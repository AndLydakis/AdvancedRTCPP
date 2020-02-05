//
// Created by andreas on 04/02/2020.
//

#include "Pipe.h"

void Pipe::push(Alarm &alarm_) {
    std::cout << "Pushing " << alarm_ << std::endl;
    list->add(alarm_);
}

Alarm Pipe::pull() {
    Alarm alarm = *list->end();
    list->erase(--list->end(), list->end());
    return alarm;
}

bool Pipe::is_empty() {
    return list->size() > 0;
}