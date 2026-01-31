#include "src/Window.h"

#include <iostream>

int main() {
    vcgb::Window window("VCGB Boilerplate", 400, 200);

    while (!window.shouldClose()) {
        window.update();
    }
    return 0;
}