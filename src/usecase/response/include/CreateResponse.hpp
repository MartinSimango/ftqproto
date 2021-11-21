#pragma once

#include "ResponseFile.hpp"
#include "ResponseStatus.hpp"
#include <vector>

namespace ftq_usecase {

typedef struct {
	std::vector<ResponseFile> files;
	ResponseStatus status;
} CreateResponse;
} // namespace ftq_usecase
