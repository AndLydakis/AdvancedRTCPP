#include "Pipeline.h"
#include "AlarmFilter.h"
#include "AlarmList.h"

int main() {

    int runs{1};

    Pipeline pipeline_{};
    for (int i{0}; i < runs; ++i) {
        std::cout << "Creating Pipe 1" << std::endl;
        Pipe p1{};
        std::cout << "Creating Pipe 2" << std::endl;
        Pipe p2{};
        std::cout << "Creating Display" << std::endl;
        Display d1{};
        std::cout << "Creating Generator" << std::endl;
        Generator g1{};
        std::cout << "Creating Alarm Filter" << std::endl;
        auto        type_ = Alarm::AlarmType::WARNING;
        AlarmFilter af1{type_};
        af1.add(Alarm::AlarmType::WARNING);
        std::cout << "Pipe has data: " << p1.is_empty() << std::endl;
        std::cout << "Connecting Alarm Filter to Pipes" << std::endl;
        connect(af1, p1, p2);
        std::cout << "Connecting Pipe to Generator" << std::endl;
        connect(g1, p1);
        std::cout << "Connecting Display to Generator" << std::endl;
        connect(d1, p2);
        std::cout << "Adding Filters to Pipeline" << std::endl;
        pipeline_.add(g1);
        pipeline_.add(af1);
        pipeline_.add(d1);
        std::cout << "-----------------" << std::endl;
    }
    pipeline_.run();
    return EXIT_SUCCESS;
}
