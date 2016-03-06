#include "Renderer.h"
#include "GameObject.h"

void Renderer::setTexture(sf::Texture* texture) {
  if(texture != nullptr) {
    _sprite.setTexture(*texture);
  }
}

sf::Sprite& Renderer::getSprite() {
  return _sprite;
}

void Renderer::setShader(sf::Shader* shader) {
  if(shader != nullptr) {
    _shader = shader;
  }
}
 
sf::Shader* Renderer::getShader() {
  return _shader;
}
  
void Renderer::render(sf::RenderTarget& target) {
  sf::RenderStates states = sf::RenderStates::Default;
  states.transform *= gameObject->transform.getTransform();
  
  //  if(shader_ != nullptr)
  //    states.shader = shader_;

  target.draw(_sprite, states);
}
