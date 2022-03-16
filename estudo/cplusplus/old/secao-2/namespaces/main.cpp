#include <iostream>

namespace Q {
    namespace V {
        class C
        { 
        public:
            void m(); 
        };
        void f();
    }
 
    void V::f()
    {
        extern void h();
    }
 
    void V::C::m()
    {
        std::cout << "Isso esta em um namespace" << std::endl;
    }
}

int main() {
    Q::V::C c;
    c.m();
}