FROM python:3.11

WORKDIR /home/ctf

COPY main.py .
COPY flag .

RUN apt-get update
RUN apt-get install -y socat

RUN chown -R root:root /home/ctf

EXPOSE 1337

CMD socat TCP-LISTEN:1337,reuseaddr,fork EXEC:"python3 main.py"
