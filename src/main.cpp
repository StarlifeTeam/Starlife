#include <iostream>
#include <SFML/Graphics.hpp>

#include "Engine.h"

int main() {
  // Loads the texture
  sf::Texture texture;
  if(!texture.loadFromFile("res/Monster.png")) {
    std::cout << "ERROR: Can't open texture." << std::endl;
    return 1;
  }

  Game game(sf::Vector2i(800, 600), "Game");

  GameObject& gameObject = game.createObject();
  gameObject.transform.setPosition(sf::Vector2f(100, 100));

  gameObject.addComponent<Renderer>();
  gameObject.getComponent<Renderer>().setTexture(&texture);

  gameObject.addComponent<Collider>();
  gameObject.getComponent<Collider>().setSize(32, 32);

  game.start();
  
  return 0;
}
