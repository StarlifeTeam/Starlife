#ifndef SL_GAME_OBJECT_H_
#define SL_GAME_OBJECT_H_

#include <iostream>
#include <typeinfo>
#include <unordered_map>
#include <SFML/Graphics.hpp>

#include "Renderer.h"

class GameObject {
 public:
  GameObject() {}
  ~GameObject() {
    for(Component* component : _components) {
      delete component;
    }
  }

  /*
    Adds a component of the specified type to this object.
  */
  template<typename T>
  void addComponent() {
    T* component = new T();
    component->setGameObject(this);
    _components.push_back(component);
    component->start();
  }


  /*
    Note: The getComponent method iterates through all the components attached to
    the object until a component matching the specified type is found.
    This can be slow when there are many components, but it is fine for the
    moment and it keeps things simple.
    
    Also, doing it this way we can retrieve a component knowing only the type
    of a class of which it inherits from.
    For example, if we add a CircleRenderer(and this class inherits from a
    Renderer class) to an object, we can retrieve it calling for just the Renderer.
    Which is useful when we don't know(or don't need to know) the exact type
    of a component.
  */
  
  /*
    Gets the first component of the specified type found or nullptr if
    there is not a component of that type attached to this object.
  */
  template<typename T>
  T& getComponent() {
    T* component = nullptr;
    for(Component* comp : _components) {
      component = dynamic_cast<T*>(comp);  // Checks if the type matches
      if(component != nullptr) break;
    }
    
    return *component;
  }

  /*
    Checks if this object has a component of the specified type
  */
  template<typename T>
  bool hasComponent() {
    for(Component* comp : _components) {
      if(dynamic_cast<T*>(comp) != nullptr) {
        return true;
      }
    }
    
    return false;
  }
  
  void update(float deltaTime);

  void render(sf::RenderTarget& target);

 public:
  /*
    Note:
    The Transform is technically a Component and therefore it should inherit
    from the Component class, but to make things simpler and because the class
    sf::Transformable implements a lot of functionality as the methods: move(),
    rotate(), scale(), I think it's better to just make use of that class directly.

    If we need the transform to inherit from Component in the future, we can
    make a new class inheriting from both the sf::Transformable and Component
   */
  
  sf::Transformable transform;

 private:

  /*
    Vector of the components attached to this game object
  */
  std::vector<Component*> _components;
  
};

#endif
