#ifndef SL_GAME_OBJECT_FACTORY
#define SL_GAME_OBJECT_FACTORY

#include "Component.h"
#include "Collider.h"
#include "Renderer.h"
#include "GameObject.h"

class GameObjectFactory{
 public:
  
  // Creates the main character
  static GameObject* createMainCharacter();
  
  /* BEAST */
  
  // Creates a random beast for the jungle level
  static GameObject* createJungleBeast();
  // Creates a random beast for the desert level
  static GameObject* createDesertBeast();
  // Creates a random beast for the arctic level
  static GameObject* createArcticBeast();
  // Creates a random beast for the volcano level
  static GameObject* createVolcanoBeast();

  /* BOSSES */
 
  // Creates the boss for the earth level
  static GameObject* createJungleBoss();
  // Creates the boss for the desert level
  static GameObject* createDesertBoss();
  // Creates the boss for the Arctic level
  static GameObject* createArcticBoss();
  // Creates the boss for the volcano level
  static GameObject* createVolcanoBoss();

};

#endif