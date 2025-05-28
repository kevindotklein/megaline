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
        float minBoundX = GetScreenWidth()/2.f - (35*30)/2.f;
        float minBoundY = GetScreenHeight()/2.f - (30*30)/2.f;
        float maxBoundX = GetScreenWidth()/2.f + (35*30)/2.f;
        float maxBoundY = GetScreenHeight()/2.f + (30*30)/2.f;

      public:
        Grid() = default;
        void Draw(void);
        float GetMinBoundX(void);
        float GetMinBoundY(void);
        float GetMaxBoundX(void);
        float GetMaxBoundY(void);
        virtual ~Grid() = default;
    };
  }
}