#include <iostream>
#include "Alarm.cpp"

int        init_glob{2};
int        uninit_glob;
int        zinit_glob{};
const int  const_glob{0};
static int static_glob;

void ex3();


int main() {
    Alarm a1;
    std::cout << "a1: " << a1.as_string() << " " << a1.type() << " " << a1 << std::endl;
    Alarm a2{};
    std::cout << "a2: " << a2.as_string() << " " << a2.type() << " " << a2 << std::endl;
    Alarm a3{WARNING};
    std::cout << "a3: " << a3.as_string() << " " << a3.type() << " " << a3 << std::endl;
}

void ex3() {
    auto        auto_{0};
    static auto static_auto{0};
    std::cout << "Initialized global: " << &init_glob << std::endl;
    std::cout << "Uninitialized global: " << &uninit_glob << std::endl;
    std::cout << "0-initialized global: " << &zinit_glob << std::endl;
    std::cout << "Constant global: " << &const_glob << std::endl;
    std::cout << "Static global: " << &static_glob << std::endl;
    std::cout << "Auto: " << &auto_ << std::endl;
    std::cout << "Static Auto: " << &static_auto << std::endl;
    std::cout << "Main: " << &main << std::endl;
    std::cout << "cast Main: " << reinterpret_cast<int *>(&main) << std::endl;
}

