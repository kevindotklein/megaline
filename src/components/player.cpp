#include "./player.hpp"

namespace megaline {
  void Player::Draw() {
    DrawCircleV(this->position, this->size, this->color);
  }
}