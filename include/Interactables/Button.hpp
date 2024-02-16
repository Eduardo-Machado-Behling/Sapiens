#pragma once

#include "Interactables/Interactable.hpp"
#include <functional>
#include <memory>

class Button : public Interactable, public sf::Drawable {
  public:
    Button();

    auto handle_event(sf::Event event) -> bool override;
    auto draw(sf::RenderTarget &target, sf::RenderStates states) const -> void override;

    auto setDrawable(sf::Drawable *drawable) -> void;

    auto setHitbox(sf::FloatRect rect) -> void;
    auto getHitbox() -> sf::RectangleShape &;

    auto onClick(std::function<void()> callback) -> void;
    auto onEnter(std::function<void(Button *)> callback) -> void;
    auto onLeave(std::function<void(Button *)> callback) -> void;

  private:
    std::unique_ptr<sf::Drawable> m_shape;
    std::function<void()> m_on_click;
    std::function<void(Button *)> m_on_enter;
    std::function<void(Button *)> m_on_leave;
    sf::RectangleShape m_hitbox;

    bool entered = false;
};