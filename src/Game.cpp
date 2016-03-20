#include <iostream>
#include "Time.h"
#include "Game.h"
#include "Collider.h"

Game::Game(sf::Vector2i size, std::string title) {
  _size = size;
  _title = title;
  _running = false;
}

Game::~Game() {
  for(GameObject* obj : _gameObjects) {
    delete obj;
  }
}

void Game::start() {
  _window.create(sf::VideoMode(_size.x, _size.y), _title);
  run();
}

void Game::stop(){
  _running = false;
}

void Game::addObject(GameObject *gameObject) {
  _gameObjects.push_back(gameObject);
}
  
void Game::run() {
  _running = true;
  
  sf::Clock clock;
  sf::Time elapsedTime = sf::Time::Zero;  // Time elapsed since last frame

  // Total time elapsed within one second, used to calculate the FPS.
  sf::Time timeCount = sf::Time::Zero; 
  // Number of frames passed in a second, used to calculate the FPS.
  int frameCount = 0;
  
  while(_running) {

    elapsedTime = clock.restart();
    timeCount += elapsedTime;
    frameCount++;
    // Each second, the FPS are calculated.
    if(timeCount.asMilliseconds() >= 1000) {
      timeCount -= sf::seconds(1);
      _fps = frameCount;
      frameCount = 0;

      std::cout << "FPS: " << _fps << std::endl;
    }
    
    Time::updateTime(elapsedTime.asSeconds());
    
    processInput();
    update();
    handleCollisions();
    render();
  }
  
  _window.close();
}
 
void Game::processInput() {
  sf::Event event;
  while(_window.pollEvent(event)) {
    switch(event.type) {
      case sf::Event::Closed:
        stop();
        break;
    }
  }
}

void Game::handleCollisions() {
  // Checks every object against every other object
  for(GameObject* object1 : _gameObjects) {
    for(GameObject* object2 : _gameObjects) {
      if(object1 == object2) continue; // If both objects are the same. Do nothing.

      Collider* collider1 = object1->getComponent<Collider>();
      Collider* collider2 = object2->getComponent<Collider>();

      // Only performs collision checking if the two objects have a collider
      if(collider1 == nullptr || collider2 == nullptr) continue;

      // If there is a collision, notify it to all the components in both objects
      if(collider1->getBounds().intersects(collider2->getBounds())) {
        for(Component* component : object1->getComponents()) {
          component->onCollision(collider2);
        }
        for(Component* component : object2->getComponents()) {
          component->onCollision(collider1);
        }
      }
    }
  }
}

void Game::update() {
  for(GameObject* gameObject : _gameObjects) {
    gameObject->update();
  }
}

void Game::render() {
  _window.clear(sf::Color::Blue);

  for(GameObject* gameObject : _gameObjects) {
    gameObject->render(_window);
    
    
    // DEBUG. Drawing the colliders.
    // Note: This slows down the game a lot
    bool DEBUG_drawColliders = true;
    if(DEBUG_drawColliders) {
      if(!gameObject->hasComponent<Collider>()) continue;

      Collider* collider = gameObject->getComponent<Collider>();
      sf::FloatRect bounds = collider->getBounds();

      sf::RectangleShape rect;
      rect.setPosition(bounds.left, bounds.top);
      rect.setSize(sf::Vector2f(bounds.width, bounds.height));
      rect.setOutlineColor(collider->hasCollision?sf::Color::Red:sf::Color::Green);
      rect.setOutlineThickness(1);
      rect.setFillColor(sf::Color::Transparent);
      _window.draw(rect);
    }
    // END DEBUG

  }

  _window.display();
}
