#include "./board.hpp"

namespace megaline
{
  namespace board
  {
    void Grid::DrawGrid() {
      int xTotalSize = this->xSlices * this->spacing;
      int yTotalSize = this->ySlices * this->spacing;

      int startX = this->center.x - xTotalSize / 2;
      int startY = this->center.y - yTotalSize / 2;

      for (int i = 0; i <= this->xSlices; i++) {
        int x = startX + i * spacing;
        DrawLine(x, startY, x, startY + yTotalSize, (Color){100, 100, 100, 255});
      }

      for (int i = 0; i <= this->ySlices; i++) {
        int y = startY + i * spacing;
        DrawLine(startX, y, startX + xTotalSize, y, (Color){100, 100, 100, 255});
      }
    }
  }

}