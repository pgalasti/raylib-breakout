#include "core/PollInput.h"

#include <algorithm>
#include <string_view>
#include "raylib.h"

using namespace RBreakout::Core;

void PollInput::Poll() {
  
  m_InputState.reset();

  for(const auto& [raylibKey, mappedKey] : g_keymap) {
    if(::IsKeyDown(raylibKey)) {
      m_InputState |= mappedKey;
    }
  }

  for(const auto& [raylibKey, mappedLetterKey] : g_letterkeymap) {
    if(::IsKeyDown(raylibKey)) {
      m_InputState |= mappedLetterKey;
    }
  }
}

bool PollInput::IsKeyPressed(const InputState& inputState, std::string_view keyCode) {

  
  if(keyCode == ENTER_CODE) {
    return inputState.keys & ENTER_KEY;
  } else if(keyCode == ARROW_LEFT_CODE) {
    return inputState.keys & LEFT_KEY;
  } else if(keyCode == ARROW_RIGHT_CODE) {
    return inputState.keys & RIGHT_KEY;
  } else if(keyCode == ARROW_UP_CODE) {
    return inputState.keys & UP_KEY;
  } else if(keyCode == ARROW_DOWN_CODE) {
    return inputState.keys & DOWN_KEY;
  }
  auto find = inputState.letterKeys.find(keyCode);
  if(inputState.letterKeys.find(keyCode) != std::string::npos) {
    return true;
  }

  return false;
}
