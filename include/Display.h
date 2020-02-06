//
// Created by andreas on 04/02/2020.
//

#ifndef ADVANCEDRTCPP_DISPLAY_H
#define ADVANCEDRTCPP_DISPLAY_H

#include "Pipe.h"
#include "AlarmList.h"
#include "Filter.h"
#include <optional>

class Display : public Filter {
public:
    Display() {
        std::cout << "Display Default ctor" << std::endl;
    }

    friend void connect(Display &display_, Pipe &pipe_);

    void connect(Pipe &pipe_);

    void execute() override;

private:
    Pipe *pipe{nullptr};
};

class Generator : public Filter {
public:
    Generator() {
        std::cout << "Generator default ctor" << std::endl;
    }

    friend void connect(Generator &generator_, Pipe &pipe_);

    void connect(Pipe &pipe_);

    void execute(Alarm::AlarmType &type_);

    void execute() override;

private:
    Pipe *pipe{nullptr};
};

#endif //ADVANCEDRTCPP_DISPLAY_H
