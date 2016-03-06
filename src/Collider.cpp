#include "Collider.h"
#include "GameObject.h"

void Collider::setSize(float x, float y) {
  _size.x = x;
  _size.y = y;
  _bounds.width = x;
  _bounds.height = y;
}

void Collider::setPosition(float x, float y) {
  _position.x = x;
  _position.y = y;
}

void Collider::setPosition(const sf::Vector2f position) {
  _position = position;
}

sf::FloatRect& Collider::getBounds() {
  return _bounds;
}

void Collider::update() {
  sf::Vector2f objectPosition = gameObject->transform.getPosition();
  _bounds.left = objectPosition.x + _position.x;
  _bounds.top = objectPosition.y + _position.y;

  sf::Vector2f objectScale = gameObject->transform.getScale();
  _bounds.width = _size.x * objectScale.x;
  _bounds.height = _size.y * objectScale.y;
}
