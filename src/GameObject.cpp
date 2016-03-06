#include "GameObject.h"

void GameObject::update(float deltaTime) {
  for(Component* component : _components) {
    component->update();
  }
}

void GameObject::render(sf::RenderTarget& target) {
  if(hasComponent<Renderer>()) {
    getComponent<Renderer>().render(target);
  }
}

