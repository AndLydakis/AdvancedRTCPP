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
    std::cout << "Allowed alarms: " << filter_value << std::endl;
    std::cout << "old alarms:" << std::endl;
    auto      alarms = input->get_alarms();
    for (auto &f :alarms) { std::cout << f.as_string(); }
    std::cout << std::endl;
    std::vector<Alarm> dest;

    auto allowed = [this](Alarm alarm) { return true; };
//    auto allowed = [this](Alarm alarm) { return alarm.type() == this->filter_value;; };
    std::copy_if(alarms.begin(), alarms.end(), std::back_inserter(dest), allowed);


    std::cout << "Filtered  Alarms:" << std::endl;
    AlarmList l{};
    for (auto &f: dest) {
        std::cout << f.as_string() << " ";
        l.add(f);
    }
    output->push(l);
    std::cout << std::endl;

}