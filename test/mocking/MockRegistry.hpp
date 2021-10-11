#pragma once

#include <string>
#include <vector>

class MockRegistry {
public:
  std::vector<std::string> methodNames;
  std::vector<std::vector<void *>> methodArgs;
  std::vector<void *> returns;
  std::vector<std::vector<void *>> calledWith;

public:
  int getMethodIndex(std::string methodName) {
    int i = 0;
    for (std::string mn : methodNames) {
      if (mn == methodName) {
        return i;
      }
      i++;
    }
    return -1;
  }

  void addMethodName(std::string name) { methodNames.push_back(name); }

  template <typename T> void addMethodArgs(std::vector<void *> &type, T arg) {
    T *t = new T(arg);
    type.push_back((void *)t);
    std::cout << "Final Value is: " << arg << std::endl;
    methodArgs.push_back(type);
  }

  template <typename T, typename... Args>
  void addMethodArgs(std::vector<void *> &type, T arg, Args... args) {
    T *t = new T(arg);
    std::cout << "Value is: " << arg << std::endl;
    type.push_back((void *)t);
    addMethodArgs(type, args...);
  }

  void addReturnValues(void *value) { returns.push_back(value); }

  template <typename T> T get(std::string methodName, T arg) {
    int i = getMethodIndex(methodName);
  }

  template <typename T, typename... Args>
  T get(std::string methodName, T arg, Args... args) {

    int i = getMethodIndex(methodName);

    if (i == -1) {
      std::cout << "No method mock found" << std::endl;
      throw std::exception();
    }
    if (returns.size() <= i || methodArgs.size() <= i) {
      std::cout << "Method was not mocked with a return value" << std::endl;
      throw std::exception();
    }

    std::vector<void *> methodArguments = methodArgs.at(i);
    if (wasCalledWith(methodArguments, 0, arg, args...)) {
      return *reinterpret_cast<T *>(returns.at(i));
    } else {
      std::cout << methodName
                << " has not mocked to be called with args: " << std::endl;
      throw std::exception();
    }
  }

  template <typename T>
  bool wasCalledWith(std::vector<void *> methodArguments, int i, T arg) {
    T value = *reinterpret_cast<T *>(methodArguments.at(i));
    std::cout << "Comparing " << arg << " with " << value << std::endl;
    return value == arg;
  }

  template <typename T, typename... Args>
  bool wasCalledWith(std::vector<void *> methodArguments, int i, T firstArg,
                     Args... args) {
    T value = *reinterpret_cast<T *>(methodArguments.at(i));
    std::cout << "Comparing " << firstArg << " with " << value << std::endl;
    return value == firstArg &&
           wasCalledWith(methodArguments, ++i, std::forward<Args>(args)...);
  }
};