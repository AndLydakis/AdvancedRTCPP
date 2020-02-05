//
// Created by andreas on 05/02/2020.
//

#include "Pipeline.h"

void Pipeline::add(Filter &filter_) {
    filters.emplace_back(&filter_);
}

void Pipeline::run() {
    for (auto filter : filters) {
        filter->execute();
    }
}