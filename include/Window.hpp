#pragma once

#include "Interactables/Manager.hpp"
#include "WindowAPI.hpp"
#include <SFML/Window.hpp>
#include <TitleBar.hpp>

class Window : public WindowAPI {
  public:
    Window(sf::Vector2u window_size);

    auto active() -> bool;
    auto mainloop() -> void;

    auto close() -> void override;
    auto get_size() -> sf::Vector2u override;

  private:
    auto handle_event() -> void;

    sf::RenderWindow window;
    sf::Vector2u window_size;

    TitleBar title_bar;
};