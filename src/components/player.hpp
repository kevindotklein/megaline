#pragma once

#include <raylib.h>
#include <functional>
#include <math.h>
#include "../utils/defs.hpp"

namespace megaline {
  enum PlayerDirection{
    RIGHT,
    LEFT,
  };
  class Player {
    private:
      Vector2 position = (Vector2){GetScreenWidth()/2.f, GetScreenHeight()/2.f};
      Color color = megaline::utils::green;
      float size = 10.f;
      PlayerDirection direction = RIGHT;
      float fireOffset = 0.f;

    public:
      Player() = default;
      void Draw();
      void SetPlayerDirection(PlayerDirection dir);
      void SetFireOffset(float offset);
      void Fire(std::function<float(float)> func, float time);
      void SetPosition(Vector2 pos);
      virtual ~Player() = default;
  };
}