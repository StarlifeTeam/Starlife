#ifndef SL_COLLIDER_H_
#define SL_COLLIDER_H_

#include <SFML/System/Vector2.hpp>

#include "Component.h"

class Collider : public Component {
 public:
  Collider() {}
  ~Collider() {}

  /*
    Set the size in pixels of the collider
  */
  void setSize(float x, float y);
  /*
    Set the position relative to the game object, in pixels.
  */
  void setPosition(float x, float y);
  void setPosition(const sf::Vector2f position);
  
  sf::FloatRect& getBounds();

  /*
    Updates the position and scale accordingly to the transform
    of the object containing this collider
  */
  void update();
  
  // DEBUG. Draw Colliders
  bool hasCollision;
  void onCollision(Collider* collider) { hasCollision = true; }
  // END DEBUG  
  
 private:
  sf::FloatRect _bounds;  // Bounding Box of the collider
  sf::Vector2f _size;  // Size of the collider bounding box
  // Position (or offset) of the collider relative to the position of the object
  sf::Vector2f _position;

};

#endif
