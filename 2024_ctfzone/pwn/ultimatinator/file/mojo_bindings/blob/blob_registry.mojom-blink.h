// third_party/blink/public/mojom/blob/blob_registry.mojom-blink.h is auto generated by mojom_bindings_generator.py, do not edit

// Copyright 2013 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_PUBLIC_MOJOM_BLOB_BLOB_REGISTRY_MOJOM_BLINK_H_
#define THIRD_PARTY_BLINK_PUBLIC_MOJOM_BLOB_BLOB_REGISTRY_MOJOM_BLINK_H_

#include <stdint.h>

#include <limits>
#include <optional>
#include <type_traits>
#include <utility>

#include "base/types/cxx23_to_underlying.h"
#include "mojo/public/cpp/bindings/clone_traits.h"
#include "mojo/public/cpp/bindings/equals_traits.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/struct_ptr.h"
#include "mojo/public/cpp/bindings/struct_traits.h"
#include "mojo/public/cpp/bindings/union_traits.h"

#include "third_party/perfetto/include/perfetto/tracing/traced_value_forward.h"

#include "third_party/blink/public/mojom/blob/blob_registry.mojom-features.h"  // IWYU pragma: export
#include "third_party/blink/public/mojom/blob/blob_registry.mojom-shared.h"  // IWYU pragma: export
#include "third_party/blink/public/mojom/blob/blob_registry.mojom-blink-forward.h"  // IWYU pragma: export
#include "third_party/blink/public/mojom/blob/blob.mojom-blink-forward.h"
#include "third_party/blink/public/mojom/blob/blob_url_store.mojom-blink-forward.h"
#include "third_party/blink/public/mojom/blob/data_element.mojom-blink-forward.h"
#include "third_party/blink/public/mojom/blob/serialized_blob.mojom-blink.h"
#include "url/mojom/origin.mojom-blink-forward.h"

#include "mojo/public/cpp/bindings/lib/wtf_clone_equals_util.h"
#include "mojo/public/cpp/bindings/lib/wtf_hash_util.h"
#include "third_party/blink/renderer/platform/wtf/hash_functions.h"
#include "third_party/blink/renderer/platform/wtf/text/wtf_string.h"

#include "mojo/public/cpp/bindings/lib/control_message_handler.h"
#include "mojo/public/cpp/bindings/lib/message_size_estimator.h"
#include "mojo/public/cpp/bindings/raw_ptr_impl_ref_traits.h"


#include "third_party/blink/renderer/platform/platform_export.h"




namespace blink::mojom::blink {

class ProgressClientProxy;

template <typename ImplRefTraits>
class ProgressClientStub;

class ProgressClientRequestValidator;


class PLATFORM_EXPORT ProgressClient
    : public ProgressClientInterfaceBase {
 public:
  using IPCStableHashFunction = uint32_t(*)();

  static const char Name_[];
  static IPCStableHashFunction MessageToMethodInfo_(mojo::Message& message);
  static const char* MessageToMethodName_(mojo::Message& message);
  static constexpr uint32_t Version_ = 0;
  static constexpr bool PassesAssociatedKinds_ = false;
  static constexpr bool HasUninterruptableMethods_ = false;

  using Base_ = ProgressClientInterfaceBase;
  using Proxy_ = ProgressClientProxy;

  template <typename ImplRefTraits>
  using Stub_ = ProgressClientStub<ImplRefTraits>;

  using RequestValidator_ = ProgressClientRequestValidator;
  using ResponseValidator_ = mojo::PassThroughFilter;
  enum MethodMinVersions : uint32_t {
    kOnProgressMinVersion = 0,
  };

// crbug.com/1340245 - this causes binary size bloat on Fuchsia, and we're OK
// with not having this data in traces there.
#if !BUILDFLAG(IS_FUCHSIA)
  struct OnProgress_Sym {
    NOINLINE static uint32_t IPCStableHash();
  };
#endif // !BUILDFLAG(IS_FUCHSIA)
  virtual ~ProgressClient() = default;

  
  virtual void OnProgress(uint64_t delta) = 0;
};

class BlobRegistryProxy;

template <typename ImplRefTraits>
class BlobRegistryStub;

class BlobRegistryRequestValidator;
class BlobRegistryResponseValidator;


class PLATFORM_EXPORT BlobRegistry
    : public BlobRegistryInterfaceBase {
 public:
  using IPCStableHashFunction = uint32_t(*)();

  static const char Name_[];
  static IPCStableHashFunction MessageToMethodInfo_(mojo::Message& message);
  static const char* MessageToMethodName_(mojo::Message& message);
  static constexpr uint32_t Version_ = 0;
  static constexpr bool PassesAssociatedKinds_ = true;
  static inline constexpr uint32_t kSyncMethodOrdinals[] = {
    0, 
    2
  };
  static constexpr bool HasUninterruptableMethods_ = false;

  using Base_ = BlobRegistryInterfaceBase;
  using Proxy_ = BlobRegistryProxy;

  template <typename ImplRefTraits>
  using Stub_ = BlobRegistryStub<ImplRefTraits>;

  using RequestValidator_ = BlobRegistryRequestValidator;
  using ResponseValidator_ = BlobRegistryResponseValidator;
  enum MethodMinVersions : uint32_t {
    kRegisterMinVersion = 0,
    kRegisterFromStreamMinVersion = 0,
    kGetBlobFromUUIDMinVersion = 0,
  };

// crbug.com/1340245 - this causes binary size bloat on Fuchsia, and we're OK
// with not having this data in traces there.
#if !BUILDFLAG(IS_FUCHSIA)
  struct Register_Sym {
    NOINLINE static uint32_t IPCStableHash();
  };
  struct RegisterFromStream_Sym {
    NOINLINE static uint32_t IPCStableHash();
  };
  struct GetBlobFromUUID_Sym {
    NOINLINE static uint32_t IPCStableHash();
  };
#endif // !BUILDFLAG(IS_FUCHSIA)
  virtual ~BlobRegistry() = default;

  // Sync method. This signature is used by the client side; the service side
  // should implement the signature with callback below.
  
  virtual bool Register(::mojo::PendingReceiver<::blink::mojom::blink::Blob> blob, const WTF::String& uuid, const WTF::String& content_type, const WTF::String& content_disposition, WTF::Vector<::blink::mojom::blink::DataElementPtr> elements);

  using RegisterCallback = base::OnceCallback<void()>;
  
  virtual void Register(::mojo::PendingReceiver<::blink::mojom::blink::Blob> blob, const WTF::String& uuid, const WTF::String& content_type, const WTF::String& content_disposition, WTF::Vector<::blink::mojom::blink::DataElementPtr> elements, RegisterCallback callback) = 0;


  using RegisterFromStreamCallback = base::OnceCallback<void(const ::scoped_refptr<::blink::BlobDataHandle>&)>;
  
  virtual void RegisterFromStream(const WTF::String& content_type, const WTF::String& content_disposition, uint64_t length_hint, ::mojo::ScopedDataPipeConsumerHandle data, ::mojo::PendingAssociatedRemote<ProgressClient> progress_client, RegisterFromStreamCallback callback) = 0;

  // Sync method. This signature is used by the client side; the service side
  // should implement the signature with callback below.
  
  virtual bool GetBlobFromUUID(::mojo::PendingReceiver<::blink::mojom::blink::Blob> blob, const WTF::String& uuid);

  using GetBlobFromUUIDCallback = base::OnceCallback<void()>;
  
  virtual void GetBlobFromUUID(::mojo::PendingReceiver<::blink::mojom::blink::Blob> blob, const WTF::String& uuid, GetBlobFromUUIDCallback callback) = 0;
};



class PLATFORM_EXPORT ProgressClientProxy
    : public ProgressClient {
 public:
  using InterfaceType = ProgressClient;

  explicit ProgressClientProxy(mojo::MessageReceiverWithResponder* receiver);
  
  void OnProgress(uint64_t delta) final;

 private:
  mojo::MessageReceiverWithResponder* receiver_;
};



class PLATFORM_EXPORT BlobRegistryProxy
    : public BlobRegistry {
 public:
  using InterfaceType = BlobRegistry;

  explicit BlobRegistryProxy(mojo::MessageReceiverWithResponder* receiver);
  
  bool Register(::mojo::PendingReceiver<::blink::mojom::blink::Blob> blob, const WTF::String& uuid, const WTF::String& content_type, const WTF::String& content_disposition, WTF::Vector<::blink::mojom::blink::DataElementPtr> elements) final;
  
  void Register(::mojo::PendingReceiver<::blink::mojom::blink::Blob> blob, const WTF::String& uuid, const WTF::String& content_type, const WTF::String& content_disposition, WTF::Vector<::blink::mojom::blink::DataElementPtr> elements, RegisterCallback callback) final;
  
  void RegisterFromStream(const WTF::String& content_type, const WTF::String& content_disposition, uint64_t length_hint, ::mojo::ScopedDataPipeConsumerHandle data, ::mojo::PendingAssociatedRemote<ProgressClient> progress_client, RegisterFromStreamCallback callback) final;
  
  bool GetBlobFromUUID(::mojo::PendingReceiver<::blink::mojom::blink::Blob> blob, const WTF::String& uuid) final;
  
  void GetBlobFromUUID(::mojo::PendingReceiver<::blink::mojom::blink::Blob> blob, const WTF::String& uuid, GetBlobFromUUIDCallback callback) final;

 private:
  mojo::MessageReceiverWithResponder* receiver_;
};
class PLATFORM_EXPORT ProgressClientStubDispatch {
 public:
  static bool Accept(ProgressClient* impl, mojo::Message* message);
  static bool AcceptWithResponder(
      ProgressClient* impl,
      mojo::Message* message,
      std::unique_ptr<mojo::MessageReceiverWithStatus> responder);
};

template <typename ImplRefTraits =
              mojo::RawPtrImplRefTraits<ProgressClient>>
class ProgressClientStub
    : public mojo::MessageReceiverWithResponderStatus {
 public:
  using ImplPointerType = typename ImplRefTraits::PointerType;

  ProgressClientStub() = default;
  ~ProgressClientStub() override = default;

  void set_sink(ImplPointerType sink) { sink_ = std::move(sink); }
  ImplPointerType& sink() { return sink_; }

  bool Accept(mojo::Message* message) override {
    if (ImplRefTraits::IsNull(sink_))
      return false;
    return ProgressClientStubDispatch::Accept(
        ImplRefTraits::GetRawPointer(&sink_), message);
  }

  bool AcceptWithResponder(
      mojo::Message* message,
      std::unique_ptr<mojo::MessageReceiverWithStatus> responder) override {
    if (ImplRefTraits::IsNull(sink_))
      return false;
    return ProgressClientStubDispatch::AcceptWithResponder(
        ImplRefTraits::GetRawPointer(&sink_), message, std::move(responder));
  }

 private:
  ImplPointerType sink_;
};
class PLATFORM_EXPORT BlobRegistryStubDispatch {
 public:
  static bool Accept(BlobRegistry* impl, mojo::Message* message);
  static bool AcceptWithResponder(
      BlobRegistry* impl,
      mojo::Message* message,
      std::unique_ptr<mojo::MessageReceiverWithStatus> responder);
};

template <typename ImplRefTraits =
              mojo::RawPtrImplRefTraits<BlobRegistry>>
class BlobRegistryStub
    : public mojo::MessageReceiverWithResponderStatus {
 public:
  using ImplPointerType = typename ImplRefTraits::PointerType;

  BlobRegistryStub() = default;
  ~BlobRegistryStub() override = default;

  void set_sink(ImplPointerType sink) { sink_ = std::move(sink); }
  ImplPointerType& sink() { return sink_; }

  bool Accept(mojo::Message* message) override {
    if (ImplRefTraits::IsNull(sink_))
      return false;
    return BlobRegistryStubDispatch::Accept(
        ImplRefTraits::GetRawPointer(&sink_), message);
  }

  bool AcceptWithResponder(
      mojo::Message* message,
      std::unique_ptr<mojo::MessageReceiverWithStatus> responder) override {
    if (ImplRefTraits::IsNull(sink_))
      return false;
    return BlobRegistryStubDispatch::AcceptWithResponder(
        ImplRefTraits::GetRawPointer(&sink_), message, std::move(responder));
  }

 private:
  ImplPointerType sink_;
};
class PLATFORM_EXPORT ProgressClientRequestValidator : public mojo::MessageReceiver {
 public:
  bool Accept(mojo::Message* message) override;
};
class PLATFORM_EXPORT BlobRegistryRequestValidator : public mojo::MessageReceiver {
 public:
  bool Accept(mojo::Message* message) override;
};
class PLATFORM_EXPORT BlobRegistryResponseValidator : public mojo::MessageReceiver {
 public:
  bool Accept(mojo::Message* message) override;
};





}  // blink::mojom::blink

namespace mojo {

}  // namespace mojo

#endif  // THIRD_PARTY_BLINK_PUBLIC_MOJOM_BLOB_BLOB_REGISTRY_MOJOM_BLINK_H_