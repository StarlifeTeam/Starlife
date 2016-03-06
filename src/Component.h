#ifndef SL_COMPONENT_H_
#define SL_COMPONENT_H_

#include <SFML/Graphics/Rect.hpp>
  
class GameObject;
  
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
  
  void setGameObject(GameObject* obj) { gameObject = obj; }
  GameObject* getGameObject() { return gameObject; }

 protected:
  GameObject* gameObject = nullptr;
};

#endif
