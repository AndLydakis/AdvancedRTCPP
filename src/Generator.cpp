//
// Created by andreas on 04/02/2020.
//

#include "Display.h"
#include "Filter.h"

void Generator::connect(Pipe &pipe_) {
    pipe = &pipe_;
}

void Generator::execute(Alarm::AlarmType &type_) {
    Alarm a1{type_};
    pipe->push(a1);
}

void Generator::execute() {
    std::cout << "Generator::execute ";
    for (int i{0}; i < 10; ++i) {
        Alarm a1{static_cast<Alarm::AlarmType>(random() % Alarm::AlarmType::last), "JHFLKJDAHFLDKJSHFLKDSJH"};
        pipe->push(a1);
    }
    std::cout << std::endl;
}

void connect(Generator &generator_, Pipe &pipe_) {
    generator_.pipe = &pipe_;
}
