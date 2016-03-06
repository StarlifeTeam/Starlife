#include <iostream>
#include "Game.h"

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

GameObject& Game::createObject() {
  GameObject* gameObject = new GameObject();
  _gameObjects.push_back(gameObject);
  return *gameObject;
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
    
    processInput();
    update(elapsedTime);
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

void Game::update(sf::Time time) {
  for(GameObject* gameObject : _gameObjects) {
    gameObject->update(time.asSeconds());
  }
}

void Game::render() {
  _window.clear(sf::Color::Blue);

  for(GameObject* gameObject : _gameObjects) {
    gameObject->render(_window);
  }

  _window.display();
}
