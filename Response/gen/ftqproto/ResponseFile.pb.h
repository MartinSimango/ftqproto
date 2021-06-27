// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: ftqproto/ResponseFile.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_ftqproto_2fResponseFile_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_ftqproto_2fResponseFile_2eproto

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
#include "ftqproto/ResponseStatus.pb.h"
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_ftqproto_2fResponseFile_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_ftqproto_2fResponseFile_2eproto {
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
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_ftqproto_2fResponseFile_2eproto;
namespace response {
class ResponseFile;
struct ResponseFileDefaultTypeInternal;
extern ResponseFileDefaultTypeInternal _ResponseFile_default_instance_;
}  // namespace response
PROTOBUF_NAMESPACE_OPEN
template<> ::response::ResponseFile* Arena::CreateMaybeMessage<::response::ResponseFile>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace response {

// ===================================================================

class ResponseFile final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:response.ResponseFile) */ {
 public:
  inline ResponseFile() : ResponseFile(nullptr) {}
  ~ResponseFile() override;
  explicit constexpr ResponseFile(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  ResponseFile(const ResponseFile& from);
  ResponseFile(ResponseFile&& from) noexcept
    : ResponseFile() {
    *this = ::std::move(from);
  }

  inline ResponseFile& operator=(const ResponseFile& from) {
    CopyFrom(from);
    return *this;
  }
  inline ResponseFile& operator=(ResponseFile&& from) noexcept {
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
  static const ResponseFile& default_instance() {
    return *internal_default_instance();
  }
  static inline const ResponseFile* internal_default_instance() {
    return reinterpret_cast<const ResponseFile*>(
               &_ResponseFile_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(ResponseFile& a, ResponseFile& b) {
    a.Swap(&b);
  }
  inline void Swap(ResponseFile* other) {
    if (other == this) return;
    if (GetOwningArena() == other->GetOwningArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(ResponseFile* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline ResponseFile* New() const final {
    return new ResponseFile();
  }

  ResponseFile* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<ResponseFile>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const ResponseFile& from);
  void MergeFrom(const ResponseFile& from);
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
  void InternalSwap(ResponseFile* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "response.ResponseFile";
  }
  protected:
  explicit ResponseFile(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kSourceFilePathFieldNumber = 1,
    kStatusFieldNumber = 2,
  };
  // string sourceFilePath = 1;
  void clear_sourcefilepath();
  const std::string& sourcefilepath() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_sourcefilepath(ArgT0&& arg0, ArgT... args);
  std::string* mutable_sourcefilepath();
  PROTOBUF_FUTURE_MUST_USE_RESULT std::string* release_sourcefilepath();
  void set_allocated_sourcefilepath(std::string* sourcefilepath);
  private:
  const std::string& _internal_sourcefilepath() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_sourcefilepath(const std::string& value);
  std::string* _internal_mutable_sourcefilepath();
  public:

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

  // @@protoc_insertion_point(class_scope:response.ResponseFile)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr sourcefilepath_;
  ::response::ResponseStatus* status_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_ftqproto_2fResponseFile_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// ResponseFile

// string sourceFilePath = 1;
inline void ResponseFile::clear_sourcefilepath() {
  sourcefilepath_.ClearToEmpty();
}
inline const std::string& ResponseFile::sourcefilepath() const {
  // @@protoc_insertion_point(field_get:response.ResponseFile.sourceFilePath)
  return _internal_sourcefilepath();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void ResponseFile::set_sourcefilepath(ArgT0&& arg0, ArgT... args) {
 
 sourcefilepath_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:response.ResponseFile.sourceFilePath)
}
inline std::string* ResponseFile::mutable_sourcefilepath() {
  // @@protoc_insertion_point(field_mutable:response.ResponseFile.sourceFilePath)
  return _internal_mutable_sourcefilepath();
}
inline const std::string& ResponseFile::_internal_sourcefilepath() const {
  return sourcefilepath_.Get();
}
inline void ResponseFile::_internal_set_sourcefilepath(const std::string& value) {
  
  sourcefilepath_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* ResponseFile::_internal_mutable_sourcefilepath() {
  
  return sourcefilepath_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* ResponseFile::release_sourcefilepath() {
  // @@protoc_insertion_point(field_release:response.ResponseFile.sourceFilePath)
  return sourcefilepath_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
}
inline void ResponseFile::set_allocated_sourcefilepath(std::string* sourcefilepath) {
  if (sourcefilepath != nullptr) {
    
  } else {
    
  }
  sourcefilepath_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), sourcefilepath,
      GetArenaForAllocation());
  // @@protoc_insertion_point(field_set_allocated:response.ResponseFile.sourceFilePath)
}

// .response.ResponseStatus status = 2;
inline bool ResponseFile::_internal_has_status() const {
  return this != internal_default_instance() && status_ != nullptr;
}
inline bool ResponseFile::has_status() const {
  return _internal_has_status();
}
inline const ::response::ResponseStatus& ResponseFile::_internal_status() const {
  const ::response::ResponseStatus* p = status_;
  return p != nullptr ? *p : reinterpret_cast<const ::response::ResponseStatus&>(
      ::response::_ResponseStatus_default_instance_);
}
inline const ::response::ResponseStatus& ResponseFile::status() const {
  // @@protoc_insertion_point(field_get:response.ResponseFile.status)
  return _internal_status();
}
inline void ResponseFile::unsafe_arena_set_allocated_status(
    ::response::ResponseStatus* status) {
  if (GetArenaForAllocation() == nullptr) {
    delete reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(status_);
  }
  status_ = status;
  if (status) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:response.ResponseFile.status)
}
inline ::response::ResponseStatus* ResponseFile::release_status() {
  
  ::response::ResponseStatus* temp = status_;
  status_ = nullptr;
  if (GetArenaForAllocation() != nullptr) {
    temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  }
  return temp;
}
inline ::response::ResponseStatus* ResponseFile::unsafe_arena_release_status() {
  // @@protoc_insertion_point(field_release:response.ResponseFile.status)
  
  ::response::ResponseStatus* temp = status_;
  status_ = nullptr;
  return temp;
}
inline ::response::ResponseStatus* ResponseFile::_internal_mutable_status() {
  
  if (status_ == nullptr) {
    auto* p = CreateMaybeMessage<::response::ResponseStatus>(GetArenaForAllocation());
    status_ = p;
  }
  return status_;
}
inline ::response::ResponseStatus* ResponseFile::mutable_status() {
  // @@protoc_insertion_point(field_mutable:response.ResponseFile.status)
  return _internal_mutable_status();
}
inline void ResponseFile::set_allocated_status(::response::ResponseStatus* status) {
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
  // @@protoc_insertion_point(field_set_allocated:response.ResponseFile.status)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace response

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_ftqproto_2fResponseFile_2eproto
