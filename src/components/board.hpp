#pragma once

#include <raylib.h>

namespace megaline {
  namespace board {
    const int defaultXSlices = 35;
    const int defaultYSlices = 30;
    const int defaultSpacing = 30;

    void drawGrid(Vector2 center, int xSlices, int ySlices, int spacing);
  }
}