#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

struct Interactable {
    virtual ~Interactable() = default;

    virtual auto handle_event(sf::Event event) -> bool = 0;
    auto active() -> bool { return m_active; }

    auto deactivate() -> void { m_active = false; }
    auto activate() -> void { m_active = true; }

  protected:
    bool m_active = true;
};
