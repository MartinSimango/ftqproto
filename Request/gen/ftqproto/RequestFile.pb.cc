// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: ftqproto/RequestFile.proto

#include "ftqproto/RequestFile.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG
namespace request {
constexpr RequestFile::RequestFile(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : sourcefilepath_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string)
  , filesize_(0)
  , isdir_(false){}
struct RequestFileDefaultTypeInternal {
  constexpr RequestFileDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~RequestFileDefaultTypeInternal() {}
  union {
    RequestFile _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT RequestFileDefaultTypeInternal _RequestFile_default_instance_;
constexpr RequestFiles::RequestFiles(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : requestfiles_(){}
struct RequestFilesDefaultTypeInternal {
  constexpr RequestFilesDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~RequestFilesDefaultTypeInternal() {}
  union {
    RequestFiles _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT RequestFilesDefaultTypeInternal _RequestFiles_default_instance_;
}  // namespace request
static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_ftqproto_2fRequestFile_2eproto[2];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_ftqproto_2fRequestFile_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_ftqproto_2fRequestFile_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_ftqproto_2fRequestFile_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::request::RequestFile, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::request::RequestFile, sourcefilepath_),
  PROTOBUF_FIELD_OFFSET(::request::RequestFile, filesize_),
  PROTOBUF_FIELD_OFFSET(::request::RequestFile, isdir_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::request::RequestFiles, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::request::RequestFiles, requestfiles_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::request::RequestFile)},
  { 8, -1, sizeof(::request::RequestFiles)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::request::_RequestFile_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::request::_RequestFiles_default_instance_),
};

const char descriptor_table_protodef_ftqproto_2fRequestFile_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\032ftqproto/RequestFile.proto\022\007request\"F\n"
  "\013RequestFile\022\026\n\016sourceFilePath\030\001 \001(\t\022\020\n\010"
  "fileSize\030\002 \001(\005\022\r\n\005isDir\030\003 \001(\010\":\n\014Request"
  "Files\022*\n\014requestFiles\030\001 \003(\0132\024.request.Re"
  "questFileBAZ\?github.com/MartinSimango/go"
  "ftqproto/internal/request/genrequestb\006pr"
  "oto3"
  ;
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_ftqproto_2fRequestFile_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_ftqproto_2fRequestFile_2eproto = {
  false, false, 244, descriptor_table_protodef_ftqproto_2fRequestFile_2eproto, "ftqproto/RequestFile.proto", 
  &descriptor_table_ftqproto_2fRequestFile_2eproto_once, nullptr, 0, 2,
  schemas, file_default_instances, TableStruct_ftqproto_2fRequestFile_2eproto::offsets,
  file_level_metadata_ftqproto_2fRequestFile_2eproto, file_level_enum_descriptors_ftqproto_2fRequestFile_2eproto, file_level_service_descriptors_ftqproto_2fRequestFile_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable* descriptor_table_ftqproto_2fRequestFile_2eproto_getter() {
  return &descriptor_table_ftqproto_2fRequestFile_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY static ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptorsRunner dynamic_init_dummy_ftqproto_2fRequestFile_2eproto(&descriptor_table_ftqproto_2fRequestFile_2eproto);
namespace request {

// ===================================================================

class RequestFile::_Internal {
 public:
};

RequestFile::RequestFile(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:request.RequestFile)
}
RequestFile::RequestFile(const RequestFile& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  sourcefilepath_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_sourcefilepath().empty()) {
    sourcefilepath_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_sourcefilepath(), 
      GetArenaForAllocation());
  }
  ::memcpy(&filesize_, &from.filesize_,
    static_cast<size_t>(reinterpret_cast<char*>(&isdir_) -
    reinterpret_cast<char*>(&filesize_)) + sizeof(isdir_));
  // @@protoc_insertion_point(copy_constructor:request.RequestFile)
}

void RequestFile::SharedCtor() {
sourcefilepath_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
::memset(reinterpret_cast<char*>(this) + static_cast<size_t>(
    reinterpret_cast<char*>(&filesize_) - reinterpret_cast<char*>(this)),
    0, static_cast<size_t>(reinterpret_cast<char*>(&isdir_) -
    reinterpret_cast<char*>(&filesize_)) + sizeof(isdir_));
}

RequestFile::~RequestFile() {
  // @@protoc_insertion_point(destructor:request.RequestFile)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void RequestFile::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  sourcefilepath_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void RequestFile::ArenaDtor(void* object) {
  RequestFile* _this = reinterpret_cast< RequestFile* >(object);
  (void)_this;
}
void RequestFile::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void RequestFile::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void RequestFile::Clear() {
// @@protoc_insertion_point(message_clear_start:request.RequestFile)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  sourcefilepath_.ClearToEmpty();
  ::memset(&filesize_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&isdir_) -
      reinterpret_cast<char*>(&filesize_)) + sizeof(isdir_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* RequestFile::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // string sourceFilePath = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          auto str = _internal_mutable_sourcefilepath();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "request.RequestFile.sourceFilePath"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // int32 fileSize = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 16)) {
          filesize_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // bool isDir = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 24)) {
          isdir_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag == 0) || ((tag & 7) == 4)) {
          CHK_(ptr);
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* RequestFile::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:request.RequestFile)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string sourceFilePath = 1;
  if (!this->sourcefilepath().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_sourcefilepath().data(), static_cast<int>(this->_internal_sourcefilepath().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "request.RequestFile.sourceFilePath");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_sourcefilepath(), target);
  }

  // int32 fileSize = 2;
  if (this->filesize() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(2, this->_internal_filesize(), target);
  }

  // bool isDir = 3;
  if (this->isdir() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteBoolToArray(3, this->_internal_isdir(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:request.RequestFile)
  return target;
}

size_t RequestFile::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:request.RequestFile)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string sourceFilePath = 1;
  if (!this->sourcefilepath().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_sourcefilepath());
  }

  // int32 fileSize = 2;
  if (this->filesize() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
        this->_internal_filesize());
  }

  // bool isDir = 3;
  if (this->isdir() != 0) {
    total_size += 1 + 1;
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void RequestFile::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:request.RequestFile)
  GOOGLE_DCHECK_NE(&from, this);
  const RequestFile* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<RequestFile>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:request.RequestFile)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:request.RequestFile)
    MergeFrom(*source);
  }
}

void RequestFile::MergeFrom(const RequestFile& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:request.RequestFile)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from.sourcefilepath().empty()) {
    _internal_set_sourcefilepath(from._internal_sourcefilepath());
  }
  if (from.filesize() != 0) {
    _internal_set_filesize(from._internal_filesize());
  }
  if (from.isdir() != 0) {
    _internal_set_isdir(from._internal_isdir());
  }
}

void RequestFile::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:request.RequestFile)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void RequestFile::CopyFrom(const RequestFile& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:request.RequestFile)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool RequestFile::IsInitialized() const {
  return true;
}

void RequestFile::InternalSwap(RequestFile* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      &sourcefilepath_, GetArenaForAllocation(),
      &other->sourcefilepath_, other->GetArenaForAllocation()
  );
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(RequestFile, isdir_)
      + sizeof(RequestFile::isdir_)
      - PROTOBUF_FIELD_OFFSET(RequestFile, filesize_)>(
          reinterpret_cast<char*>(&filesize_),
          reinterpret_cast<char*>(&other->filesize_));
}

::PROTOBUF_NAMESPACE_ID::Metadata RequestFile::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_ftqproto_2fRequestFile_2eproto_getter, &descriptor_table_ftqproto_2fRequestFile_2eproto_once,
      file_level_metadata_ftqproto_2fRequestFile_2eproto[0]);
}

// ===================================================================

class RequestFiles::_Internal {
 public:
};

RequestFiles::RequestFiles(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena),
  requestfiles_(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:request.RequestFiles)
}
RequestFiles::RequestFiles(const RequestFiles& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      requestfiles_(from.requestfiles_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  // @@protoc_insertion_point(copy_constructor:request.RequestFiles)
}

void RequestFiles::SharedCtor() {
}

RequestFiles::~RequestFiles() {
  // @@protoc_insertion_point(destructor:request.RequestFiles)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void RequestFiles::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
}

void RequestFiles::ArenaDtor(void* object) {
  RequestFiles* _this = reinterpret_cast< RequestFiles* >(object);
  (void)_this;
}
void RequestFiles::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void RequestFiles::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void RequestFiles::Clear() {
// @@protoc_insertion_point(message_clear_start:request.RequestFiles)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  requestfiles_.Clear();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* RequestFiles::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // repeated .request.RequestFile requestFiles = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_requestfiles(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<10>(ptr));
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag == 0) || ((tag & 7) == 4)) {
          CHK_(ptr);
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* RequestFiles::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:request.RequestFiles)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated .request.RequestFile requestFiles = 1;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->_internal_requestfiles_size()); i < n; i++) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(1, this->_internal_requestfiles(i), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:request.RequestFiles)
  return target;
}

size_t RequestFiles::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:request.RequestFiles)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .request.RequestFile requestFiles = 1;
  total_size += 1UL * this->_internal_requestfiles_size();
  for (const auto& msg : this->requestfiles_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void RequestFiles::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:request.RequestFiles)
  GOOGLE_DCHECK_NE(&from, this);
  const RequestFiles* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<RequestFiles>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:request.RequestFiles)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:request.RequestFiles)
    MergeFrom(*source);
  }
}

void RequestFiles::MergeFrom(const RequestFiles& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:request.RequestFiles)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  requestfiles_.MergeFrom(from.requestfiles_);
}

void RequestFiles::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:request.RequestFiles)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void RequestFiles::CopyFrom(const RequestFiles& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:request.RequestFiles)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool RequestFiles::IsInitialized() const {
  return true;
}

void RequestFiles::InternalSwap(RequestFiles* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  requestfiles_.InternalSwap(&other->requestfiles_);
}

::PROTOBUF_NAMESPACE_ID::Metadata RequestFiles::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_ftqproto_2fRequestFile_2eproto_getter, &descriptor_table_ftqproto_2fRequestFile_2eproto_once,
      file_level_metadata_ftqproto_2fRequestFile_2eproto[1]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace request
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::request::RequestFile* Arena::CreateMaybeMessage< ::request::RequestFile >(Arena* arena) {
  return Arena::CreateMessageInternal< ::request::RequestFile >(arena);
}
template<> PROTOBUF_NOINLINE ::request::RequestFiles* Arena::CreateMaybeMessage< ::request::RequestFiles >(Arena* arena) {
  return Arena::CreateMessageInternal< ::request::RequestFiles >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>