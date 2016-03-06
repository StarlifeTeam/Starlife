#ifndef SL_RENDERER_H_
#define SL_RENDERER_H_

#include <SFML/Graphics.hpp>

#include "Component.h"

class Renderer : public Component {
 public:
  Renderer() {}
  ~Renderer() {}

  void setTexture(sf::Texture* texture);
  sf::Sprite& getSprite();
  
  void setShader(sf::Shader* shader);
  sf::Shader* getShader();

  // TODO: Change sf::FloatRect to Bounds
  sf::FloatRect getBounds() { return _sprite.getGlobalBounds(); }
  
  void render(sf::RenderTarget& target);

 private:
  // TODO: Check if it's better not to use the sf::Sprite in this way
  // due to the duplicity of position, rotation, scale and transform with
  // the GameObject's Transform component. Maybe the better solution would be to
  // handle the texture directly within this class?
  sf::Sprite _sprite;
  sf::Shader* _shader = nullptr;
};
 
#endif
