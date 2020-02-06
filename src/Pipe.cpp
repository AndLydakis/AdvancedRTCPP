//
// Created by andreas on 04/02/2020.
//

#include "Pipe.h"

void Pipe::push(Alarm &alarm_) {
    std::cout << "Pushing " << alarm_.as_string() << ":" << alarm_.what() << std::endl;
    list->add(alarm_);
}

Alarm Pipe::pull() {
    std::cout << "Alarms remaining in pipe: " << list->size() << std::endl;
    Alarm alarm = *list->begin();
    list->erase(list->begin(), list->begin() + 1);
    std::cout << "Pulled " << alarm.as_string() << ":" << alarm.what() << std::endl;
    return alarm;
}

bool Pipe::is_empty() {
    return list->size() <= 0;
}

Pipe::container_type Pipe::get_alarms() {
    return *list;
}
