//
// Created by andreas on 05/02/2020.
//

#ifndef ADVANCEDRTCPP_PIPELINE_H
#define ADVANCEDRTCPP_PIPELINE_H

#include "Filter.h"
#include "Display.h"
#include <vector>

class Pipeline {
public:
    Pipeline() = default;

    void add(Filter &);

    void run();


private:
    std::vector<Filter *> filters{};
};


#endif //ADVANCEDRTCPP_PIPELINE_H
