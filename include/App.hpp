#ifndef APP_HPP
#define APP_HPP

#include "pch.hpp" // IWYU pragma: export

#include "Util/Root.hpp"
#include "Character.hpp"
#include "Util/Text.hpp"

class App {
public:
    enum class State {
        START,
        UPDATE,
        END,
    };

    State GetCurrentState() const { return m_CurrentState; }

    void Start();

    void Update();

    void End(); // NOLINT(readability-convert-member-functions-to-static)

private:
    void ValidTask();

    static constexpr std::string_view s_PhaseTasks[6] = {
            "Replace the image of m_giraffe with giraffe.bmp in Resources!",
            "Make the giraffe move into the red area using the keyboard!",
            "Design a program to make the chest disappear when the giraffe touches it!",
            "Write a program to give your bee friend an animation!",
            "Write a program to open the door when your character touches it!",
            "Design a program to countdown the ball, then stop the animation after displaying OK"
    };
    static constexpr std::string_view s_Validation = "Press Enter to validate";

private:
    enum class Phase {
        CHANGE_CHARACTER_IMAGE,
        ABLE_TO_MOVE,
        COLLIDE_DETECTION,
        BEE_ANIMATION,
        OPEN_THE_DOORS,
        COUNTDOWN,
    };


    State m_CurrentState = State::START;
    Phase m_Phase = Phase::CHANGE_CHARACTER_IMAGE;

    Util::Root m_Root;

    std::shared_ptr<Character> m_Background;
    std::shared_ptr<Character> m_Giraffe;
    std::shared_ptr<Character> m_Chest;
    std::shared_ptr<Character> m_Bee;
    std::vector<std::shared_ptr<Character>> m_Doors;
    std::shared_ptr<Character> Ball;
};

#endif
