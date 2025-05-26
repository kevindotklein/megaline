#include <iostream>
#include <raylib.h>

#include "./utils/defs.hpp"
#include "./components/board.hpp"

int main(void) {
  SetConfigFlags(FLAG_MSAA_4X_HINT | FLAG_WINDOW_UNDECORATED);

  InitWindow(GetMonitorWidth(0), GetMonitorHeight(0), "Megaline");
  SetWindowPosition(0, 0);

  SetExitKey(KEY_NULL);

  Font ubuntuFont = LoadFontEx("./assets/fonts/Ubuntu-Regular.ttf", 32, nullptr, 0);

  SetTargetFPS(60);

  while(!WindowShouldClose()) {

    BeginDrawing();

    ClearBackground(GetColor(0x181818FF));
    megaline::board::drawGrid(
      (Vector2){static_cast<float>(GetScreenWidth()/2),
      static_cast<float>(GetScreenHeight()/2)},
      megaline::board::defaultXSlices,
      megaline::board::defaultYSlices,
      megaline::board::defaultSpacing
    );
    

    EndDrawing();
  }
  
  return 0;
}