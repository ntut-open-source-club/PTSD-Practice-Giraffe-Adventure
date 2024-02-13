#ifndef APP_UTIL_HPP
#define APP_UTIL_HPP

#include "Character.hpp"

inline bool isInsideTheSquare(const Character& character) {
    auto position = character.GetPosition();
    return position.y > -56 && position.y < 75 && position.x > 89 && position.x < 159;
}

#endif //APP_UTIL_HPP
