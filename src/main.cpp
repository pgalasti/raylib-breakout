#include "core/Game.h"

#include "raylib.h" // Replace with renderer

#include<iostream>
#include<memory>
#include<string>

int main(int argc, char* argv[]) {

  std::unique_ptr<RBreakout::Core::Game> pGame {std::make_unique<RBreakout::Core::Game>()};
  pGame->Start();
  while(!pGame->IsShuttingDown()) {
    pGame->UpdateGameState();
    pGame->RenderState();
  };
  
  pGame->Shutdown();

  return 0;
}
