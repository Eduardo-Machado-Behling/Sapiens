#pragma once

#include "DrawableManager.hpp"
#include "Interactables/Manager.hpp"

struct WindowAPI : public InteractableManager, public DrawableManager {
    virtual ~WindowAPI() = default;

    virtual auto close() -> void = 0;
    virtual auto get_size() -> sf::Vector2u = 0;
};
