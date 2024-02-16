#ifndef APP_UTIL_HPP
#define APP_UTIL_HPP

#include "Character.hpp"

[[nodiscard]]inline bool isInsideTheSquare(const Character& character) {
    auto position = character.GetPosition();
    return position.y > -90 && position.y < 93 && position.x > 50 && position.x < 233;
}

[[nodiscard]]inline bool AreAllDoorsOpen(const std::vector<std::shared_ptr<Character>>& doors) {
    return std::all_of(doors.begin(), doors.end(), [](const auto& door) { return door->GetImagePath() ==
    GA_RESOURCE_DIR"/Image/Character/door_open.png"; });
}

#endif //APP_UTIL_HPP
