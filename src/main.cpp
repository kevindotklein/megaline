#include <iostream>
#include <raylib.h>
#include <math.h>

#include "./utils/defs.hpp"
#include "./components/board.hpp"

int main(void) {
  SetConfigFlags(FLAG_MSAA_4X_HINT | FLAG_WINDOW_UNDECORATED);

  InitWindow(GetMonitorWidth(0), GetMonitorHeight(0), "Megaline");
  SetWindowPosition(0, 0);

  SetExitKey(KEY_NULL);

  Font ubuntuFont = LoadFontEx("./assets/fonts/Ubuntu-Regular.ttf", 32, nullptr, 0);

  SetTargetFPS(60);
  float i = 0.f;
  while(!WindowShouldClose()) {

    BeginDrawing();

    //ClearBackground(GetColor(0x181818FF));
    megaline::board::drawGrid(
      (Vector2){static_cast<float>(GetScreenWidth()/2),
      static_cast<float>(GetScreenHeight()/2)},
      megaline::board::defaultXSlices,
      megaline::board::defaultYSlices,
      megaline::board::defaultSpacing
    );

    DrawCircleV((Vector2){500.f, 500.f}, 10, ColorFromHSV(90.f, 0.8f, 1.f));
    if(i<=GetScreenWidth()) {
      DrawLineV((Vector2){1000.f + i, 600 + sinf(static_cast<float>(i*0.5f)) * 30},
                (Vector2){1000.f + i + 1.f, 600 + sinf(static_cast<float>((i+1.f)*0.5f)) * 30},
                ColorFromHSV(220.f, 0.8f, 1.f));
    }
    if(i<=GetScreenWidth()) {
      DrawLineV((Vector2){1000.f + i, 1000 + sinf(static_cast<float>(i*0.1f)) * 30},
                (Vector2){1000.f + i + 1.f, 1000 + sinf(static_cast<float>((i+1.f)*0.1f)) * 30},
                ColorFromHSV(220.f, 0.8f, 1.f));
    }
    if(i<=GetScreenWidth()) {
      DrawLineV((Vector2){1000.f + i, 1000 + sinf(static_cast<float>(i*1.f)) * 30},
                (Vector2){1000.f + i + 1.f, 1000 + sinf(static_cast<float>((i+1.f)*1.f)) * 30},
                ColorFromHSV(220.f, 0.8f, 1.f));
    }

    i+=1.f;

    EndDrawing();
  }
  
  return 0;
}