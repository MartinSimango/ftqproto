#pragma once
#include "MockRegistry.hpp"
#include <type_traits>
#include <typeinfo>
#include <vector>

struct SomeInterface {
  /* data */
  virtual int foo(int a, std::string b) = 0;
  virtual int boo(int a) = 0;
  // virtual void time() = 0;
};

template <typename Type> class Mock {

public:
  MockRegistry registry;
  Type instance;

  Mock() { instance.registry = &registry; }

  Type getType() { return Type(); }

  Type &get() { return instance; }

  void addMethodName(std::string name) { registry.addMethodName(name); }

  template <typename... Args> void addMethodArgs(Args... args) {
    std::vector<void *> type;
    registry.addMethodArgs(type, args...);
  }

  void addReturnValues(void *value) { registry.addReturnValues(value); }

  template <typename... Args>
  bool wasCalledWith(std::vector<void *> methodArguments, Args... args) {
    return registry.wasCalledWith(methodArguments, 0,
                                  std::forward<Args>(args)...);
  }

  int getMethodIndex(std::string methodName) {
    return registry.getMethodIndex(methodName);
  }

  std::vector<void *> getMethodArgsForMethod(std::string methodName) {
    int index = getMethodIndex(methodName);
    if (index < 0) {
      std::cout << "Method name does not exist" << std::endl;
      throw std::exception();
    }
    if (index >= registry.methodArgs.size()) {
      std::cout << "Method was called" << std::endl;
      throw std::exception();
    }
    return registry.methodArgs.at(index);
  }
};
