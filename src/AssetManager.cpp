#include "AssetManager.hpp"

auto AssetManager::getFont(const char *name) -> sf::Font & { return this->m_fonts[name]; }

auto AssetManager::getInstance() -> AssetManager & {
    if (!m_instance)
        m_instance = new AssetManager();

    return *m_instance;
}

AssetManager::AssetManager() {
    sf::Font temp;
    if (!temp.loadFromFile("./assets/fonts/Roboto.ttf"))
        abort();

    m_fonts.insert(std::pair<std::string, sf::Font>("roboto", temp));
}