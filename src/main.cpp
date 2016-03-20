#include <iostream>
#include <SFML/Graphics.hpp>

#include "Engine.h"
#include "Sticky.h"  // Migue vente al lab de redes!

int main() {
  // Loads the texture
  sf::Texture texture;
  if(!texture.loadFromFile("res/Monster.png")) {
    std::cout << "ERROR: Can't open texture." << std::endl;
    return 1;
  }

  Game game(sf::Vector2i(800, 600), "Game");

  GameObject* leftWall = new GameObject();
  leftWall->transform.setPosition(0, 0);
  leftWall->addComponent<Collider>();
  leftWall->getComponent<Collider>()->setSize(10, 600);
  game.addObject(leftWall);

  GameObject* rightWall = new GameObject();
  rightWall->transform.setPosition(790, 0);
  rightWall->addComponent<Collider>();
  rightWall->getComponent<Collider>()->setSize(10, 600);
  game.addObject(rightWall);

  GameObject* topWall = new GameObject();
  topWall->transform.setPosition(0, 0);
  topWall->addComponent<Collider>();
  topWall->getComponent<Collider>()->setSize(800, 10);
  game.addObject(topWall);
  
  GameObject* bottomWall = new GameObject();
  bottomWall->transform.setPosition(0, 590);
  bottomWall->addComponent<Collider>();
  bottomWall->getComponent<Collider>()->setSize(800, 10);
  game.addObject(bottomWall);

  for(int i = 0; i < 50; i++) {
    GameObject* gameObject = new GameObject();
    game.addObject(gameObject);

    gameObject->addComponent<Renderer>();
    gameObject->getComponent<Renderer>()->setTexture(&texture);

    gameObject->addComponent<Collider>();
    gameObject->getComponent<Collider>()->setSize(32, 32);

    gameObject->addComponent<Sticky>();
  }


  game.start();
  
  return 0;
}
