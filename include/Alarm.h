//
// Created by andreas on 03/02/2020.
//

#ifndef ADVANCEDRTCPP_ALARM_H
#define ADVANCEDRTCPP_ALARM_H

#include <iostream>

class Alarm {

public:

    enum AlarmType {
        WARNING,
        CAUTION,
        ADVISORY,
        DEFAULT,
        last
    };

    Alarm();

    Alarm(AlarmType);

    AlarmType type() const;

    const char *as_string() const;

private:
    AlarmType m_type;
};

std::ostream &operator<<(std::ostream &os, Alarm alarm);

#endif //ADVANCEDRTCPP_ALARM_H
