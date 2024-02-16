#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

struct DrawableManager {
    virtual ~DrawableManager() = default;

    virtual auto register_drawable(sf::Drawable *drawable) -> void { m_drawables.push_back(drawable); }

  protected:
    std::vector<sf::Drawable *> m_drawables;
};
