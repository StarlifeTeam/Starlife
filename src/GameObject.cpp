#include "GameObject.h"

void GameObject::update() {
  for(Component* component : _components) {
    component->update();
  }
}

void GameObject::render(sf::RenderTarget& target) {
  Renderer* renderer = getComponent<Renderer>();
  if(renderer) renderer->render(target);
}

