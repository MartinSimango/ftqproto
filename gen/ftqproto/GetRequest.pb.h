// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: ftqproto/GetRequest.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_ftqproto_2fGetRequest_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_ftqproto_2fGetRequest_2eproto

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
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_ftqproto_2fGetRequest_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_ftqproto_2fGetRequest_2eproto {
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
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_ftqproto_2fGetRequest_2eproto;
namespace request {
class GetRequest;
struct GetRequestDefaultTypeInternal;
extern GetRequestDefaultTypeInternal _GetRequest_default_instance_;
}  // namespace request
PROTOBUF_NAMESPACE_OPEN
template<> ::request::GetRequest* Arena::CreateMaybeMessage<::request::GetRequest>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace request {

// ===================================================================

class GetRequest final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:request.GetRequest) */ {
 public:
  inline GetRequest() : GetRequest(nullptr) {}
  ~GetRequest() override;
  explicit constexpr GetRequest(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  GetRequest(const GetRequest& from);
  GetRequest(GetRequest&& from) noexcept
    : GetRequest() {
    *this = ::std::move(from);
  }

  inline GetRequest& operator=(const GetRequest& from) {
    CopyFrom(from);
    return *this;
  }
  inline GetRequest& operator=(GetRequest&& from) noexcept {
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
  static const GetRequest& default_instance() {
    return *internal_default_instance();
  }
  static inline const GetRequest* internal_default_instance() {
    return reinterpret_cast<const GetRequest*>(
               &_GetRequest_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(GetRequest& a, GetRequest& b) {
    a.Swap(&b);
  }
  inline void Swap(GetRequest* other) {
    if (other == this) return;
    if (GetOwningArena() == other->GetOwningArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(GetRequest* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline GetRequest* New() const final {
    return new GetRequest();
  }

  GetRequest* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<GetRequest>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const GetRequest& from);
  void MergeFrom(const GetRequest& from);
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
  void InternalSwap(GetRequest* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "request.GetRequest";
  }
  protected:
  explicit GetRequest(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kFilePathFieldNumber = 1,
  };
  // string filePath = 1;
  void clear_filepath();
  const std::string& filepath() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_filepath(ArgT0&& arg0, ArgT... args);
  std::string* mutable_filepath();
  PROTOBUF_FUTURE_MUST_USE_RESULT std::string* release_filepath();
  void set_allocated_filepath(std::string* filepath);
  private:
  const std::string& _internal_filepath() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_filepath(const std::string& value);
  std::string* _internal_mutable_filepath();
  public:

  // @@protoc_insertion_point(class_scope:request.GetRequest)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr filepath_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_ftqproto_2fGetRequest_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// GetRequest

// string filePath = 1;
inline void GetRequest::clear_filepath() {
  filepath_.ClearToEmpty();
}
inline const std::string& GetRequest::filepath() const {
  // @@protoc_insertion_point(field_get:request.GetRequest.filePath)
  return _internal_filepath();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void GetRequest::set_filepath(ArgT0&& arg0, ArgT... args) {
 
 filepath_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:request.GetRequest.filePath)
}
inline std::string* GetRequest::mutable_filepath() {
  // @@protoc_insertion_point(field_mutable:request.GetRequest.filePath)
  return _internal_mutable_filepath();
}
inline const std::string& GetRequest::_internal_filepath() const {
  return filepath_.Get();
}
inline void GetRequest::_internal_set_filepath(const std::string& value) {
  
  filepath_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* GetRequest::_internal_mutable_filepath() {
  
  return filepath_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* GetRequest::release_filepath() {
  // @@protoc_insertion_point(field_release:request.GetRequest.filePath)
  return filepath_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
}
inline void GetRequest::set_allocated_filepath(std::string* filepath) {
  if (filepath != nullptr) {
    
  } else {
    
  }
  filepath_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), filepath,
      GetArenaForAllocation());
  // @@protoc_insertion_point(field_set_allocated:request.GetRequest.filePath)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace request

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_ftqproto_2fGetRequest_2eproto