//
// Created by andreas on 03/02/2020.
//

#include "../include/Alarm.h"



Alarm::Alarm() {
    std::cout << "Default Constructor" << std::endl;
    m_type = ADVISORY;
}

Alarm::Alarm(Alarm::AlarmType type_) : m_type(type_) {
    std::cout << "Enum constructor" << std::endl;
}

const char *Alarm::as_string() const {

    const char *strings[] = {"WARNING", "CAUTION", "ADVISORY", "DEFAULT"};
    return strings[m_type];
}

Alarm::AlarmType Alarm::type() const {
    return m_type;
}

std::ostream &operator<<(std::ostream &os, Alarm alarm) {
    os << "Alarm: " << alarm.as_string();
    return os;
}
