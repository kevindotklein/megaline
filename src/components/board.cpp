#include "./board.hpp"

namespace megaline
{
  namespace board
  {
    void drawGrid(Vector2 center, int xSlices, int ySlices, int spacing) {
      int xTotalSize = xSlices * spacing;
      int yTotalSize = ySlices * spacing;

      int startX = center.x - xTotalSize / 2;
      int startY = center.y - yTotalSize / 2;

      for (int i = 0; i <= xSlices; i++) {
        int x = startX + i * spacing;
        DrawLine(x, startY, x, startY + yTotalSize, (Color){100, 100, 100, 255});
      }

      for (int i = 0; i <= ySlices; i++) {
        int y = startY + i * spacing;
        DrawLine(startX, y, startX + xTotalSize, y, (Color){100, 100, 100, 255});
      }
    }
  }

}