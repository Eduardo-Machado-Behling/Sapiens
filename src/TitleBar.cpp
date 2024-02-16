#include "TitleBar.hpp"

TitleBar::TitleBar(WindowAPI *window) : file(250) {
    sf::Vector2f window_size({(float)window->get_size().x, (float)window->get_size().y});
    this->rect.setFillColor(sf::Color(0, 0, 0));
    this->rect.setPosition(0, 0);
    this->rect.setSize({(float)window_size.x, 30});

    auto text = new sf::Text();
    text->setPosition(0, 0);
    text->setCharacterSize(18);
    text->setFont(AssetManager::getInstance().getFont("roboto"));
    text->setString("File");
    auto b = text->getGlobalBounds();
    text->setPosition((50 - b.width) / 2, (30 - b.height) / 2 - 5);

    auto file_btn = new Button();
    file_btn->setDrawable(text);
    auto hb = text->getGlobalBounds();
    hb.top = 0;
    hb.left = 0;
    hb.width = 50;
    hb.height = 30;
    file_btn->setHitbox(hb);
    file_btn->onEnter([](Button *btn) { btn->getHitbox().setFillColor(sf::Color::Green); });
    file_btn->onLeave([](Button *btn) { btn->getHitbox().setFillColor(sf::Color::Transparent); });

    this->file.setParent(file_btn);

    auto btn = new Button();
    btn->onEnter([](Button *btn) { btn->getHitbox().setFillColor(sf::Color::Green); });
    btn->onLeave([](Button *btn) { btn->getHitbox().setFillColor(sf::Color::Transparent); });
    this->file.addChild("Save", "Ctrl+S", btn);

    this->file.getDropdownBG().setFillColor(sf::Color(20, 20, 20));

    auto img = new sf::Text();
    img->setFont(AssetManager::getInstance().getFont("roboto"));
    img->setString('X');
    img->setCharacterSize(22);
    img->setPosition(window_size.x - 50 + (50 - img->getGlobalBounds().width) / 2, 0);
    img->setFillColor(sf::Color::White);

    auto hitbox = rect.getGlobalBounds();
    hitbox.left = window_size.x - 50;
    hitbox.width -= 50;
    this->close.setHitbox(hitbox);
    this->close.setDrawable(img);
    this->close.onClick([=]() { window->close(); });
    this->close.onEnter([](Button *btn) { btn->getHitbox().setFillColor(sf::Color::Red); });
    this->close.onLeave([](Button *btn) { btn->getHitbox().setFillColor(sf::Color::Transparent); });

    window->register_drawable(&this->rect);
    window->register_drawable(&this->close);
    window->register_drawable(&this->file);
    this->file.register_childs(window);
    window->register_interactable(&this->close);
}
