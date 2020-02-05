//
// Created by andreas on 04/02/2020.
//

#include "Display.h"

void Display::connect(Pipe &pipe_) {
    pipe = &pipe_;
}

void Display::execute() {
    std::cout << "Displaying: " << pipe->pull() << std::endl;
}

void connect(Display &display_, Pipe &pipe_) {
    display_.pipe = &pipe_;
}
