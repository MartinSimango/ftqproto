
#pragma once

#include "Mock.hpp"
#include <iostream>
#include <tuple>

// Below function inspired from: https://www.py4u.net/discuss/76093
#define AF(...) __VA_ARGS__

template <typename ReturnType, typename Object, typename... Args>
class MemberFunctionWrapper {
public:
  typedef ReturnType Type;
  using Tuple = std::tuple<Args...>;
  static constexpr auto Size = sizeof...(Args);

  template <std::size_t N>
  using Nth = typename std::tuple_element<N, Tuple>::type;
  static std::make_integer_sequence<int, Size> S;
  static Tuple tuple;
};

template <typename ReturnType, typename Object, typename... Args>
inline MemberFunctionWrapper<ReturnType, Object, Args...>
createMemberFunctionWrapper(ReturnType (Object::*FuncPtr)(Args...)) {
  return MemberFunctionWrapper<ReturnType, Object, Args...>();
}

template <typename MockObject, typename Retval> class WillReturn {
private:
  Mock<MockObject> *mock;

public:
  WillReturn(Mock<MockObject> *mock) : mock(mock) {}
  void willReturn(Retval value) {
    Retval *val = new Retval(value);
    this->mock->addReturnValues((void *)val);
  }
};

template <typename MockObject, typename Retval, typename... Args> class With {

private:
  Mock<MockObject> *mock;

public:
  With(Mock<MockObject> *mock) : mock(mock) {}

  WillReturn<MockObject, Retval> with(Args... args) {
    mock->addMethodArgs(args...);
    return WillReturn<MockObject, Retval>(mock);
  }
};

template <typename MockObject, typename Retval, typename... Args>
class WasCalledWith {

private:
  Mock<MockObject> *mock;
  std::string methodName;

public:
  WasCalledWith(Mock<MockObject> *mock, std::string methodName)
      : mock(mock), methodName(methodName) {}

  bool wasCalledWith(Args... args) {
    return mock->wasCalledWith(mock->getMethodArgsForMethod(methodName),
                               std::forward<Args>(args)...);
  }
};

template <typename Object, typename Retval, typename... Args>
With<Object, Retval, Args...> expect(Mock<Object> *mock,
                                     Retval (Object::*func)(Args...),
                                     std::string methodName) {
  mock->addMethodName(methodName);
  return With<Object, Retval, Args...>(mock);
}

template <typename Object, typename Retval, typename... Args>
WasCalledWith<Object, Retval, Args...> verify(Mock<Object> *mock,
                                              Retval (Object::*func)(Args...),
                                              std::string methodName) {
  return WasCalledWith<Object, Retval, Args...>(mock, methodName);
}

#define MOCKTYPE(mock) std::remove_reference<decltype((mock).getType())>::type

#define FUNC_RETURN_TYPE(func_name)                                            \
  decltype(createMemberFunctionWrapper(func_name))::Type

#define FUNC_ARGS_COUNT(func_name) createMemberFunctionWrapper(func_name).Size

#define FUNC_ARGS_N(func_name, n)                                              \
  decltype(createMemberFunctionWrapper(func_name))::Nth<n>

#define GET_FUNC_WRAPPER(func_name) createMemberFunctionWrapper(func_name)

#define MOCK_FUNC_ARG_COUNT(mock, func) FUNC_ARGS_COUNT(&MOCKTYPE(mock)::func)

#define MOCK_FUNC_ARG_N(mock, func, n) FUNC_ARGS_N(&MOCKTYPE(mock)::func, n)

#define MOCK_FUNC_TYPE(mock, func) FUNC_RETURN_TYPE(&MOCKTYPE(mock)::func)

#define expectThat(mock, func)                                                 \
  expect<MOCKTYPE(mock), MOCK_FUNC_TYPE(mock, func)>(                          \
      &mock, &MOCKTYPE(mock)::foo, std::string(#func))

#define Verify(mock, func)                                                     \
  verify<MOCKTYPE(mock), MOCK_FUNC_TYPE(mock, func)>(                          \
      &mock, &MOCKTYPE(mock)::foo, std::string(#func))

#define MOCK_METHOD(returnType, methodName, ...)                               \
  MOCK_METHOD_I(returnType, methodName, ##__VA_ARGS__, 9, 8, 7, 6, 5, 4, 3, 2, \
                1, __VA_ARGS__)

#define MOCK_METHOD_I(returnType, methodName, _9, _8, _7, _6, _5, _4, _3, _2,  \
                      _1, X, ...)                                              \
  MOCK_METHOD_##X(returnType, methodName, ##__VA_ARGS__)

#define MOCK_METHOD_(returnType, methodName)                                   \
  returnType methodName() override {                                           \
    return registry->get<returnType>(#methodName);                             \
  }
#define MOCK_METHOD_1(returnType, methodName, arg_1)                           \
  returnType methodName(arg_1 a) override {                                    \
    return registry->get<returnType>(#methodName, a);                          \
  }

#define MOCK_METHOD_2(returnType, methodName, _1, arg_1, arg_2)                \
  returnType methodName(arg_1 a, arg_2 b) override {                           \
    return registry->get<returnType>(#methodName, a, b);                       \
  }

#define MOCK_METHOD_3(returnType, methodName, _1, _2, arg_1, arg_2, arg_3)     \
  returnType methodName(arg_1 a, arg_2 b, arg_3 c) override {                  \
    return registry->get<returnType>(#methodName, a, b, c);                    \
  }

#define MOCK_METHOD_4(returnType, methodName, _1, _2, _3, arg_1, arg_2, arg_3, \
                      arg_4)                                                   \
  returnType methodName(arg_1 a, arg_2 b, arg_3 c, arg_4 d) override {         \
    return registry->get<returnType>(#methodName, a, b, c, d);                 \
  }
#define MOCK_METHOD_5(returnType, methodName, _1, _2, _3, _4, arg_1, arg_2,    \
                      arg_3, arg_4, arg_5)                                     \
  returnType methodName(arg_1 a, arg_2 b, arg_3 c, arg_4 d, arg_5 e)           \
      override {                                                               \
    return registry->get<returnType>(#methodName, a, b, c, d, e);              \
  }

#define MOCK_INTERFACE(interface, ...)                                         \
  class interface##Mock : public interface {                                   \
  public:                                                                      \
    MockRegistry *registry;                                                    \
    interface##Mock() {}                                                       \
    ~interface##Mock() {}                                                      \
    __VA_ARGS__                                                                \
  };                                                                           \
  interface##Mock                                                              \
      interface##Mock##_instance; //this ensures mock implements all interface methods \

// #define MOCK(interface, method) MOCK_N(interface, method, )
// AF(std::get<GET_FUNC_WRAPPER(&interface::method).S>(GET_FUNC_WRAPPER(&interface::method).tuple)...)

#define MOCK_0(interface, method)                                              \
  FUNC_RETURN_TYPE(&interface::method) method() override {                     \
    return registry->get<FUNC_RETURN_TYPE(&interface::method)>(#method);       \
  }

#define MOCK_1(interface, method)                                              \
  FUNC_RETURN_TYPE(&interface::method)                                         \
  method(FUNC_ARGS_N(&interface::method, 0) a) override {                      \
    return registry->get<FUNC_RETURN_TYPE(&interface::method)>(#method, a);    \
  }

#define MOCK_2(interface, method)                                              \
  FUNC_RETURN_TYPE(&interface::method)                                         \
  method(FUNC_ARGS_N(&interface::method, 0) a,                                 \
         FUNC_ARGS_N(&interface::method, 1) b) override {                      \
    return registry->get<FUNC_RETURN_TYPE(&interface::method)>(#method, a, b); \
  }

#define MOCK_3(interface, method)                                              \
  FUNC_RETURN_TYPE(&interface::method)                                         \
  method(FUNC_ARGS_N(&interface::method, 0) a,                                 \
         FUNC_ARGS_N(&interface::method, 1)                                    \
             b.FUNC_ARGS_N(&interface::method, 2) c) override {                \
    return registry->get<FUNC_RETURN_TYPE(&interface::method)>(#method, a, b,  \
                                                               c);             \
  }

#define MOCK_4(interface, method)                                              \
  FUNC_RETURN_TYPE(&interface::method)                                         \
  method(FUNC_ARGS_N(&interface::method, 0) a,                                 \
         FUNC_ARGS_N(&interface::method, 1) b,                                 \
         FUNC_ARGS_N(&interface::method, 2) c,                                 \
         FUNC_ARGS_N(&interface::method, 3) d) override {                      \
    return registry->get<FUNC_RETURN_TYPE(&interface::method)>(#method, a, b,  \
                                                               c, d);          \
  }

// #define MOCK(interface, method) MOCK_N(interface, method,
// GET_FUNC_WRAPPER(&interface::method).Size)
