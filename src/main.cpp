#include "Window.hpp"

int main() {
    Window window({1440, 1000});

    while (window.active())
        window.mainloop();
}