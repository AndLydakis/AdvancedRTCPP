//
// Created by andreas on 05/02/2020.
//

#ifndef ADVANCEDRTCPP_PIPELINE_H
#define ADVANCEDRTCPP_PIPELINE_H

#include "Filter.h"
#include "Display.h"
#include <vector>
#include <initializer_list>

class Pipeline {
public:
    Pipeline() = default;

    Pipeline(std::initializer_list<Filter *> list_) : filters(list_) {};

    void add(Filter &);

    void run();


private:
    std::vector<Filter *> filters{};
};


#endif //ADVANCEDRTCPP_PIPELINE_H
