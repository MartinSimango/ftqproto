#pragma once

#include "../../../domain/util/include/FtqUtil.hpp"
#include <string>

namespace ftq_usecase {

typedef struct {
	std::string filePath;
	std::string data;
	ftq_domain::uint32 offset;

} WriteRequest;

} // namespace ftq_usecase
