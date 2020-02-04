//
// Created by andreas on 04/02/2020.
//

#ifndef ADVANCEDRTCPP_PIPE_H
#define ADVANCEDRTCPP_PIPE_H

#include "Alarm.h"
#include "Generator.h"
#include <optional>

class Pipe {
public:
    Pipe() {
        std::cout << "Pipe Default ctor" << std::endl;
    }

    explicit Pipe(Alarm::AlarmType type_) : alarm(type_) {
        std::cout << "PipeAlarm Type ctor" << std::endl;
    }

    std::optional<Alarm> pull();

    void push(Alarm &alarm_);

    void toggle_flag() { has_alarm = !has_alarm; }

    bool is_empty();

private:
    std::optional<Alarm> alarm;
    bool                 has_alarm{false};
};


#endif //ADVANCEDRTCPP_PIPE_H
