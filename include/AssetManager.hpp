#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <unordered_map>

class AssetManager {
  public:
    static auto getInstance() -> AssetManager &;

    auto getFont(const char *name) -> sf::Font &;

  protected:
    AssetManager();
    inline static AssetManager *m_instance = nullptr;

  private:
    std::unordered_map<std::string, sf::Font> m_fonts;
};
