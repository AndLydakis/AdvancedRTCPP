#include "Pipeline.h"
#include "Filter.h"
#include "AlarmList.h"

int main() {


    Pipeline pipeline_{};
    for (int i{0}; i < 3; ++i) {
        std::cout << "Creating Pipe" << std::endl;
        Pipe p1{};
        std::cout << "Creating Display" << std::endl;
        Display d1{};
        std::cout << "Creating Generator" << std::endl;
        Generator g1{};
        std::cout << "Created Generator" << std::endl;
        std::cout << "Pipe has data: " << p1.is_empty() << std::endl;
        std::cout << "Connecting Pipe to Generator" << std::endl;
        connect(g1, p1);
        std::cout << "Connecting Display to Generator" << std::endl;
        connect(d1, p1);
        pipeline_.add(g1);
        pipeline_.add(d1);
        std::cout << "-----------------" << std::endl;
    }
    pipeline_.run();

    /**
    for (int i{0}; i < 3; ++i) {
        std::cout << "Creating Pipe" << std::endl;
        Pipe p1{};
        std::cout << "Creating Display" << std::endl;
        Display d1{};
        std::cout << "Creating Generator" << std::endl;
        Generator g1{};
        std::cout << "Pipe has data: " << p1.is_empty() << std::endl;
        std::cout << "Connecting Pipe to Generator" << std::endl;
        connect(g1, p1);
        std::cout << "Connecting Display to Generator" << std::endl;
        connect(d1, p1);
        g1.execute();
        std::cout << "Pipe has data: " << p1.is_empty() << std::endl;
        d1.execute();
        std::cout << "------------------------------------" << std::endl;
    }
     **/
    return EXIT_SUCCESS;
}
