#include "sim_8051.hpp"

#include <iostream>

int main(int argc, char* argv[])
{
    model_0c8051 model;

    // Initialize rom

    // Initialize states

    // Start runing
    for (int i=0; i<10; i++) {
        model.update();
    }

    return 0;
}
