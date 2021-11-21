#pragma once

#include "ResponseStatus.hpp"
#include <string>

namespace ftq_usecase {

typedef struct {
	std::string sourceFilePath;
	ResponseStatus status;

} ResponseFile;
} // namespace ftq_usecase
