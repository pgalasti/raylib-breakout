#ifndef RBREAKOUT_POLLINPUT_H
#define RBREAKOUT_POLLINPUT_H

#include <cstdint>
#include <unordered_map>
#include <string_view>
#include <string>
#include <list>

#include "raylib.h"

namespace RBreakout::Core {

/**
 * Honestly, a lot of this class is redundant to what raylib offers.
 *
 * The only benefit is it's agnostic and another interface can be switched
 * in palce of raylib's implementation in Poll().
 **/


// This can be enhanced for more keys later if needed.
// For now just do arrow and enter
using KeyBitFlag = std::uint8_t; // If I add more, make sure this is expanded
constexpr KeyBitFlag ENTER_KEY  { 1 << 0 };
constexpr KeyBitFlag UP_KEY     { 1 << 1 };
constexpr KeyBitFlag DOWN_KEY   { 1 << 2 };
constexpr KeyBitFlag LEFT_KEY   { 1 << 3 };
constexpr KeyBitFlag RIGHT_KEY  { 1 << 4 };


struct InputState {
  KeyBitFlag keys {0};
  std::string letterKeys {""};
  
  void reset() { 
    keys = 0; 
    letterKeys.clear();
  }
  
  InputState& operator|=(KeyBitFlag bits) {
    keys |= bits;
    return *this;
  }
  
  InputState& operator|=(char letter) {
    letterKeys.push_back(letter);
    return *this;
  }

  // TODO: overload the bitwise & operator
};

// It probably makes more sense to just be a list structure
// but this is fine for now.
using RaylibKeyMap = std::unordered_map<int, KeyBitFlag>;
inline const RaylibKeyMap g_keymap {
  {KEY_ENTER,  ENTER_KEY},
  {KEY_UP,     UP_KEY},
  {KEY_DOWN,   DOWN_KEY},
  {KEY_LEFT,   LEFT_KEY},
  {KEY_RIGHT,  RIGHT_KEY}
};

// Probably a better way to handle letter keys but this will do for now.
using RaylibLetterKeyMap = std::unordered_map<int, char>;
inline const RaylibLetterKeyMap g_letterkeymap {
  {KEY_A, 'A'},
  {KEY_S, 'S'},
  {KEY_D, 'D'},
  {KEY_W, 'W'},
};

constexpr std::string_view ARROW_LEFT_CODE  {"AL"};
constexpr std::string_view ARROW_RIGHT_CODE {"AR"};
constexpr std::string_view ARROW_UP_CODE    {"AU"};
constexpr std::string_view ARROW_DOWN_CODE  {"AD"};
constexpr std::string_view ENTER_CODE       {"ENT"};

class PollInput {
public:
  PollInput() = default;
  ~PollInput() = default;

  void Poll();
  const InputState& GetPollState() const { return m_InputState; } 

  static bool IsKeyPressed(const InputState& inputState, const std::list<std::string_view>& keyCodes);
private:
  InputState m_InputState;
};

} // RBreakout::Core

#endif //RBREAKOUT_POLLINPUT_H
