// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: ftqproto/CreateRequest.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_ftqproto_2fCreateRequest_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_ftqproto_2fCreateRequest_2eproto

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
#include "ftqproto/RequestFile.pb.h"
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_ftqproto_2fCreateRequest_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_ftqproto_2fCreateRequest_2eproto {
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
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_ftqproto_2fCreateRequest_2eproto;
namespace request {
class CreateRequest;
struct CreateRequestDefaultTypeInternal;
extern CreateRequestDefaultTypeInternal _CreateRequest_default_instance_;
}  // namespace request
PROTOBUF_NAMESPACE_OPEN
template<> ::request::CreateRequest* Arena::CreateMaybeMessage<::request::CreateRequest>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace request {

// ===================================================================

class CreateRequest final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:request.CreateRequest) */ {
 public:
  inline CreateRequest() : CreateRequest(nullptr) {}
  ~CreateRequest() override;
  explicit constexpr CreateRequest(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  CreateRequest(const CreateRequest& from);
  CreateRequest(CreateRequest&& from) noexcept
    : CreateRequest() {
    *this = ::std::move(from);
  }

  inline CreateRequest& operator=(const CreateRequest& from) {
    CopyFrom(from);
    return *this;
  }
  inline CreateRequest& operator=(CreateRequest&& from) noexcept {
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
  static const CreateRequest& default_instance() {
    return *internal_default_instance();
  }
  static inline const CreateRequest* internal_default_instance() {
    return reinterpret_cast<const CreateRequest*>(
               &_CreateRequest_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(CreateRequest& a, CreateRequest& b) {
    a.Swap(&b);
  }
  inline void Swap(CreateRequest* other) {
    if (other == this) return;
    if (GetOwningArena() == other->GetOwningArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(CreateRequest* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline CreateRequest* New() const final {
    return new CreateRequest();
  }

  CreateRequest* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<CreateRequest>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const CreateRequest& from);
  void MergeFrom(const CreateRequest& from);
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
  void InternalSwap(CreateRequest* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "request.CreateRequest";
  }
  protected:
  explicit CreateRequest(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kFilesFieldNumber = 3,
    kSourceFilePathFieldNumber = 1,
    kDestinationFilePathFieldNumber = 2,
  };
  // repeated .request.RequestFile files = 3;
  int files_size() const;
  private:
  int _internal_files_size() const;
  public:
  void clear_files();
  ::request::RequestFile* mutable_files(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::request::RequestFile >*
      mutable_files();
  private:
  const ::request::RequestFile& _internal_files(int index) const;
  ::request::RequestFile* _internal_add_files();
  public:
  const ::request::RequestFile& files(int index) const;
  ::request::RequestFile* add_files();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::request::RequestFile >&
      files() const;

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

  // string destinationFilePath = 2;
  void clear_destinationfilepath();
  const std::string& destinationfilepath() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_destinationfilepath(ArgT0&& arg0, ArgT... args);
  std::string* mutable_destinationfilepath();
  PROTOBUF_FUTURE_MUST_USE_RESULT std::string* release_destinationfilepath();
  void set_allocated_destinationfilepath(std::string* destinationfilepath);
  private:
  const std::string& _internal_destinationfilepath() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_destinationfilepath(const std::string& value);
  std::string* _internal_mutable_destinationfilepath();
  public:

  // @@protoc_insertion_point(class_scope:request.CreateRequest)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::request::RequestFile > files_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr sourcefilepath_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr destinationfilepath_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_ftqproto_2fCreateRequest_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// CreateRequest

// string sourceFilePath = 1;
inline void CreateRequest::clear_sourcefilepath() {
  sourcefilepath_.ClearToEmpty();
}
inline const std::string& CreateRequest::sourcefilepath() const {
  // @@protoc_insertion_point(field_get:request.CreateRequest.sourceFilePath)
  return _internal_sourcefilepath();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void CreateRequest::set_sourcefilepath(ArgT0&& arg0, ArgT... args) {
 
 sourcefilepath_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:request.CreateRequest.sourceFilePath)
}
inline std::string* CreateRequest::mutable_sourcefilepath() {
  // @@protoc_insertion_point(field_mutable:request.CreateRequest.sourceFilePath)
  return _internal_mutable_sourcefilepath();
}
inline const std::string& CreateRequest::_internal_sourcefilepath() const {
  return sourcefilepath_.Get();
}
inline void CreateRequest::_internal_set_sourcefilepath(const std::string& value) {
  
  sourcefilepath_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* CreateRequest::_internal_mutable_sourcefilepath() {
  
  return sourcefilepath_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* CreateRequest::release_sourcefilepath() {
  // @@protoc_insertion_point(field_release:request.CreateRequest.sourceFilePath)
  return sourcefilepath_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
}
inline void CreateRequest::set_allocated_sourcefilepath(std::string* sourcefilepath) {
  if (sourcefilepath != nullptr) {
    
  } else {
    
  }
  sourcefilepath_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), sourcefilepath,
      GetArenaForAllocation());
  // @@protoc_insertion_point(field_set_allocated:request.CreateRequest.sourceFilePath)
}

// string destinationFilePath = 2;
inline void CreateRequest::clear_destinationfilepath() {
  destinationfilepath_.ClearToEmpty();
}
inline const std::string& CreateRequest::destinationfilepath() const {
  // @@protoc_insertion_point(field_get:request.CreateRequest.destinationFilePath)
  return _internal_destinationfilepath();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void CreateRequest::set_destinationfilepath(ArgT0&& arg0, ArgT... args) {
 
 destinationfilepath_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:request.CreateRequest.destinationFilePath)
}
inline std::string* CreateRequest::mutable_destinationfilepath() {
  // @@protoc_insertion_point(field_mutable:request.CreateRequest.destinationFilePath)
  return _internal_mutable_destinationfilepath();
}
inline const std::string& CreateRequest::_internal_destinationfilepath() const {
  return destinationfilepath_.Get();
}
inline void CreateRequest::_internal_set_destinationfilepath(const std::string& value) {
  
  destinationfilepath_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* CreateRequest::_internal_mutable_destinationfilepath() {
  
  return destinationfilepath_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* CreateRequest::release_destinationfilepath() {
  // @@protoc_insertion_point(field_release:request.CreateRequest.destinationFilePath)
  return destinationfilepath_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
}
inline void CreateRequest::set_allocated_destinationfilepath(std::string* destinationfilepath) {
  if (destinationfilepath != nullptr) {
    
  } else {
    
  }
  destinationfilepath_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), destinationfilepath,
      GetArenaForAllocation());
  // @@protoc_insertion_point(field_set_allocated:request.CreateRequest.destinationFilePath)
}

// repeated .request.RequestFile files = 3;
inline int CreateRequest::_internal_files_size() const {
  return files_.size();
}
inline int CreateRequest::files_size() const {
  return _internal_files_size();
}
inline ::request::RequestFile* CreateRequest::mutable_files(int index) {
  // @@protoc_insertion_point(field_mutable:request.CreateRequest.files)
  return files_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::request::RequestFile >*
CreateRequest::mutable_files() {
  // @@protoc_insertion_point(field_mutable_list:request.CreateRequest.files)
  return &files_;
}
inline const ::request::RequestFile& CreateRequest::_internal_files(int index) const {
  return files_.Get(index);
}
inline const ::request::RequestFile& CreateRequest::files(int index) const {
  // @@protoc_insertion_point(field_get:request.CreateRequest.files)
  return _internal_files(index);
}
inline ::request::RequestFile* CreateRequest::_internal_add_files() {
  return files_.Add();
}
inline ::request::RequestFile* CreateRequest::add_files() {
  // @@protoc_insertion_point(field_add:request.CreateRequest.files)
  return _internal_add_files();
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::request::RequestFile >&
CreateRequest::files() const {
  // @@protoc_insertion_point(field_list:request.CreateRequest.files)
  return files_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace request

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_ftqproto_2fCreateRequest_2eproto
