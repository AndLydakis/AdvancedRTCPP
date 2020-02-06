//
// Created by andreas on 05/02/2020.
//

#ifndef ADVANCEDRTCPP_ALARMLIST_H
#define ADVANCEDRTCPP_ALARMLIST_H

#include "Alarm.h"
#include<vector>

class AlarmList {
public:
    using Container  = std::vector<Alarm>;
    using Iterator   = Container::iterator;
    using value_type = Container::value_type;
    using size_type  = Container::size_type;

    void add(Alarm &in_val);

    void emplace(Alarm::AlarmType type);
    void emplace(Alarm::AlarmType type, const char* description);

    void erase(const Iterator &from, const Iterator &to);

    void reserve(size_t sz);

    size_type size() const;

    Iterator begin();

    Iterator end();

private:
    Container alarm_list{};
};


#endif //ADVANCEDRTCPP_ALARMLIST_H
