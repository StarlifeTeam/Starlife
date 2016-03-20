#include "Component.h"
#include "Time.h"

#include <iostream>

class Sticky : public Component {

 public:
  Sticky() {}
  ~Sticky() {}

  void start() {
    // Set a random position
    gameObject->transform.setPosition(sf::Vector2f(50+rand()%700, 50+rand()%500));
    //Set a random velocity
    _velocity = sf::Vector2f (rand()%50+1, rand()%50+1);;
  }

  void update() {
    // Moves the game object
    gameObject->transform.move(_velocity * Time::getDeltaTime());
  }

  void onCollision(Collider* collider) {
    // Stops the movement if there's a collision
    _velocity.x = 0;
    _velocity.y = 0;
  }

 private:
  sf::Vector2f _velocity;
};
