// third_party/blink/public/mojom/blob/blob.mojom-shared.cc is auto generated by mojom_bindings_generator.py, do not edit

// Copyright 2016 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "third_party/blink/public/mojom/blob/blob.mojom-shared.h"

// Used to support stream output operator for enums.
// TODO(dcheng): Consider omitting this somehow if not needed.
#include <ostream>
#include <utility>

#include "base/strings/stringprintf.h"
#include "mojo/public/cpp/bindings/lib/validate_params.h"
#include "mojo/public/cpp/bindings/lib/validation_errors.h"
#include "mojo/public/cpp/bindings/lib/validation_util.h"
#include "third_party/perfetto/include/perfetto/tracing/traced_value.h"

#include "third_party/blink/public/mojom/blob/blob.mojom-params-data.h"
namespace blink {
namespace mojom {

namespace internal {


// static
bool BlobReaderClient_OnCalculatedSize_Params_Data::Validate(
    const void* data,
    mojo::internal::ValidationContext* validation_context) {
  if (!data)
    return true;
  if (!ValidateUnversionedStructHeaderAndSizeAndClaimMemory(
          data, 24, validation_context)) {
    return false;
  }

  // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
  // the message comes from an older version.
  [[maybe_unused]] const BlobReaderClient_OnCalculatedSize_Params_Data* object =
      static_cast<const BlobReaderClient_OnCalculatedSize_Params_Data*>(data);

  return true;
}

BlobReaderClient_OnCalculatedSize_Params_Data::BlobReaderClient_OnCalculatedSize_Params_Data()
    : header_({sizeof(*this), 0}) {}


// static
bool BlobReaderClient_OnComplete_Params_Data::Validate(
    const void* data,
    mojo::internal::ValidationContext* validation_context) {
  if (!data)
    return true;
  if (!ValidateUnversionedStructHeaderAndSizeAndClaimMemory(
          data, 24, validation_context)) {
    return false;
  }

  // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
  // the message comes from an older version.
  [[maybe_unused]] const BlobReaderClient_OnComplete_Params_Data* object =
      static_cast<const BlobReaderClient_OnComplete_Params_Data*>(data);

  return true;
}

BlobReaderClient_OnComplete_Params_Data::BlobReaderClient_OnComplete_Params_Data()
    : header_({sizeof(*this), 0}) {}


// static
bool Blob_Clone_Params_Data::Validate(
    const void* data,
    mojo::internal::ValidationContext* validation_context) {
  if (!data)
    return true;
  if (!ValidateUnversionedStructHeaderAndSizeAndClaimMemory(
          data, 16, validation_context)) {
    return false;
  }

  // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
  // the message comes from an older version.
  [[maybe_unused]] const Blob_Clone_Params_Data* object =
      static_cast<const Blob_Clone_Params_Data*>(data);

  if (!mojo::internal::ValidateHandleOrInterfaceNonNullable(
          object->blob, 1, validation_context)) {
    return false;
  }
  if (!mojo::internal::ValidateHandleOrInterface(object->blob,
                                                 validation_context)) {
    return false;
  }

  return true;
}

Blob_Clone_Params_Data::Blob_Clone_Params_Data()
    : header_({sizeof(*this), 0}) {}


// static
bool Blob_AsDataPipeGetter_Params_Data::Validate(
    const void* data,
    mojo::internal::ValidationContext* validation_context) {
  if (!data)
    return true;
  if (!ValidateUnversionedStructHeaderAndSizeAndClaimMemory(
          data, 16, validation_context)) {
    return false;
  }

  // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
  // the message comes from an older version.
  [[maybe_unused]] const Blob_AsDataPipeGetter_Params_Data* object =
      static_cast<const Blob_AsDataPipeGetter_Params_Data*>(data);

  if (!mojo::internal::ValidateHandleOrInterfaceNonNullable(
          object->data_pipe_getter, 1, validation_context)) {
    return false;
  }
  if (!mojo::internal::ValidateHandleOrInterface(object->data_pipe_getter,
                                                 validation_context)) {
    return false;
  }

  return true;
}

Blob_AsDataPipeGetter_Params_Data::Blob_AsDataPipeGetter_Params_Data()
    : header_({sizeof(*this), 0}) {}


// static
bool Blob_ReadAll_Params_Data::Validate(
    const void* data,
    mojo::internal::ValidationContext* validation_context) {
  if (!data)
    return true;
  if (!ValidateUnversionedStructHeaderAndSizeAndClaimMemory(
          data, 24, validation_context)) {
    return false;
  }

  // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
  // the message comes from an older version.
  [[maybe_unused]] const Blob_ReadAll_Params_Data* object =
      static_cast<const Blob_ReadAll_Params_Data*>(data);

  if (!mojo::internal::ValidateHandleOrInterfaceNonNullable(
          object->pipe, 1, validation_context)) {
    return false;
  }
  if (!mojo::internal::ValidateHandleOrInterface(object->pipe,
                                                 validation_context)) {
    return false;
  }

  if (!mojo::internal::ValidateHandleOrInterface(object->client,
                                                 validation_context)) {
    return false;
  }

  return true;
}

Blob_ReadAll_Params_Data::Blob_ReadAll_Params_Data()
    : header_({sizeof(*this), 0}) {}


// static
bool Blob_ReadRange_Params_Data::Validate(
    const void* data,
    mojo::internal::ValidationContext* validation_context) {
  if (!data)
    return true;
  if (!ValidateUnversionedStructHeaderAndSizeAndClaimMemory(
          data, 40, validation_context)) {
    return false;
  }

  // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
  // the message comes from an older version.
  [[maybe_unused]] const Blob_ReadRange_Params_Data* object =
      static_cast<const Blob_ReadRange_Params_Data*>(data);

  if (!mojo::internal::ValidateHandleOrInterfaceNonNullable(
          object->pipe, 3, validation_context)) {
    return false;
  }
  if (!mojo::internal::ValidateHandleOrInterface(object->pipe,
                                                 validation_context)) {
    return false;
  }

  if (!mojo::internal::ValidateHandleOrInterface(object->client,
                                                 validation_context)) {
    return false;
  }

  return true;
}

Blob_ReadRange_Params_Data::Blob_ReadRange_Params_Data()
    : header_({sizeof(*this), 0}) {}


// static
bool Blob_Load_Params_Data::Validate(
    const void* data,
    mojo::internal::ValidationContext* validation_context) {
  if (!data)
    return true;
  if (!ValidateUnversionedStructHeaderAndSizeAndClaimMemory(
          data, 40, validation_context)) {
    return false;
  }

  // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
  // the message comes from an older version.
  [[maybe_unused]] const Blob_Load_Params_Data* object =
      static_cast<const Blob_Load_Params_Data*>(data);

  if (!mojo::internal::ValidateHandleOrInterfaceNonNullable(
          object->loader, 1, validation_context)) {
    return false;
  }
  if (!mojo::internal::ValidateHandleOrInterface(object->loader,
                                                 validation_context)) {
    return false;
  }

  if (!mojo::internal::ValidatePointerNonNullable(
          object->request_method, 2, validation_context)) {
    return false;
  }
  constexpr const mojo::internal::ContainerValidateParams& request_method_validate_params =
      mojo::internal::GetArrayValidator<0, false, nullptr>();
  if (!mojo::internal::ValidateContainer(object->request_method, validation_context,
                                         &request_method_validate_params)) {
    return false;
  }

  if (!mojo::internal::ValidatePointerNonNullable(
          object->headers, 3, validation_context)) {
    return false;
  }
  if (!mojo::internal::ValidateStruct(object->headers, validation_context))
    return false;

  if (!mojo::internal::ValidateHandleOrInterfaceNonNullable(
          object->client, 4, validation_context)) {
    return false;
  }
  if (!mojo::internal::ValidateHandleOrInterface(object->client,
                                                 validation_context)) {
    return false;
  }

  return true;
}

Blob_Load_Params_Data::Blob_Load_Params_Data()
    : header_({sizeof(*this), 0}) {}


// static
bool Blob_ReadSideData_Params_Data::Validate(
    const void* data,
    mojo::internal::ValidationContext* validation_context) {
  if (!data)
    return true;
  if (!ValidateUnversionedStructHeaderAndSizeAndClaimMemory(
          data, 8, validation_context)) {
    return false;
  }

  // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
  // the message comes from an older version.
  [[maybe_unused]] const Blob_ReadSideData_Params_Data* object =
      static_cast<const Blob_ReadSideData_Params_Data*>(data);

  return true;
}

Blob_ReadSideData_Params_Data::Blob_ReadSideData_Params_Data()
    : header_({sizeof(*this), 0}) {}


// static
bool Blob_ReadSideData_ResponseParams_Data::Validate(
    const void* data,
    mojo::internal::ValidationContext* validation_context) {
  if (!data)
    return true;
  if (!ValidateUnversionedStructHeaderAndSizeAndClaimMemory(
          data, 24, validation_context)) {
    return false;
  }

  // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
  // the message comes from an older version.
  [[maybe_unused]] const Blob_ReadSideData_ResponseParams_Data* object =
      static_cast<const Blob_ReadSideData_ResponseParams_Data*>(data);

  if (!mojo::internal::ValidateInlinedUnion(object->data, validation_context))
    return false;

  return true;
}

Blob_ReadSideData_ResponseParams_Data::Blob_ReadSideData_ResponseParams_Data()
    : header_({sizeof(*this), 0}) {}


// static
bool Blob_CaptureSnapshot_Params_Data::Validate(
    const void* data,
    mojo::internal::ValidationContext* validation_context) {
  if (!data)
    return true;
  if (!ValidateUnversionedStructHeaderAndSizeAndClaimMemory(
          data, 8, validation_context)) {
    return false;
  }

  // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
  // the message comes from an older version.
  [[maybe_unused]] const Blob_CaptureSnapshot_Params_Data* object =
      static_cast<const Blob_CaptureSnapshot_Params_Data*>(data);

  return true;
}

Blob_CaptureSnapshot_Params_Data::Blob_CaptureSnapshot_Params_Data()
    : header_({sizeof(*this), 0}) {}


// static
bool Blob_CaptureSnapshot_ResponseParams_Data::Validate(
    const void* data,
    mojo::internal::ValidationContext* validation_context) {
  if (!data)
    return true;
  if (!ValidateUnversionedStructHeaderAndSizeAndClaimMemory(
          data, 24, validation_context)) {
    return false;
  }

  // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
  // the message comes from an older version.
  [[maybe_unused]] const Blob_CaptureSnapshot_ResponseParams_Data* object =
      static_cast<const Blob_CaptureSnapshot_ResponseParams_Data*>(data);

  if (!mojo::internal::ValidateStruct(object->modification_time, validation_context))
    return false;

  return true;
}

Blob_CaptureSnapshot_ResponseParams_Data::Blob_CaptureSnapshot_ResponseParams_Data()
    : header_({sizeof(*this), 0}) {}


// static
bool Blob_GetInternalUUID_Params_Data::Validate(
    const void* data,
    mojo::internal::ValidationContext* validation_context) {
  if (!data)
    return true;
  if (!ValidateUnversionedStructHeaderAndSizeAndClaimMemory(
          data, 8, validation_context)) {
    return false;
  }

  // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
  // the message comes from an older version.
  [[maybe_unused]] const Blob_GetInternalUUID_Params_Data* object =
      static_cast<const Blob_GetInternalUUID_Params_Data*>(data);

  return true;
}

Blob_GetInternalUUID_Params_Data::Blob_GetInternalUUID_Params_Data()
    : header_({sizeof(*this), 0}) {}


// static
bool Blob_GetInternalUUID_ResponseParams_Data::Validate(
    const void* data,
    mojo::internal::ValidationContext* validation_context) {
  if (!data)
    return true;
  if (!ValidateUnversionedStructHeaderAndSizeAndClaimMemory(
          data, 16, validation_context)) {
    return false;
  }

  // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
  // the message comes from an older version.
  [[maybe_unused]] const Blob_GetInternalUUID_ResponseParams_Data* object =
      static_cast<const Blob_GetInternalUUID_ResponseParams_Data*>(data);

  if (!mojo::internal::ValidatePointerNonNullable(
          object->uuid, 1, validation_context)) {
    return false;
  }
  constexpr const mojo::internal::ContainerValidateParams& uuid_validate_params =
      mojo::internal::GetArrayValidator<0, false, nullptr>();
  if (!mojo::internal::ValidateContainer(object->uuid, validation_context,
                                         &uuid_validate_params)) {
    return false;
  }

  return true;
}

Blob_GetInternalUUID_ResponseParams_Data::Blob_GetInternalUUID_ResponseParams_Data()
    : header_({sizeof(*this), 0}) {}

}  // namespace internal
}  // namespace mojom
}  // namespace blink