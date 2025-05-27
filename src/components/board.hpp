#pragma once

#include <raylib.h>

namespace megaline {
  namespace board {
    class Grid {
      private:
        Vector2 center = (Vector2){GetScreenWidth()/2.f, GetScreenHeight()/2.f};
        int xSlices = 35;
        int ySlices = 30;
        int spacing = 30;

      public:
        Grid() = default;
        void Draw(void);
        virtual ~Grid() = default;
    };
  }
}