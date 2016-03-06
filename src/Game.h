#ifndef SL_GAME_H_
#define SL_GAME_H_

#include <string>
#include <list>
#include <vector>
#include <SFML/Graphics.hpp>

#include "GameObject.h"

class Game {
 public:
  Game(sf::Vector2i size, std::string title);
  ~Game();
  
  void start();
  void stop();

  /*
    Note: Temporarily creating objects here. But it will be better to have
    a separate class just for creating the objects.
  */
  GameObject& createObject();
  
 private:
  /*
    Game loop
   */
  void run();

  void processInput();

  /*
    Updates all the game objects in the game.
  */
  void update(sf::Time time);

  /*
    Renders all the game objects in the game.
  */
  void render();

 private:
  sf::Vector2i _size;  // Size of the window
  std::string _title;  // Title of the window
  sf::RenderWindow _window;

  std::vector<GameObject*> _gameObjects;

  bool _running;  // Indicates wheter the gameloop is running
  int _fps;
  /*
    Note: The _fps could be moved to a debug class, because it only exists
    for debugging purposes.
  */

};

#endif
