#pragma once

#include "../../request/include/RequestFile.hpp"
#include "ResponseStatus.hpp"
#include <vector>

namespace ftq_usecase {

typedef struct {
  std::vector<RequestFile> files;
  ResponseStatus status;
} GetResponse;
} // namespace ftq_usecase
