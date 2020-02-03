//
// Created by andreas on 03/02/2020.
//

#include "../include/Alarm.h"

enum alarm_type {
    WARNING,
    CAUTION,
    ADVISORY,
    DEFAULT
};

class Alarm {
public:
    Alarm() {
        std::cout << "Default Constructor" << std::endl;
        type_ = ADVISORY;
    }

    explicit Alarm(alarm_type type_) : type_(type_) {
        std::cout << "Enum constructor" << std::endl;
    }

    const char *as_string() const {

        const char *strings[] = {"WARNING", "CAUTION", "ADVISORY", "DEFAULT"};
        return strings[type()];
    }

    alarm_type type() const {
        return type_;
    }

private:
    alarm_type type_;
};

std::ostream &operator<<(std::ostream &os, Alarm alarm) {
    os << "Alarm: " << alarm.as_string();
    return os;
}
