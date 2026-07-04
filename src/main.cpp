#include "ui/Window.h"
#include "raylib.h" // Replace with renderer

#include<iostream>
#include<memory>
#include<string>

int main(int argc, char* argv[]) {

  RBreakout::UI::WindowOptions options {800, 350, 120, "Breakout"};
  std::unique_ptr<RBreakout::UI::Window> pWindow = std::make_unique<RBreakout::UI::Window>(options);

  pWindow->Init();

  while(pWindow->IsWindowOpen()) {
    //Replace with renderer logic
    BeginDrawing();
    ClearBackground(RAYWHITE);
    EndDrawing();
  };
  
  pWindow->Shutdown();

  return 0;
}
