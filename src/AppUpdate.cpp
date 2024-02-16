#include "App.hpp"

#include "AppUtil.hpp"

#include "Util/Input.hpp"
#include "Util/Keycode.hpp"
#include "Util/Logger.hpp"
#include "Util/Time.hpp"


void App::ValidTask() {
    LOG_DEBUG("Validating the task {}", static_cast<int>(m_Phase));
    switch (m_Phase) {
        case Phase::CHANGE_CHARACTER_IMAGE:
//            if (m_Giraffe->GetImagePath() == GA_RESOURCE_DIR"/giraffe.png") {
            if (true) {
                m_Phase = Phase::ABLE_TO_MOVE;
                m_Giraffe->SetPosition({-112.5f, -140.5f});

                m_PRM->NextPhase();
            } else {
                LOG_DEBUG("The image is not correct");
            }
            break;

        case Phase::ABLE_TO_MOVE:
            if (isInsideTheSquare(*m_Giraffe)) {
                m_Phase = Phase::COLLIDE_DETECTION;
                m_Giraffe->SetPosition({-112.5f, -140.5f});
                m_Chest->SetVisible(true);

                m_PRM->NextPhase();
            } else {
                LOG_DEBUG("The giraffe is not inside the square");
            }
            break;

        case Phase::COLLIDE_DETECTION:
//            if (m_Giraffe->IfCollides(*m_Chest)) {
            if (true) {
//                if (m_Chest->GetVisibility()) {
                if (!true) {
                    LOG_DEBUG("The giraffe collided with the chest but the chest is still visible");
                } else {
                    m_Phase = Phase::BEE_ANIMATION;
                    m_Giraffe->SetVisible(false);
                    m_Bee->SetVisible(true);

                    m_PRM->NextPhase();
                }
            } else {
                LOG_DEBUG("The giraffe is not colliding with the chest");
            }
            break;

        case Phase::BEE_ANIMATION:
            if (m_Bee->IsLooping()) {
                //TODO: Add the bee animation validation
                m_Phase = Phase::OPEN_THE_DOORS;
                m_Giraffe->SetPosition({-112.5f, -140.5f});
                m_Giraffe->SetVisible(true);
                m_Bee->SetVisible(false);
                std::for_each(m_Doors.begin(), m_Doors.end(), [](const auto& door) { door->SetVisible(true); });

                m_PRM->NextPhase();
            } else {
                LOG_DEBUG("The bee animation is not correct");
            }

            break;

        case Phase::OPEN_THE_DOORS:
            if (AreAllDoorsOpen(m_Doors)) {
                m_Phase = Phase::COUNTDOWN;
                std::for_each(m_Doors.begin(), m_Doors.end(), [](const auto& door) { door->SetVisible(false); });
                m_Giraffe->SetVisible(false);

                m_PRM->NextPhase();
            } else {
                LOG_DEBUG("At least one door is not open");
            }
            break;

        case Phase::COUNTDOWN:
            if (m_Ball->IfAnimationEnds()) {
//            if (true) {
                LOG_DEBUG("Congratulations! You have completed Giraffe Adventure!");
                m_CurrentState = State::END;
            }
            break;
    }
}


void App::Update() {

    if (Util::Input::IsKeyPressed(Util::Keycode::UP)) {
        m_Giraffe->SetPosition(m_Giraffe->GetPosition() + glm::vec2(0.0F, 1.0F));
    }
    if (Util::Input::IsKeyPressed(Util::Keycode::DOWN)) {
        m_Giraffe->SetPosition(m_Giraffe->GetPosition() + glm::vec2(0.0F, -1.0F));
    }
    if (Util::Input::IsKeyPressed(Util::Keycode::LEFT)) {
        m_Giraffe->SetPosition(m_Giraffe->GetPosition() + glm::vec2(-1.0F, 0.0F));
    }
    if (Util::Input::IsKeyPressed(Util::Keycode::RIGHT)) {
        m_Giraffe->SetPosition(m_Giraffe->GetPosition() + glm::vec2(1.0F, 0.0F));
    }

    if (Util::Input::IsKeyPressed(Util::Keycode::A)) {
        m_Chest->SetVisible(false);
    }
    if (Util::Input::IsKeyPressed(Util::Keycode::S)) {
        m_Chest->SetVisible(true);
    }

    if (Util::Input::IsKeyPressed(Util::Keycode::D)) {
        std::for_each(m_Doors.begin(), m_Doors.end(), [](const auto& door) {
            door->SetImage(
                    GA_RESOURCE_DIR"/Image/Character/door_open.png");
        });
    }

    if (Util::Input::IsKeyPressed(Util::Keycode::F)) {
        std::for_each(m_Doors.begin(), m_Doors.end(), [](const auto& door) {
            door->SetImage(
                    GA_RESOURCE_DIR"/Image/Character/door_close.png");
        });
    }


    if (Util::Input::IsKeyPressed(Util::Keycode::ESCAPE) || Util::Input::IfExit()) {
        m_CurrentState = State::END;
    }

    if (m_EnterDown) {
        if (!Util::Input::IsKeyPressed(Util::Keycode::RETURN)) {
            LOG_DEBUG(glm::to_string(m_Giraffe->GetPosition()));
            ValidTask();
        }
    }
    m_EnterDown = Util::Input::IsKeyPressed(Util::Keycode::RETURN);

    m_Root.Update();
}
