//
// Created by andreas on 04/02/2020.
//

#include "Pipe.h"

void Pipe::push(Alarm &alarm_) {
    std::cout << "Pushing " << alarm_ << std::endl;
    alarm = std::optional<Alarm>{alarm_};
}

std::optional<Alarm> Pipe::pull() {
    if (alarm.has_value()) {
        return alarm;
    } else {
        return std::optional<Alarm>{};
    }
}

bool Pipe::is_empty() {
    return alarm.has_value();
}