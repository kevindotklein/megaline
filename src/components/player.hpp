#pragma once

#include <raylib.h>
#include "../utils/defs.hpp"

namespace megaline {
  class Player {
    private:
      Vector2 position = (Vector2){GetScreenWidth()/2.f, GetScreenHeight()/2.f};
      Color color = megaline::utils::green;
      float size = 10.f;

    public:
      Player() = default;
      void Draw();
      virtual ~Player() = default;
  };
}