#include "Interactables/Dropdown.hpp"
#include "AssetManager.hpp"

Dropdown::Dropdown(float width) { m_dropdown_bg.setSize({width, 5}); }

auto Dropdown::update() -> void {
    for (auto it = m_childs.begin(); it < m_childs.end(); it++) {
        if (show_child)
            (*it)->activate();
        else
            (*it)->deactivate();
    }
}
auto Dropdown::draw(sf::RenderTarget &target, sf::RenderStates states) const -> void {
    target.draw(*m_parent);
    if (show_child) {
        target.draw(m_dropdown_bg);
        for (auto it = m_childs.begin(); it != m_childs.end(); it++) {
            target.draw(**it);
        }
    }
}

auto Dropdown::setParent(Button *button) -> void {
    button->onClick([this]() {
        this->show_child = !this->show_child;
        this->update();
    });

    this->m_parent.reset(button);
    auto gb = this->m_parent->getHitbox().getGlobalBounds();
    m_dropdown_bg.setPosition(gb.left, gb.top + gb.height);
}
auto Dropdown::getParent() -> Button & { return *m_parent; }

auto Dropdown::addChild(const char *name, const char *shortcut, Button *child) -> void {
    sf::FloatRect hitbox;
    if (m_childs.empty()) {
        hitbox = m_parent->getHitbox().getGlobalBounds();
        hitbox.left += 2.5;
    } else
        hitbox = m_childs.back()->getHitbox().getGlobalBounds();
    hitbox.top += hitbox.height;
    hitbox.width = m_dropdown_bg.getSize().x - 5;
    auto img = new Dropdown::ChildGraph(name, shortcut, hitbox);

    child->setDrawable(img);
    hitbox.height = img->name.getGlobalBounds().height + 10;
    child->setHitbox(hitbox);

    auto size = m_dropdown_bg.getSize();
    size.y += hitbox.height;
    m_dropdown_bg.setSize(size);

    m_childs.emplace_back(child);
}
auto Dropdown::register_childs(WindowAPI *win) -> void {
    win->register_interactable(m_parent.get());

    for (auto it = m_childs.begin(); it != m_childs.end(); it++) {
        win->register_interactable(it->get());
    }
}

auto Dropdown::getDropdownBG() -> sf::RectangleShape & { return m_dropdown_bg; }

Dropdown::ChildGraph::ChildGraph(const char *name, const char *shortcut, sf::FloatRect dropdown_rect) {
    auto &font = AssetManager::getInstance().getFont("roboto");
    this->name.setString(name);
    this->name.setFont(font);
    this->name.setCharacterSize(18);
    this->name.setFillColor(sf::Color::White);

    float y = dropdown_rect.top;
    this->name.setPosition(dropdown_rect.left + 30, y);

    this->shortcut.setString(shortcut);
    this->shortcut.setFont(font);
    this->shortcut.setCharacterSize(18);
    this->shortcut.setFillColor(sf::Color::White);
    float x = dropdown_rect.width - this->shortcut.getGlobalBounds().width - 30;
    this->shortcut.setPosition(x, y);
}

auto Dropdown::ChildGraph::draw(sf::RenderTarget &target, sf::RenderStates states) const -> void {
    target.draw(this->name);
    target.draw(this->shortcut);
}
