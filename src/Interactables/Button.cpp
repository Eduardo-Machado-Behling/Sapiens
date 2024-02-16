#include "Interactables/Button.hpp"

Button::Button() {
    m_hitbox.setFillColor(sf::Color::Transparent);
    m_hitbox.setOutlineColor(sf::Color::Transparent);
}

auto Button::handle_event(sf::Event event) -> bool {
    if (event.type == sf::Event::EventType::MouseMoved) {
        if (m_hitbox.getGlobalBounds().contains(event.mouseMove.x, event.mouseMove.y)) {
            if (m_on_enter && !entered) {
                m_on_enter(this);
                entered = true;
            }
        } else {
            if (m_on_leave && entered) {
                m_on_leave(this);
                entered = false;
            }
        }
    } else if (event.type == sf::Event::EventType::MouseButtonPressed) {
        if (m_hitbox.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
            if (m_on_click && event.mouseButton.button == sf::Mouse::Left) {
                m_on_click();
            }
        }
    }

    return false;
}
auto Button::draw(sf::RenderTarget &target, sf::RenderStates states) const -> void {
    target.draw(m_hitbox);

    if (m_shape)
        target.draw(*m_shape.get());
}

auto Button::setDrawable(sf::Drawable *drawable) -> void { m_shape.reset(drawable); }

auto Button::setHitbox(sf::FloatRect rect) -> void {
    m_hitbox.setPosition(rect.left, rect.top);
    m_hitbox.setSize({rect.width, rect.height});
}
auto Button::getHitbox() -> sf::RectangleShape & { return m_hitbox; }

auto Button::onClick(std::function<void()> callback) -> void { m_on_click = callback; }
auto Button::onEnter(std::function<void(Button *)> callback) -> void { m_on_enter = callback; }
auto Button::onLeave(std::function<void(Button *)> callback) -> void { m_on_leave = callback; }
