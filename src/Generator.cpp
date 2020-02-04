//
// Created by andreas on 04/02/2020.
//

#include "../include/Pipe.h"

void Generator::connect(Pipe &pipe_) {
    pipe = &pipe_;
}

void Generator::execute(Alarm::AlarmType &type_) {
    Alarm a1{type_};
    pipe->push(a1);
}

void Generator::execute() {
    Alarm a1{static_cast<Alarm::AlarmType>(rand() % Alarm::AlarmType::last)};
    pipe->push(a1);
}
