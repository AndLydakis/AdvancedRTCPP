//
// Created by andreas on 04/02/2020.
//

#include "Display.h"

void Display::connect(Pipe &pipe_) {
    pipe = &pipe_;
}

void Display::execute() {
    std::cout << "Running Display " << pipe->is_empty() << std::endl;
    while (!pipe->is_empty()) {
        std::cout << "Running Display " << pipe->is_empty() << std::endl;
        auto alarm = pipe->pull();
        std::cout << "Displaying: " << alarm << ":" << alarm.what() << std::endl;
    }
}

void connect(Display &display_, Pipe &pipe_) {
    display_.pipe = &pipe_;
}
