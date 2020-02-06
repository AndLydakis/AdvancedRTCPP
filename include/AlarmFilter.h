//
// Created by andreas on 06/02/2020.
//

#ifndef ADVANCEDRTCPP_ALARMFILTER_H
#define ADVANCEDRTCPP_ALARMFILTER_H

#include "Filter.h"
#include "Pipe.h"
#include "AlarmList.h"
#include <set>
#include <algorithm>

class AlarmFilter : public Filter {
public:

    AlarmFilter() {
        std::cout << "AlarmFilter::ctor" << std::endl;
    }

    AlarmFilter(Alarm::AlarmType &val) : filter_value(val) {
        std::cout << "AlarmFilter::val ctor" << std::endl;
    }

    bool add(Alarm::AlarmType type_) {
        filter_value = type_;
        return true;
    }

    AlarmList filter();

    friend void connect(AlarmFilter &filter, Pipe &input_pipe, Pipe &output_pipe);

    void execute() override;

private:
    Alarm::AlarmType filter_value;
//    std::set<Alarm::AlarmType> allowed_alarms{};
    Pipe             *input{nullptr};
    Pipe             *output{nullptr};
};


#endif //ADVANCEDRTCPP_ALARMFILTER_H
