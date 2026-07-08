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

bool PollInput::IsKeyPressed(const InputState& inputState, const std::list<std::string_view>& keyCodes) {

  for(const auto& keyCode : keyCodes) {
    if(keyCode == ENTER_CODE && (inputState.keys & ENTER_KEY)) {
      return true;
    } else if(keyCode == ARROW_LEFT_CODE && (inputState.keys & LEFT_KEY)) {
      return true;
    } else if(keyCode == ARROW_RIGHT_CODE && (inputState.keys & RIGHT_KEY)) {
      return true;
    } else if(keyCode == ARROW_UP_CODE && (inputState.keys & UP_KEY)) {
      return true;
    } else if(keyCode == ARROW_DOWN_CODE && (inputState.keys & DOWN_KEY)) {
      return true;
    }

    else if(inputState.letterKeys.find(keyCode) != std::string::npos) {
      return true;
    }
  }

  return false;
}
