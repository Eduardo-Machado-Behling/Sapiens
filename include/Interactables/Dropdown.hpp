#include "Interactables/Button.hpp"
#include "WindowAPI.hpp"

class Dropdown : public sf::Drawable {
  public:
    Dropdown(float width);

    auto draw(sf::RenderTarget &target, sf::RenderStates states) const -> void override;
    auto update() -> void;

    auto setParent(Button *button) -> void;
    auto getParent() -> Button &;

    auto addChild(const char *name, const char *shortcut, Button *child) -> void;
    auto register_childs(WindowAPI *win) -> void;

    auto getDropdownBG() -> sf::RectangleShape &;

  private:
    struct ChildGraph : public sf::Drawable {
        ChildGraph(const char *name, const char *shortcut, sf::FloatRect dropdown_rect);

        auto draw(sf::RenderTarget &target, sf::RenderStates states) const -> void override;

        sf::Text name, shortcut;
    };
    std::unique_ptr<Button> m_parent;
    std::vector<std::unique_ptr<Button>> m_childs;

    sf::RectangleShape m_dropdown_bg;
    bool show_child = false;
};
