#pragma once

#include "../../../domain/util/include/FtqUtil.hpp"
#include <string>

namespace ftq_usecase {

typedef struct {
	std::string filePath;
	ftq_domain::uint32 numberOfBytesToRead;
	ftq_domain::uint32 offset;

} ReadRequest;

} // namespace ftq_usecase
