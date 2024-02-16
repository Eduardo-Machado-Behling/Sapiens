#include "Window.hpp"

Window::Window(sf::Vector2u window_size)
    : window(sf::VideoMode(window_size.x, window_size.y), "Sapiens", sf::Style::None), window_size(window_size), title_bar(this){};

auto Window::active() -> bool { return window.isOpen(); }

auto Window::mainloop() -> void {
    window.clear(sf::Color::White);
    for (auto it = m_drawables.begin(); it != m_drawables.end(); it++)
        window.draw(**it);
    window.display();

    sf::Event event;
    while (window.pollEvent(event)) {
        for (auto it = m_interactables.begin(); it != m_interactables.end(); it++) {
            if ((*it)->active())
                (*it)->handle_event(event);
        }

        // "close requested" event: we close the window
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

auto Window::close() -> void { window.close(); }
auto Window::get_size() -> sf::Vector2u { return this->window_size; }