//
// Created by andreas on 04/02/2020.
//

#ifndef ADVANCEDRTCPP_PIPE_H
#define ADVANCEDRTCPP_PIPE_H

#include "AlarmList.h"
#include <optional>

class Pipe {
    using container_type = AlarmList;
public:
    Pipe() {
        list = new container_type();
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

    container_type get_alarms();
protected:

private:


    container_type *list;
    bool           has_alarm{false};
};


#endif //ADVANCEDRTCPP_PIPE_H
