#ifndef SL_COMPONENT_H_
#define SL_COMPONENT_H_

#include <SFML/Graphics/Rect.hpp>
  
class GameObject;
class Collider;
  
class Component {
 public:
  /*
    Called just once when the component starts to function
  */
  virtual void start() {}

  /*
    Called every frame
   */
  virtual void update() {}
  
  /*
    Called when there is a collision
    collider is the collider of the other game object
  */
  virtual void onCollision(Collider* collider) {}
  
  void setGameObject(GameObject* obj) { gameObject = obj; }
  GameObject* getGameObject() { return gameObject; }

 protected:
  GameObject* gameObject = nullptr;
};

#endif
