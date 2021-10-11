// #pragma once

#include "../../../src/driver/fileIO/include/FileIO.hpp"
#include "../../FtqTest.hpp"

using namespace ftq_driver;

namespace ftq_test {

// todo make test classes Singletons
class FileIOTests : public FtqTest {

private:
  static FileIO *fileIORead;
  static FileIO *fileIOWrite;

  static std::string TEST_FILE;
  static std::string TEST_DIRECTORY;

  static void setUp() {
    delete fileIORead;
    delete fileIOWrite;
    fileIORead = new FileIO(TEST_FILE, Mode::READ);
    fileIOWrite = new FileIO(TEST_FILE, Mode::WRITE);
  }

  static void destroy() {
    delete fileIORead;
    delete fileIOWrite;
    fileIORead = NULL;
    fileIOWrite = NULL;
  }

public:
  FileIOTests() : FtqTest("FileIOTests") { setupTests(); }

  ~FileIOTests() {}

  void setupTests() {
    setUp();
    REGISTER_TEST(testCreateFile_shouldAssertToTrue);
    REGISTER_TEST(testCreateFile_shouldAssertToFalse);
    REGISTER_TEST(testCreateDirectory_shouldAssertToTrue);
  }

  // TESTS

  static void testCreateFile_shouldAssertToTrue() {
    std::string filePath = TEST_DIRECTORY + "/" + TEST_FILE;
    FileIO::CreateFile(filePath, 0);
    FtqAssert::assertEqualTo(FileIO::DoesFileExist(filePath), true);
  }

  static void testCreateFile_shouldAssertToFalse() {
    FtqAssert::assertEqualTo(
        FileIO::DoesFileExist(TEST_DIRECTORY + "/random_file"), false);
  }

  static void testCreateDirectory_shouldAssertToTrue() {
    std::string filePath = TEST_DIRECTORY + "/" + "dir";
    FileIO::CreateDirectory(filePath);
    FtqAssert::assertEqualTo(FileIO::DoesFileExist(filePath), true);
    FtqAssert::assertEqualTo(FileIO::CheckFileIsDirectory(filePath.c_str()),
                             true);
  }
};

std::string FileIOTests::TEST_DIRECTORY = "/tmp/ftqproto_tests";
std::string FileIOTests::TEST_FILE = "test_file.txt";
FileIO *FileIOTests::fileIORead = NULL;
FileIO *FileIOTests::fileIOWrite = NULL;

} // namespace ftq_test