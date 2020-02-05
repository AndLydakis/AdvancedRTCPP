//
// Created by andreas on 04/02/2020.
//

#ifndef ADVANCEDRTCPP_PIPE_H
#define ADVANCEDRTCPP_PIPE_H

#include "AlarmList.h"
#include <optional>

class Pipe {
public:
    Pipe() {
        list = new AlarmList();
        std::cout << "Pipe Default ctor" << std::endl;
    }

    explicit Pipe(Alarm::AlarmType type_) {
        list->emplace(type_);
        std::cout << "PipeAlarm Type ctor" << std::endl;
    }

    Alarm pull();

    void push(Alarm &alarm_);

    void toggle_flag() { has_alarm = !has_alarm; }

    bool is_empty();

private:
    AlarmList *list;
    bool      has_alarm{false};
};


#endif //ADVANCEDRTCPP_PIPE_H
