#pragma once

#include "AssetManager.hpp"
#include "Interactables/Button.hpp"
#include "Interactables/Dropdown.hpp"
#include "Interactables/Interactable.hpp"
#include "Interactables/Manager.hpp"
#include "WindowAPI.hpp"
#include <SFML/Graphics.hpp>


class TitleBar {
  public:
    TitleBar(WindowAPI *window);
    ~TitleBar() = default;

    auto set_title(const char *) -> void;

  private:
    sf::RectangleShape rect;
    Dropdown file;

    Button close;
    Button minimize;
};
