#!/usr/bin/env python3

import os
import sys


def memfrob(data: bytes) -> bytes:
    tmp = 0xFF
    result = []

    for i, byte in enumerate(data):
        byte = (byte ^ tmp) & 0xFF

        byte = (byte ^ (i)) & 0xFF
        byte = (byte + (i*i)) & 0xFF
        byte = (byte ^ (i*i*i)) & 0xFF
        byte = (byte + (i*i*i*i)) & 0xFF

        result.append(byte)

        tmp = (tmp + byte) & 0xFF

    return bytes(result)


def unmemfrob(data: bytes) -> bytes:
    tmp = 0xFF
    tmp = (tmp + sum(data)) & 0xFF

    unprotected = []

    for i, byte in reversed(list(enumerate(data))):
        tmp = (tmp - byte) & 0xFF

        byte = (byte - (i*i*i*i)) & 0xFF
        byte = (byte ^ (i*i*i)) & 0xFF
        byte = (byte - (i*i)) & 0xFF
        byte = (byte ^ (i)) & 0xFF

        byte = (byte ^ tmp) & 0xFF

        unprotected.append(byte)

    return bytes(unprotected[::-1])


def encrypt(flag: bytes, values: bytes) -> bytes:
    result = []

    for i, byte in enumerate(flag):
        byte = (byte + i) & 0xFF
        byte = (byte ^ values[i]) & 0xFF

        result.append(byte)

    return bytes(result)


def decrypt(ciphertext: bytes, values: bytes) -> bytes:
    array = []

    for i, byte in enumerate(ciphertext):
        byte = (byte ^ values[i]) & 0xFF
        byte = (byte - i) & 0xFF

        array.append(byte)

    return bytes(array)


def generate_check_code(flag: bytes, values: bytes) -> str:
    template = '''
values = [{values}]
expected = [{expected}]

flag = flag[:len(expected)]

valid = True

for i, byte in enumerate(flag):
    byte = (byte + i) & 0xFF
    byte = (byte ^ values[i]) & 0xFF

    if byte != expected[i]:
        valid = False
'''

    expected = encrypt(flag, values)

    values_array = ', '.join(
        str(value) for value in values
    )
    expected_array = ', '.join(
        '0x' + hex(byte)[2:].zfill(2) for byte in expected
    )

    check_code = template.format(
        values = values_array,
        expected = expected_array,
    )

    return check_code


def generate_check() -> None:
    # flag = os.getenv('FLAG', '').encode()

    # if len(flag) == 0:
    #     raise Exception('please set FLAG env')

    flag = b'try harder..............................'
    values = os.urandom(len(flag))

    assert decrypt(encrypt(flag, values), values) == flag

    check_code = generate_check_code(flag, values)

    with open('check.py', 'w') as file:
        file.write(check_code)

    return


def generate_array_code(name: str, data: bytes, length: int) -> str:
    template = '''/* DO NOT EDIT: autogenerated */
__attribute__((section(".data")))
unsigned char {name}[] = {{
    {array}
}};
const unsigned long long {name}Length = {length};
'''

    array = ', '.join(
        '0x' + hex(byte)[2:].zfill(2) for byte in data
    )

    code = template.format(
        name = name,
        array = array,
        length = length,
    )

    return code


def generate_program() -> None:
    with open('check.pyc', 'rb') as file:
        bytecode = file.read()

    # skip 16 bytes to pass into marshal.loads (idk why)
    bytecode = bytecode[16:]

    bytecode = unmemfrob(bytecode)

    program_code = generate_array_code('Program', bytecode, len(bytecode))

    with open('program.c', 'w') as file:
        file.write(program_code)

    return


def generate_runtime() -> None:
    with open('runtime.zip', 'rb') as file:
        runtime = file.read()

    runtime = unmemfrob(runtime)

    runtime_code = generate_array_code('Runtime', runtime, len(runtime))

    with open('runtime.c', 'w') as file:
        file.write(runtime_code)

    return


def generate_atexit() -> None:
    with open('hijacked.pyc', 'rb') as file:
        bytecode = file.read()

    # skip 16 bytes to pass into marshal.loads (idk why)
    bytecode = bytecode[16:]

    padding = bytes((x & 0xFF) for x in range(0x1000))
    bytecode_ex = bytecode + padding

    bytecode_encrypted = [x ^ 0x55 for x in bytecode_ex]

    hijacked_code = generate_array_code(
        'Hijacked', bytecode_encrypted, len(bytecode),
    )

    with open('atexit.template.c', 'r') as file:
        atexit_template = file.read()

    includes = '''/* DO NOT EDIT: autogenerated */
#include <signal.h>
'''

    functions = '''/* DO NOT EDIT: autogenerated */
__attribute__((visibility("hidden")))
PyObject *my_marshal_loads(PyObject *module, PyObject *arg) {
    volatile void *this = (void *)(&my_marshal_loads);

    /* page: r-x libchecker.so */
    volatile void *library_base = this - 0x11b851;

    /* marshal_loads@got.plt */
    volatile void *plt_entry = library_base + 0xa21108;

    /* saved marshal_loads pointer */
    volatile void *original_ptr = plt_entry + 0x10000;

    /* load original marshal_loads */
    PyObject *(*original)(PyObject *module, PyObject *arg) = (*(unsigned long long *)original_ptr) ^ 0xa09dc576e3147c6e;

    for (size_t i = 0; i < HijackedLength; i += 1) {
        Hijacked[i] ^= 0x55;
    }

    PyObject *hijacked = PyBytes_FromStringAndSize(Hijacked, HijackedLength);

    PyObject *result = (*original)(module, hijacked);
    Py_DECREF(hijacked);

    return result;
}

__attribute__((visibility("hidden")))
void hook_marshal_loads() {
    volatile void *this = (void *)(&hook_marshal_loads);

    /* page: r-x libchecker.so */
    volatile void *library_base = this - 0x11b81f;

    /* marshal_loads@got.plt */
    volatile void *plt_entry = library_base + 0xa21108;

    /* saved marshal_loads pointer */
    volatile void *original_ptr = plt_entry + 0x10000;

    /* save original marshal_loads */
    *(unsigned long long *)original_ptr = (*(unsigned long long *)plt_entry) ^ 0xa09dc576e3147c6e;

    /* put hook address in marshal_loads@got.plt */
    *(void **)plt_entry = (void *)(&my_marshal_loads);

    return;
}
'''

    functions = hijacked_code + functions

    atexit_code = atexit_template
    atexit_code = atexit_code.replace('/* INCLUDES */', includes)
    atexit_code = atexit_code.replace('/* FUNCTIONS */', functions)

    with open('atexit.c', 'w') as file:
        file.write(atexit_code)

    return


def main() -> None:
    if len(sys.argv) < 2:
        print(f'usage: `python3 {sys.argv[0]} CHECK|PROGRAM|RUNTIME|ATEXIT`')
        return
    
    arg = sys.argv[1].lower()

    if arg == 'check':
        generate_check()
    elif arg == 'program':
        generate_program()
    elif arg == 'runtime':
        generate_runtime()
    elif arg == 'atexit':
        generate_atexit()
    else:
        print(f'invalid arg: {arg}')

    return


if __name__ == '__main__':
    main()