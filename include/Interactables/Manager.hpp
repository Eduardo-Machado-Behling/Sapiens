#pragma once

#include "Interactables/Interactable.hpp"
#include <vector>

struct InteractableManager {
    virtual ~InteractableManager() = default;

    virtual auto register_interactable(Interactable *interactable) -> void { m_interactables.push_back(interactable); }

  protected:
    std::vector<Interactable *> m_interactables;
};
