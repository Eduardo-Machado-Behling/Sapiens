#include "Interactable.hpp"
#include <SFML/Graphics.hpp>

struct Tab : sf::Drawable {
    virtual ~Tab() = default;

    virtual auto draw(sf::RenderTarget &target, const sf::RenderStates &states) const -> void = 0;
    virtual auto handle_event(sf::Event event) -> bool = 0;
};
