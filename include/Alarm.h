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

    Alarm(const Alarm &alarm);

    AlarmType type() const;

    const char *as_string() const;

    ~Alarm() { std::cout << "Alarm::dtor" << std::endl; }

    Alarm &operator=(const Alarm &alarm_);

private:
    AlarmType m_type;
};

std::ostream &operator<<(std::ostream &os, Alarm alarm);

#endif //ADVANCEDRTCPP_ALARM_H
