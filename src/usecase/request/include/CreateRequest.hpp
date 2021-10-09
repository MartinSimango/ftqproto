#pragma once

#include "RequestFile.hpp"
#include <string>
#include <vector>

namespace ftq_usecase {

typedef struct {

  std::string sourceFilePath;
  std::string destinationFilePath;
  bool isSourceDirectory;
  std::vector<RequestFile> files;
  /* data */
} CreateRequest;

} // namespace ftq_usecase
