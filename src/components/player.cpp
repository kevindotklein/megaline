#include "./player.hpp"
#include <iostream>
namespace megaline {
  void Player::Draw() {
    DrawCircleV(this->position, this->size, this->color);
  }

  void Player::SetPlayerDirection(PlayerDirection dir) {
    this->direction = dir;
  }


  void Player::SetFireOffset(float offset) {
    this->fireOffset = offset;
  }

  void Player::Fire(std::function<float(float)> func, float time) {
    switch (this->direction) {
    case megaline::PlayerDirection::RIGHT:
      for (float j = 0.f; j < time; j += megaline::utils::timeStep) {
        DrawLineV((Vector2){(this->position.x + this->size) + j,
                            this->position.y + func(j)},
                  (Vector2){(this->position.x + this->size) + j + megaline::utils::timeStep,
                            this->position.y + func(j+megaline::utils::timeStep)},
                  megaline::utils::blue);
      }
      break;
    case megaline::PlayerDirection::LEFT:
      for (float j = 0; j < time; j += 1.0f) {
        DrawLineV((Vector2){1000.f + j, 600 + sinf(j * 0.5f) * 30},
                  (Vector2){1000.f + j + 1.f, 600 + sinf((j + 1.f) * 0.5f) * 30},
                  megaline::utils::blue);
      }
      break;
    default:
      break;
    }
  }
}