//
// Created by andreas on 04/02/2020.
//

#ifndef ADVANCEDRTCPP_DISPLAY_H
#define ADVANCEDRTCPP_DISPLAY_H

#include "Pipe.h"
#include <optional>

class Display {
public:
    Display() {
        std::cout << "Display Default ctor" << std::endl;
    }

    friend void connect(Display &display_, Pipe &pipe_);

    void connect(Pipe &pipe_);

    void execute();

private:
    Pipe *pipe{nullptr};
};

class Generator {
public:
    Generator() {
        std::cout << "Generator default ctor" << std::endl;
    }

    friend void connect(Generator &generator_, Pipe &pipe_);

    void connect(Pipe &pipe_);

    void execute(Alarm::AlarmType &type_);

    void execute();

private:
    Pipe *pipe{nullptr};
};

#endif //ADVANCEDRTCPP_DISPLAY_H
