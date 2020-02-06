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

    explicit Alarm(AlarmType);

//    Alarm(const Alarm &alarm);

    Alarm(const Alarm &alarm, const char *description);

    Alarm(const Alarm &alarm);

    // move constructor
    Alarm(Alarm &&alarm) noexcept;

    Alarm(Alarm::AlarmType type_, const char *description_);

    AlarmType type() const;

    const char *as_string() const;

    const char *what() const;

    Alarm &operator=(Alarm alarm_);

    friend void swap(Alarm &lhs, Alarm &rhs);

private:
    char      *description{nullptr};
    AlarmType m_type;
};

std::ostream &operator<<(std::ostream &os, Alarm alarm);

#endif //ADVANCEDRTCPP_ALARM_H
