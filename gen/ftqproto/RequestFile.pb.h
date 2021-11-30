// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: ftqproto/RequestFile.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_ftqproto_2fRequestFile_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_ftqproto_2fRequestFile_2eproto

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
#define PROTOBUF_INTERNAL_EXPORT_ftqproto_2fRequestFile_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_ftqproto_2fRequestFile_2eproto {
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
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_ftqproto_2fRequestFile_2eproto;
namespace request {
class RequestFile;
struct RequestFileDefaultTypeInternal;
extern RequestFileDefaultTypeInternal _RequestFile_default_instance_;
}  // namespace request
PROTOBUF_NAMESPACE_OPEN
template<> ::request::RequestFile* Arena::CreateMaybeMessage<::request::RequestFile>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace request {

// ===================================================================

class RequestFile final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:request.RequestFile) */ {
 public:
  inline RequestFile() : RequestFile(nullptr) {}
  ~RequestFile() override;
  explicit constexpr RequestFile(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  RequestFile(const RequestFile& from);
  RequestFile(RequestFile&& from) noexcept
    : RequestFile() {
    *this = ::std::move(from);
  }

  inline RequestFile& operator=(const RequestFile& from) {
    CopyFrom(from);
    return *this;
  }
  inline RequestFile& operator=(RequestFile&& from) noexcept {
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
  static const RequestFile& default_instance() {
    return *internal_default_instance();
  }
  static inline const RequestFile* internal_default_instance() {
    return reinterpret_cast<const RequestFile*>(
               &_RequestFile_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(RequestFile& a, RequestFile& b) {
    a.Swap(&b);
  }
  inline void Swap(RequestFile* other) {
    if (other == this) return;
    if (GetOwningArena() == other->GetOwningArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(RequestFile* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline RequestFile* New() const final {
    return new RequestFile();
  }

  RequestFile* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<RequestFile>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const RequestFile& from);
  void MergeFrom(const RequestFile& from);
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
  void InternalSwap(RequestFile* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "request.RequestFile";
  }
  protected:
  explicit RequestFile(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kSourceFilePathFieldNumber = 1,
    kFileSizeFieldNumber = 2,
    kIsDirFieldNumber = 3,
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

  // int32 fileSize = 2;
  void clear_filesize();
  ::PROTOBUF_NAMESPACE_ID::int32 filesize() const;
  void set_filesize(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_filesize() const;
  void _internal_set_filesize(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // bool isDir = 3;
  void clear_isdir();
  bool isdir() const;
  void set_isdir(bool value);
  private:
  bool _internal_isdir() const;
  void _internal_set_isdir(bool value);
  public:

  // @@protoc_insertion_point(class_scope:request.RequestFile)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr sourcefilepath_;
  ::PROTOBUF_NAMESPACE_ID::int32 filesize_;
  bool isdir_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_ftqproto_2fRequestFile_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// RequestFile

// string sourceFilePath = 1;
inline void RequestFile::clear_sourcefilepath() {
  sourcefilepath_.ClearToEmpty();
}
inline const std::string& RequestFile::sourcefilepath() const {
  // @@protoc_insertion_point(field_get:request.RequestFile.sourceFilePath)
  return _internal_sourcefilepath();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void RequestFile::set_sourcefilepath(ArgT0&& arg0, ArgT... args) {
 
 sourcefilepath_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:request.RequestFile.sourceFilePath)
}
inline std::string* RequestFile::mutable_sourcefilepath() {
  // @@protoc_insertion_point(field_mutable:request.RequestFile.sourceFilePath)
  return _internal_mutable_sourcefilepath();
}
inline const std::string& RequestFile::_internal_sourcefilepath() const {
  return sourcefilepath_.Get();
}
inline void RequestFile::_internal_set_sourcefilepath(const std::string& value) {
  
  sourcefilepath_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* RequestFile::_internal_mutable_sourcefilepath() {
  
  return sourcefilepath_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* RequestFile::release_sourcefilepath() {
  // @@protoc_insertion_point(field_release:request.RequestFile.sourceFilePath)
  return sourcefilepath_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
}
inline void RequestFile::set_allocated_sourcefilepath(std::string* sourcefilepath) {
  if (sourcefilepath != nullptr) {
    
  } else {
    
  }
  sourcefilepath_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), sourcefilepath,
      GetArenaForAllocation());
  // @@protoc_insertion_point(field_set_allocated:request.RequestFile.sourceFilePath)
}

// int32 fileSize = 2;
inline void RequestFile::clear_filesize() {
  filesize_ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 RequestFile::_internal_filesize() const {
  return filesize_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 RequestFile::filesize() const {
  // @@protoc_insertion_point(field_get:request.RequestFile.fileSize)
  return _internal_filesize();
}
inline void RequestFile::_internal_set_filesize(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  filesize_ = value;
}
inline void RequestFile::set_filesize(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_filesize(value);
  // @@protoc_insertion_point(field_set:request.RequestFile.fileSize)
}

// bool isDir = 3;
inline void RequestFile::clear_isdir() {
  isdir_ = false;
}
inline bool RequestFile::_internal_isdir() const {
  return isdir_;
}
inline bool RequestFile::isdir() const {
  // @@protoc_insertion_point(field_get:request.RequestFile.isDir)
  return _internal_isdir();
}
inline void RequestFile::_internal_set_isdir(bool value) {
  
  isdir_ = value;
}
inline void RequestFile::set_isdir(bool value) {
  _internal_set_isdir(value);
  // @@protoc_insertion_point(field_set:request.RequestFile.isDir)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace request

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_ftqproto_2fRequestFile_2eproto