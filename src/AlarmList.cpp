//
// Created by andreas on 05/02/2020.
//

#include "AlarmList.h"

void AlarmList::add(Alarm &in_val) {
    alarm_list.push_back(in_val);
}

void AlarmList::emplace(Alarm::AlarmType type) {
    alarm_list.emplace_back(type);
}

std::size_t AlarmList::size() const {
    return alarm_list.size();
}

AlarmList::Iterator AlarmList::begin() {
    return alarm_list.begin();
}

AlarmList::Iterator AlarmList::end() {
    return --alarm_list.end();
}

void AlarmList::reserve(const std::size_t sz) {
    alarm_list.reserve(sz);
}

void AlarmList::erase(const Iterator &from, const Iterator &to) {
    std::cout << "AlarmList::erase" << std::endl;
    alarm_list.erase(from, to);
}

void AlarmList::emplace(Alarm::AlarmType type, const char *desc) {
    alarm_list.emplace_back(type, desc);
}

