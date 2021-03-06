// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: ftqproto/ResponseStatus.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_ftqproto_2fResponseStatus_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_ftqproto_2fResponseStatus_2eproto

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
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_ftqproto_2fResponseStatus_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_ftqproto_2fResponseStatus_2eproto {
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
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_ftqproto_2fResponseStatus_2eproto;
namespace response {
class ResponseStatus;
struct ResponseStatusDefaultTypeInternal;
extern ResponseStatusDefaultTypeInternal _ResponseStatus_default_instance_;
}  // namespace response
PROTOBUF_NAMESPACE_OPEN
template<> ::response::ResponseStatus* Arena::CreateMaybeMessage<::response::ResponseStatus>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace response {

enum ResponseStatus_Status : int {
  ResponseStatus_Status_OK = 0,
  ResponseStatus_Status_FILE_NOT_FOUND = 1,
  ResponseStatus_Status_NO_WRITE_PERMISSIONS = 2,
  ResponseStatus_Status_NO_READ_PERMISSIONS = 3,
  ResponseStatus_Status_FAILED_TO_CREATE_FILE = 4,
  ResponseStatus_Status_FAILED_TO_CREATE_DIRECTORY = 5,
  ResponseStatus_Status_OPERATION_NOT_PERMITTED = 6,
  ResponseStatus_Status_ResponseStatus_Status_INT_MIN_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::PROTOBUF_NAMESPACE_ID::int32>::min(),
  ResponseStatus_Status_ResponseStatus_Status_INT_MAX_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::PROTOBUF_NAMESPACE_ID::int32>::max()
};
bool ResponseStatus_Status_IsValid(int value);
constexpr ResponseStatus_Status ResponseStatus_Status_Status_MIN = ResponseStatus_Status_OK;
constexpr ResponseStatus_Status ResponseStatus_Status_Status_MAX = ResponseStatus_Status_OPERATION_NOT_PERMITTED;
constexpr int ResponseStatus_Status_Status_ARRAYSIZE = ResponseStatus_Status_Status_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* ResponseStatus_Status_descriptor();
template<typename T>
inline const std::string& ResponseStatus_Status_Name(T enum_t_value) {
  static_assert(::std::is_same<T, ResponseStatus_Status>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function ResponseStatus_Status_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    ResponseStatus_Status_descriptor(), enum_t_value);
}
inline bool ResponseStatus_Status_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, ResponseStatus_Status* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<ResponseStatus_Status>(
    ResponseStatus_Status_descriptor(), name, value);
}
// ===================================================================

class ResponseStatus final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:response.ResponseStatus) */ {
 public:
  inline ResponseStatus() : ResponseStatus(nullptr) {}
  ~ResponseStatus() override;
  explicit constexpr ResponseStatus(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  ResponseStatus(const ResponseStatus& from);
  ResponseStatus(ResponseStatus&& from) noexcept
    : ResponseStatus() {
    *this = ::std::move(from);
  }

  inline ResponseStatus& operator=(const ResponseStatus& from) {
    CopyFrom(from);
    return *this;
  }
  inline ResponseStatus& operator=(ResponseStatus&& from) noexcept {
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
  static const ResponseStatus& default_instance() {
    return *internal_default_instance();
  }
  static inline const ResponseStatus* internal_default_instance() {
    return reinterpret_cast<const ResponseStatus*>(
               &_ResponseStatus_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(ResponseStatus& a, ResponseStatus& b) {
    a.Swap(&b);
  }
  inline void Swap(ResponseStatus* other) {
    if (other == this) return;
    if (GetOwningArena() == other->GetOwningArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(ResponseStatus* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline ResponseStatus* New() const final {
    return new ResponseStatus();
  }

  ResponseStatus* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<ResponseStatus>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const ResponseStatus& from);
  void MergeFrom(const ResponseStatus& from);
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
  void InternalSwap(ResponseStatus* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "response.ResponseStatus";
  }
  protected:
  explicit ResponseStatus(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  typedef ResponseStatus_Status Status;
  static constexpr Status OK =
    ResponseStatus_Status_OK;
  static constexpr Status FILE_NOT_FOUND =
    ResponseStatus_Status_FILE_NOT_FOUND;
  static constexpr Status NO_WRITE_PERMISSIONS =
    ResponseStatus_Status_NO_WRITE_PERMISSIONS;
  static constexpr Status NO_READ_PERMISSIONS =
    ResponseStatus_Status_NO_READ_PERMISSIONS;
  static constexpr Status FAILED_TO_CREATE_FILE =
    ResponseStatus_Status_FAILED_TO_CREATE_FILE;
  static constexpr Status FAILED_TO_CREATE_DIRECTORY =
    ResponseStatus_Status_FAILED_TO_CREATE_DIRECTORY;
  static constexpr Status OPERATION_NOT_PERMITTED =
    ResponseStatus_Status_OPERATION_NOT_PERMITTED;
  static inline bool Status_IsValid(int value) {
    return ResponseStatus_Status_IsValid(value);
  }
  static constexpr Status Status_MIN =
    ResponseStatus_Status_Status_MIN;
  static constexpr Status Status_MAX =
    ResponseStatus_Status_Status_MAX;
  static constexpr int Status_ARRAYSIZE =
    ResponseStatus_Status_Status_ARRAYSIZE;
  static inline const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor*
  Status_descriptor() {
    return ResponseStatus_Status_descriptor();
  }
  template<typename T>
  static inline const std::string& Status_Name(T enum_t_value) {
    static_assert(::std::is_same<T, Status>::value ||
      ::std::is_integral<T>::value,
      "Incorrect type passed to function Status_Name.");
    return ResponseStatus_Status_Name(enum_t_value);
  }
  static inline bool Status_Parse(::PROTOBUF_NAMESPACE_ID::ConstStringParam name,
      Status* value) {
    return ResponseStatus_Status_Parse(name, value);
  }

  // accessors -------------------------------------------------------

  enum : int {
    kBodyFieldNumber = 1,
    kStatusFieldNumber = 2,
  };
  // string body = 1;
  void clear_body();
  const std::string& body() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_body(ArgT0&& arg0, ArgT... args);
  std::string* mutable_body();
  PROTOBUF_FUTURE_MUST_USE_RESULT std::string* release_body();
  void set_allocated_body(std::string* body);
  private:
  const std::string& _internal_body() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_body(const std::string& value);
  std::string* _internal_mutable_body();
  public:

  // .response.ResponseStatus.Status status = 2;
  void clear_status();
  ::response::ResponseStatus_Status status() const;
  void set_status(::response::ResponseStatus_Status value);
  private:
  ::response::ResponseStatus_Status _internal_status() const;
  void _internal_set_status(::response::ResponseStatus_Status value);
  public:

  // @@protoc_insertion_point(class_scope:response.ResponseStatus)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr body_;
  int status_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_ftqproto_2fResponseStatus_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// ResponseStatus

// string body = 1;
inline void ResponseStatus::clear_body() {
  body_.ClearToEmpty();
}
inline const std::string& ResponseStatus::body() const {
  // @@protoc_insertion_point(field_get:response.ResponseStatus.body)
  return _internal_body();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void ResponseStatus::set_body(ArgT0&& arg0, ArgT... args) {
 
 body_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:response.ResponseStatus.body)
}
inline std::string* ResponseStatus::mutable_body() {
  // @@protoc_insertion_point(field_mutable:response.ResponseStatus.body)
  return _internal_mutable_body();
}
inline const std::string& ResponseStatus::_internal_body() const {
  return body_.Get();
}
inline void ResponseStatus::_internal_set_body(const std::string& value) {
  
  body_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* ResponseStatus::_internal_mutable_body() {
  
  return body_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* ResponseStatus::release_body() {
  // @@protoc_insertion_point(field_release:response.ResponseStatus.body)
  return body_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
}
inline void ResponseStatus::set_allocated_body(std::string* body) {
  if (body != nullptr) {
    
  } else {
    
  }
  body_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), body,
      GetArenaForAllocation());
  // @@protoc_insertion_point(field_set_allocated:response.ResponseStatus.body)
}

// .response.ResponseStatus.Status status = 2;
inline void ResponseStatus::clear_status() {
  status_ = 0;
}
inline ::response::ResponseStatus_Status ResponseStatus::_internal_status() const {
  return static_cast< ::response::ResponseStatus_Status >(status_);
}
inline ::response::ResponseStatus_Status ResponseStatus::status() const {
  // @@protoc_insertion_point(field_get:response.ResponseStatus.status)
  return _internal_status();
}
inline void ResponseStatus::_internal_set_status(::response::ResponseStatus_Status value) {
  
  status_ = value;
}
inline void ResponseStatus::set_status(::response::ResponseStatus_Status value) {
  _internal_set_status(value);
  // @@protoc_insertion_point(field_set:response.ResponseStatus.status)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace response

PROTOBUF_NAMESPACE_OPEN

template <> struct is_proto_enum< ::response::ResponseStatus_Status> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::response::ResponseStatus_Status>() {
  return ::response::ResponseStatus_Status_descriptor();
}

PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_ftqproto_2fResponseStatus_2eproto
