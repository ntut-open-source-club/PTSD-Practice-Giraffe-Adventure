#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>

#include "Util/GameObject.hpp"

class Character : public Util::GameObject {
public:
    explicit Character(const std::string& ImagePath);

    Character(const Character&) = delete;

    Character(Character&&) = delete;

    Character& operator=(const Character&) = delete;

    Character& operator=(Character&&) = delete;

    [[nodiscard]] const std::string& GetImagePath() const { return m_ImagePath; }

    [[nodiscard]] const glm::vec2& GetPosition() const { return m_Transform.translation; }

    [[nodiscard]] bool GetVisibility() const { return m_Visible; }

    void SetImage(const std::string& ImagePath);

    void SetPosition(const glm::vec2& Position) { m_Transform.translation = Position; }

    void ResetPosition() { m_Transform.translation = {.5f, .5f}; }

     [[nodiscard]] bool IfCollides(const Character& other) const {(void)other; return false;} // TODO: Implement the collision detection

    // TODO: Add and implement more methods and properties as needed to finish Giraffe Adventure.

private:
    std::string m_ImagePath;
};


#endif //CHARACTER_HPP
