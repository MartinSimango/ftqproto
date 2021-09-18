
#pragma once 

#include "Mock.hpp"
#include <iostream>

#define MOCKTYPE(mock) std::remove_reference<decltype((mock).getType())>::type

#define FUNC_RETURN_TYPE( func_name ) decltype(createMemberFunctionWrapper( func_name ) )::Type

#define MOCK_FUNC_TYPE(mock, func) FUNC_RETURN_TYPE(&MOCKTYPE(mock)::func) 

#define expectThat(mock, func) expect<MOCKTYPE(mock), MOCK_FUNC_TYPE(mock, func)>(&mock, &MOCKTYPE(mock)::foo, std::string(#func))

#define Verify(mock, func) verify<MOCKTYPE(mock), MOCK_FUNC_TYPE(mock, func)>(&mock, &MOCKTYPE(mock)::foo, std::string(#func))









