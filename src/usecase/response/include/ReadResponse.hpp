#pragma once

#include "ResponseStatus.hpp"
#include <string>

namespace ftq_usecase {

typedef struct {
	std::string data;
	ResponseStatus status;
} ReadResponse;
} // namespace ftq_usecase
