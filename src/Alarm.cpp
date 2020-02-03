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

    const char *as_string() {
        switch (type()) {
            case WARNING   :
                return "WARNING";
            case ADVISORY:
                return "ADVISORY";
            case CAUTION :
                return "CAUTION";
            case DEFAULT :
                return "DEFAULT";
            default    :
                return "UNKNOWN";
        }
    }

    alarm_type type() {
        return type_;
    }

private:
    alarm_type type_;
};

std::ostream &operator<<(std::ostream &os, Alarm alarm) {
    os << "Alarm: ";
    switch (alarm.type()) {
        case WARNING   :
            os << "WARNING";
            break;
        case ADVISORY:
            os << "ADVISORY";
            break;
        case CAUTION :
            os << "CAUTION";
            break;
        case DEFAULT :
            os << "DEFAULT";
            break;
        default    :
            os.setstate(std::ios_base::failbit);
    }
    return os;
}