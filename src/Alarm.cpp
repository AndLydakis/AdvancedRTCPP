//
// Created by andreas on 03/02/2020.
//

#include <cstring>
#include "Alarm.h"


Alarm::Alarm() {
    std::cout << "Default Constructor" << std::endl;
    m_type = ADVISORY;
}

Alarm::Alarm(Alarm::AlarmType type_) : m_type(type_) {
    std::cout << "Enum constructor" << std::endl;
}

Alarm::Alarm(const Alarm &alarm, const char *description_) {
    std::cout << "Alarm::copy-ctor with description" << std::endl;
    m_type = alarm.type();
    std::cout << "Type: " << m_type << std::endl;
    std::cout << "Description: " << std::endl;
    std::cout << description_ << std::endl;
    if (description_) {
        std::cout << "Allocating space" << std::endl;
        description = new char[(strlen(description_) + 1)];
        strcpy(description, description_);
    }
    std::cout << "**" << what() << std::endl;
}

Alarm::Alarm(const Alarm &alarm) {
    std::cout << "Alarm::copy-ctor" << std::endl;
    m_type = alarm.type();
    std::cout << "Type: " << m_type << std::endl;
    if (alarm.description) {
        description = new char[(strlen(alarm.description) + 1)];
        strcpy(description, alarm.description);
    }
    std::cout << "**" << what() << std::endl;
}

const char *Alarm::as_string() const {

    const char *strings[] = {"WARNING", "CAUTION", "ADVISORY", "DEFAULT"};
    return strings[m_type];
}

Alarm::AlarmType Alarm::type() const {
    return m_type;
}

Alarm &Alarm::operator=(Alarm alarm_) {
    swap(*this, alarm_);
    return *this;

}

void swap(Alarm &lhs, Alarm &rhs) { // Swap each attribute in order
    using std::swap;
    swap(lhs.m_type, rhs.m_type);
    swap(lhs.description, rhs.description);
}

const char *Alarm::what() const {
    return description;
}

std::ostream &operator<<(std::ostream &os, Alarm alarm) {
    os << "Alarm: " << alarm.as_string();
    return os;
}