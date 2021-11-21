#pragma once

#include "../../../domain/util/include/FtqUtil.hpp"
#include <string>

namespace ftq_usecase {

typedef struct {
	std::string sourceFilePath;
	ftq_domain::uint32 fileSize;
	bool isDir;

} RequestFile;

} // namespace ftq_usecase
