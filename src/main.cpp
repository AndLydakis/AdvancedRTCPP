#include <iostream>
#include "Alarm.cpp"
#include "Display.cpp"
#include "Pipe.cpp"
#include "Generator.cpp"

int        init_glob{2};
int        uninit_glob;
int        zinit_glob{};
const int  const_glob{0};
static int static_glob;

void ex3();


int main() {
    for (int i{0}; i < 3; ++i) {
        std::cout << "Creating Pipe" << std::endl;
        Pipe p1{};
        std::cout << "Creating Display" << std::endl;
        Display d1{};
        std::cout << "Creating Generator" << std::endl;
        Generator g1{};
        std::cout << "Pipe has data: " << p1.is_empty() << std::endl;
        std::cout << "Connecting Pipe to Generator" << std::endl;
        g1.connect(p1);
        std::cout << "Connecting Display to Generator" << std::endl;
        d1.connect(p1);
//        Alarm::AlarmType caution{Alarm::AlarmType::CAUTION};
        g1.execute();
        std::cout << "Pipe has data: " << p1.is_empty() << std::endl;
        d1.execute();
        std::cout << "------------------------------------" << std::endl;
    }
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
//    std::cout << "Static Auto: " << &static_auto << std::endl;
//    std::cout << "Main: " << &main << std::endl;
    std::cout << "cast Main: " << reinterpret_cast<int *>(&main) << std::endl;
}

