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

    Alarm(const Alarm &alarm, const char *description);

    AlarmType type() const;

    const char *as_string() const;

    const char *what() const;

    ~Alarm() { std::cout << "Alarm::dtor" << std::endl; }

    Alarm &operator=(Alarm alarm_);

    friend void swap(Alarm &lhs, Alarm &rhs);

private:
    char *description{nullptr};
    AlarmType  m_type;
};

std::ostream &operator<<(std::ostream &os, Alarm alarm);

#endif //ADVANCEDRTCPP_ALARM_H
