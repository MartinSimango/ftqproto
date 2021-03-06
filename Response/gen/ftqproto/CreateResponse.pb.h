// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: ftqproto/CreateResponse.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_ftqproto_2fCreateResponse_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_ftqproto_2fCreateResponse_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3017000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3017002 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
#include "ftqproto/ResponseFile.pb.h"
#include "ftqproto/ResponseStatus.pb.h"
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_ftqproto_2fCreateResponse_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_ftqproto_2fCreateResponse_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxiliaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[1]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_ftqproto_2fCreateResponse_2eproto;
namespace response {
class CreateResponse;
struct CreateResponseDefaultTypeInternal;
extern CreateResponseDefaultTypeInternal _CreateResponse_default_instance_;
}  // namespace response
PROTOBUF_NAMESPACE_OPEN
template<> ::response::CreateResponse* Arena::CreateMaybeMessage<::response::CreateResponse>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace response {

// ===================================================================

class CreateResponse final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:response.CreateResponse) */ {
 public:
  inline CreateResponse() : CreateResponse(nullptr) {}
  ~CreateResponse() override;
  explicit constexpr CreateResponse(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  CreateResponse(const CreateResponse& from);
  CreateResponse(CreateResponse&& from) noexcept
    : CreateResponse() {
    *this = ::std::move(from);
  }

  inline CreateResponse& operator=(const CreateResponse& from) {
    CopyFrom(from);
    return *this;
  }
  inline CreateResponse& operator=(CreateResponse&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const CreateResponse& default_instance() {
    return *internal_default_instance();
  }
  static inline const CreateResponse* internal_default_instance() {
    return reinterpret_cast<const CreateResponse*>(
               &_CreateResponse_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(CreateResponse& a, CreateResponse& b) {
    a.Swap(&b);
  }
  inline void Swap(CreateResponse* other) {
    if (other == this) return;
    if (GetOwningArena() == other->GetOwningArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(CreateResponse* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline CreateResponse* New() const final {
    return new CreateResponse();
  }

  CreateResponse* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<CreateResponse>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const CreateResponse& from);
  void MergeFrom(const CreateResponse& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(CreateResponse* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "response.CreateResponse";
  }
  protected:
  explicit CreateResponse(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kFilesFieldNumber = 1,
    kStatusFieldNumber = 2,
  };
  // repeated .response.ResponseFile files = 1;
  int files_size() const;
  private:
  int _internal_files_size() const;
  public:
  void clear_files();
  ::response::ResponseFile* mutable_files(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::response::ResponseFile >*
      mutable_files();
  private:
  const ::response::ResponseFile& _internal_files(int index) const;
  ::response::ResponseFile* _internal_add_files();
  public:
  const ::response::ResponseFile& files(int index) const;
  ::response::ResponseFile* add_files();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::response::ResponseFile >&
      files() const;

  // .response.ResponseStatus status = 2;
  bool has_status() const;
  private:
  bool _internal_has_status() const;
  public:
  void clear_status();
  const ::response::ResponseStatus& status() const;
  PROTOBUF_FUTURE_MUST_USE_RESULT ::response::ResponseStatus* release_status();
  ::response::ResponseStatus* mutable_status();
  void set_allocated_status(::response::ResponseStatus* status);
  private:
  const ::response::ResponseStatus& _internal_status() const;
  ::response::ResponseStatus* _internal_mutable_status();
  public:
  void unsafe_arena_set_allocated_status(
      ::response::ResponseStatus* status);
  ::response::ResponseStatus* unsafe_arena_release_status();

  // @@protoc_insertion_point(class_scope:response.CreateResponse)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::response::ResponseFile > files_;
  ::response::ResponseStatus* status_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_ftqproto_2fCreateResponse_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// CreateResponse

// repeated .response.ResponseFile files = 1;
inline int CreateResponse::_internal_files_size() const {
  return files_.size();
}
inline int CreateResponse::files_size() const {
  return _internal_files_size();
}
inline ::response::ResponseFile* CreateResponse::mutable_files(int index) {
  // @@protoc_insertion_point(field_mutable:response.CreateResponse.files)
  return files_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::response::ResponseFile >*
CreateResponse::mutable_files() {
  // @@protoc_insertion_point(field_mutable_list:response.CreateResponse.files)
  return &files_;
}
inline const ::response::ResponseFile& CreateResponse::_internal_files(int index) const {
  return files_.Get(index);
}
inline const ::response::ResponseFile& CreateResponse::files(int index) const {
  // @@protoc_insertion_point(field_get:response.CreateResponse.files)
  return _internal_files(index);
}
inline ::response::ResponseFile* CreateResponse::_internal_add_files() {
  return files_.Add();
}
inline ::response::ResponseFile* CreateResponse::add_files() {
  // @@protoc_insertion_point(field_add:response.CreateResponse.files)
  return _internal_add_files();
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::response::ResponseFile >&
CreateResponse::files() const {
  // @@protoc_insertion_point(field_list:response.CreateResponse.files)
  return files_;
}

// .response.ResponseStatus status = 2;
inline bool CreateResponse::_internal_has_status() const {
  return this != internal_default_instance() && status_ != nullptr;
}
inline bool CreateResponse::has_status() const {
  return _internal_has_status();
}
inline const ::response::ResponseStatus& CreateResponse::_internal_status() const {
  const ::response::ResponseStatus* p = status_;
  return p != nullptr ? *p : reinterpret_cast<const ::response::ResponseStatus&>(
      ::response::_ResponseStatus_default_instance_);
}
inline const ::response::ResponseStatus& CreateResponse::status() const {
  // @@protoc_insertion_point(field_get:response.CreateResponse.status)
  return _internal_status();
}
inline void CreateResponse::unsafe_arena_set_allocated_status(
    ::response::ResponseStatus* status) {
  if (GetArenaForAllocation() == nullptr) {
    delete reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(status_);
  }
  status_ = status;
  if (status) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:response.CreateResponse.status)
}
inline ::response::ResponseStatus* CreateResponse::release_status() {
  
  ::response::ResponseStatus* temp = status_;
  status_ = nullptr;
  if (GetArenaForAllocation() != nullptr) {
    temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  }
  return temp;
}
inline ::response::ResponseStatus* CreateResponse::unsafe_arena_release_status() {
  // @@protoc_insertion_point(field_release:response.CreateResponse.status)
  
  ::response::ResponseStatus* temp = status_;
  status_ = nullptr;
  return temp;
}
inline ::response::ResponseStatus* CreateResponse::_internal_mutable_status() {
  
  if (status_ == nullptr) {
    auto* p = CreateMaybeMessage<::response::ResponseStatus>(GetArenaForAllocation());
    status_ = p;
  }
  return status_;
}
inline ::response::ResponseStatus* CreateResponse::mutable_status() {
  // @@protoc_insertion_point(field_mutable:response.CreateResponse.status)
  return _internal_mutable_status();
}
inline void CreateResponse::set_allocated_status(::response::ResponseStatus* status) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaForAllocation();
  if (message_arena == nullptr) {
    delete reinterpret_cast< ::PROTOBUF_NAMESPACE_ID::MessageLite*>(status_);
  }
  if (status) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
        ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper<
            ::PROTOBUF_NAMESPACE_ID::MessageLite>::GetOwningArena(
                reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(status));
    if (message_arena != submessage_arena) {
      status = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, status, submessage_arena);
    }
    
  } else {
    
  }
  status_ = status;
  // @@protoc_insertion_point(field_set_allocated:response.CreateResponse.status)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace response

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_ftqproto_2fCreateResponse_2eproto
