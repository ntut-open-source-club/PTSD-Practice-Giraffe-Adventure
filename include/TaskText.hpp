#ifndef TASKTEXT_HPP
#define TASKTEXT_HPP

#include "Util/GameObject.hpp"
#include "Util/Text.hpp"
#include "Util/Color.hpp"

class TaskText : public Util::GameObject {
public:
    TaskText() : GameObject(
            std::make_unique<Util::Text>(GA_RESOURCE_DIR"/Font/Inkfree.ttf", 20,
                                         append_string_views(s_PhaseTasks[0], s_Validation),
                                         Util::Color(0.F, 0.F, 0.F, 1.0F)),
            100) {
        m_Transform.translation = {0.0F, -270.F};
    }

    void NextPhase(const int phase) {
        auto temp = std::dynamic_pointer_cast<Util::Text>(m_Drawable);
        temp->SetText(append_string_views(s_PhaseTasks[phase], s_Validation));
    }

private:
    inline static std::string append_string_views(std::string_view sv1, std::string_view sv2) {
        return std::string(sv1) + "\n" + std::string(sv2);
    }

    static constexpr std::string_view s_PhaseTasks[6] = {
            "Replace the image of m_giraffe with giraffe.bmp in Resources!",
            "Make the giraffe move into the red area using the keyboard!",
            "Make the chest disappear when the giraffe touches it!",
            "Write a program to give your bee friend an animation!",
            "Write a program to open the door when your character touches it!",
            "Design a program to countdown, stop animation after OK display"
    };
    static constexpr std::string_view s_Validation = "Press Enter to validate";
};


#endif //TASKTEXT_HPP
