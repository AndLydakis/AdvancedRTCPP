//
// Created by andreas on 06/02/2020.
//

#include "AlarmFilter.h"

void connect(AlarmFilter &filter, Pipe &input_pipe, Pipe &output_pipe) {
    std::cout << "Connecting filter with pipes" << std::endl;
    filter.input  = &input_pipe;
    filter.output = &output_pipe;
}

void AlarmFilter::execute() {
    std::cout << "old alarms:" << std::endl;
    std::cout << "Allowed alarms: " << filter_value << std::endl;
    auto      alarms = input->get_alarms();
    for (auto &f :alarms) { std::cout << f; }
    std::cout << std::endl;
    std::vector<Alarm> dest;

//    auto allowed = [this](Alarm alarm) { return alarm.type() == this->filter_value; };
    auto allowed = [this](Alarm alarm) { return true; };
    std::copy_if(alarms.begin(), alarms.end(), std::back_inserter(dest), allowed);

    std::cout << "filtered alarms:" << std::endl;
    for (auto &f: dest) std::cout << f << " ";
    std::cout << std::endl;
    for (Alarm f:dest) {
        std::cout << "Filter Pushing " << f.as_string() << std::endl;
        output->push(f);
    }
}