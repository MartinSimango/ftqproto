#pragma once
#include <type_traits>
#include <typeinfo>
#include "Mock.hpp"
#include <vector>

#define FUNC_ARGS(args...) args



#define MOCK_METHOD(returnType, methodName, arg_1)  returnType methodName(arg_1 a) override { \
    return registry->get<returnType>(#methodName, a);                \
} \

#define MOCK_METHOD_2(returnType,methodName,arg_1,arg_2) returnType methodName(arg_1 a, arg_2 b) override { \
    return registry->get<returnType>(#methodName, a,b);                \
} \

#define MOCK_METHOD_3(returnType, methodName, arg_1, arg_2, arg_3) returnType methodName(arg_1 a, arg_2 b, arg_3 c) override { \
    return registry->get<returnType>(#methodName, a,b,c);                                                                      \
}

#define MOCK_METHOD_4(returnType, methodName, arg_1, arg_2, arg_3, arg_4) returnType methodName(arg_1 a, arg_2 b, arg_3 c, arg_4 d) override { \
    return registry->get<returnType>(#methodName, a,b,c,d);                \
} 
#define MOCK_METHOD_5(returnType, methodName, arg_1, arg_2, arg_3, arg_4, arg_5) returnType methodName(arg_1 a, arg_2 b, arg_3 c, arg_4 d, arg_5 e) override { \
    return registry->get<returnType>(#methodName, a,b,c,d,e);                \
} 


#define MOCK_TYPE(type) decltype(type)##Mock

struct SomeInterface
{
    /* data */
    virtual int foo(int a, int b) = 0;
    virtual int boo(int a) = 0;
};

class MockRegistry {
    private:
    std::vector<std::string> methodNames;
    std::vector<std::vector<void*>> methodArgs;
    std::vector<void *> returns;


    int getMethodIndex(std::string methodName) {
        int i = 0;
        for (std::string mn: methodNames) {
            if (mn == methodName){
                return i;
            }
            i++;
        }
        return -1;
    }

    public:
        void addMethodName(std::string name) {
            methodNames.push_back(name);
        }

        template<typename ...Args>
        void addMethodArgs(Args... args) {
            std::vector<void *> types;
            for(auto p : {args...}) {
                decltype(p) *t = new decltype(p)(p);
                // std::cout << "Value is: " << *t << std::endl;
                types.push_back((void *)t);
            }
                
            methodArgs.push_back(types);
        }

        void addReturnValues(void * value){
            returns.push_back(value);
        }

        template<typename T, typename ...Args> 
        T get(std::string methodName, Args... args) {

            int i = getMethodIndex(methodName);

            if (i == -1) {
                std::cout << "No method mock found" <<std::endl;
                throw std::exception();
            }
            if (returns.size() <= i || methodArgs.size() <= i) {
                std::cout << "Method was not mocked with a return value" <<std::endl;
                throw std::exception();
            }
            return *reinterpret_cast<T*>(returns.at(i));
              
     
        }

        template<typename ...Args>
        bool wasCalledWith(std::string methodName, Args... args) {
            int index = getMethodIndex(methodName);
            
            std::vector<void*> arguments = methodArgs.at(index);
            int i = 0;
            for(auto p : {args...}) {
                decltype(p) value = *reinterpret_cast<decltype(p)*>(arguments.at(i));
                // std::cout << "Comparing " << p << " with " << value << std::endl;
                if (p != value) {
                    return false;
                }
                i++;
            }

            return true;        
        }

       
   
};


template<typename Type>
class Mock {


    public:
    MockRegistry registry;
    Type instance;
   


    Mock(){
        instance.registry = &registry;
        
    }

    Type getType() {
        return Type();
    }
    

    Type& get() {
        return instance;
    }

     void addMethodName(std::string name) {
         registry.addMethodName(name);
     }

    template<typename ...Args>
    void addMethodArgs(Args... args) {
        registry.addMethodArgs(std::forward<Args>(args)...);
    }

    void addReturnValues(void * value){
        registry.addReturnValues(value);
    }

    template<typename ...Args>
    bool wasCalledWith(std::string methodName, Args... args) {
        return registry.wasCalledWith(methodName, std::forward<Args>(args)...);
    }
    
};



#define MOCK_INTERFACE(interface, ...) \
class interface##Mock : public interface { \
    private:            \
    public:  \
    MockRegistry *registry;                            \
    interface##Mock() { \
                      \
    }  \
    __VA_ARGS__  \
     \
};  \
interface##Mock instance; \

MOCK_INTERFACE(SomeInterface,
    MOCK_METHOD_2(int, foo, int, int)
    MOCK_METHOD(int, boo, int)
)


// Below function inspired from: https://www.py4u.net/discuss/76093

template <typename ReturnType, typename Object, typename ...Args> 
class MemberFunctionWrapper
{
    typedef ReturnType (Object::*FuncPtr)(Args...);
public:
    typedef ReturnType Type;
};

template <typename ReturnType, typename Object, typename ...Args> 
inline MemberFunctionWrapper<ReturnType, Object, Args...> createMemberFunctionWrapper(ReturnType (Object::*FuncPtr )(Args...))
{
    return MemberFunctionWrapper<ReturnType, Object, Args...>();
}


template<typename MockObject, typename Retval>
class WillReturn {
    private:
    Mock<MockObject> *mock;

    public:
    WillReturn(Mock<MockObject> *mock) : mock(mock) {}
    void willReturn(Retval value) { 
        Retval * val = new Retval(value);
        this->mock->addReturnValues((void *) val);
    }

};

template<typename MockObject, typename Retval, typename ...Args>
class With {

   private:
   Mock<MockObject> *mock;

   public:

   With(Mock<MockObject> *mock) : mock(mock) {}

   WillReturn<MockObject, Retval> with(Args... args) {
            mock->addMethodArgs(std::forward<Args>(args)...);
            return WillReturn<MockObject, Retval>(mock);
        
    }

};

template<typename MockObject, typename Retval, typename ...Args>
class WasCalledWith {

    private:
    Mock<MockObject> *mock;
    std::string methodName;

    public:
    
    WasCalledWith(Mock<MockObject> * mock, std::string methodName) : mock(mock), methodName(methodName) {}

    bool wasCalledWith(Args... args) {
        return mock->wasCalledWith(methodName, std::forward<Args>(args)...);
    }

};


template<typename Object, typename Retval, typename ...Args>
With<Object, Retval, Args...> expect(Mock<Object> *mock, Retval(Object::*func)(Args...), std::string methodName) {
        mock->addMethodName(methodName);
        return With<Object,Retval, Args...>(mock);
}

template<typename Object, typename Retval, typename ...Args>
WasCalledWith<Object, Retval, Args...> verify(Mock<Object> *mock, Retval(Object::*func)(Args...), std::string methodName) {
        return WasCalledWith<Object,Retval, Args...>(mock, methodName);
        
}