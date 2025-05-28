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

  void Player::SetPosition(Vector2 pos) {
    this->position = pos;
  }

  void Player::SetCLine(Vector2 pos) {
    this->cLine = pos;
  }

  Vector2 Player::GetCLine(void) {
    return this->cLine;
  }

  void Player::Fire(std::function<float(float)> func, float time) {
    switch (this->direction) {
    case megaline::PlayerDirection::RIGHT: {
      float j;
      for (j = 0.f; j < time; j += megaline::utils::timeStep) {
        DrawLineV((Vector2){(this->position.x + this->size) + j,
                            (this->position.y + this->fireOffset) - func(j)},
                  (Vector2){(this->position.x + this->size) + j + megaline::utils::timeStep,
                            (this->position.y + this->fireOffset) - func(j+megaline::utils::timeStep)},
                  megaline::utils::blue);
      }
      this->cLine =
        (Vector2){(this->position.x + this->size) + j + megaline::utils::timeStep,
        (this->position.y + this->fireOffset) - func(j+megaline::utils::timeStep)};
      break;
    }
    case megaline::PlayerDirection::LEFT: {
      float j;
      for (j = 0.f; j < time; j += megaline::utils::timeStep) {
        DrawLineV((Vector2){(this->position.x - this->size) - j,
                            (this->position.y + this->fireOffset) - func(-j)},
                  (Vector2){(this->position.x - this->size) - j - megaline::utils::timeStep,
                            (this->position.y + this->fireOffset) - func(-j-megaline::utils::timeStep)},
                  megaline::utils::blue);
      }
      this->cLine =
        (Vector2){(this->position.x + this->size) + j + megaline::utils::timeStep,
        (this->position.y + this->fireOffset) - func(j+megaline::utils::timeStep)};
      break;
    }
    default:
      break;
    }
  }
}