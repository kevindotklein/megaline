#include <iostream>
#include <raylib.h>
#include <math.h>

#include "./utils/defs.hpp"
#include "./components/board.hpp"
#include "./components/player.hpp"

int main(void) {
  SetConfigFlags(FLAG_MSAA_4X_HINT | FLAG_WINDOW_UNDECORATED);

  InitWindow(GetMonitorWidth(0), GetMonitorHeight(0), "Megaline");
  SetWindowPosition(0, 0);

  SetExitKey(KEY_NULL);

  Font ubuntuFont = LoadFontEx("./assets/fonts/Ubuntu-Regular.ttf", 32, nullptr, 0);

  SetTargetFPS(60);
  float time = 0.f;
  auto grid = new megaline::board::Grid();
  auto player = new megaline::Player();
  while(!WindowShouldClose()) {

    BeginDrawing();

    ClearBackground(GetColor(0x181818FF));
    grid->Draw();
    player->Draw();
    player->SetFireOffset(cosf(0 * 5 * DEG2RAD) * 40);
    player->Fire([](float x){return cosf(x * 5 * DEG2RAD) * 40;}, time);

    time+=1.f;

    EndDrawing();
  }
  
  return 0;
}