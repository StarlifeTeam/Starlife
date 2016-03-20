#include "GameObjectFactory.h"

// To Do
GameObject* GameObjectFactory::createMainCharacter(){
  GameObject* gameObject = new GameObject();
  gameObject->addComponent<Renderer>();
  //gameObject.getComponent<Renderer>().setTexture(&texture);
  gameObject->addComponent<Collider>();
  gameObject->getComponent<Collider>()->setSize(32, 32);
  return gameObject;
}

/* BEAST */

GameObject* GameObjectFactory::createJungleBeast(){
  return nullptr;
}

GameObject* GameObjectFactory::createDesertBeast(){
  return nullptr;
}

GameObject* GameObjectFactory::createArcticBeast(){
  return nullptr;
}

GameObject* GameObjectFactory::createVolcanoBeast(){
  return nullptr;
}

/* BOSSES */

GameObject* GameObjectFactory::createJungleBoss(){
  return nullptr;
}

GameObject* GameObjectFactory::createDesertBoss(){
  return nullptr;
}

GameObject* GameObjectFactory::createArcticBoss(){
  return nullptr;
}

GameObject* GameObjectFactory::createVolcanoBoss(){
  return nullptr;
}