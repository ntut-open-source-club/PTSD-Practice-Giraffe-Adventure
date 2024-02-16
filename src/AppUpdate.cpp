#include "App.hpp"

#include "AppUtil.hpp"

#include "Util/Input.hpp"
#include "Util/Keycode.hpp"
#include "Util/Logger.hpp"


void App::ValidTask() {
    switch (m_Phase) {
        case Phase::CHANGE_CHARACTER_IMAGE:
            if (m_Giraffe->GetImagePath() == GA_RESOURCE_DIR"/giraffe.bmp") {
                m_Phase = Phase::ABLE_TO_MOVE;
                m_PRM->NextPhase();

            } else {
                LOG_DEBUG("The image is not correct");
            }
            break;

        case Phase::ABLE_TO_MOVE:
            if (isInsideTheSquare(*m_Giraffe)) {
                m_Phase = Phase::COLLIDE_DETECTION;
                m_PRM->NextPhase();
            } else {
                LOG_DEBUG("The giraffe is not inside the square");
            }
            break;
        case Phase::COLLIDE_DETECTION:
            if (m_Giraffe->IfCollides(*m_Chest)) {
                if (m_Chest->GetVisibility()) {
                    LOG_DEBUG("The giraffe collided with the chest but the chest is still visible");
                } else {
                    m_Phase = Phase::BEE_ANIMATION;
                    m_PRM->NextPhase();
                }
            } else {
                LOG_DEBUG("The giraffe is not colliding with the chest");
            }
            break;

        case Phase::BEE_ANIMATION:
            //TODO: Add the bee animation validation
            m_Phase = Phase::OPEN_THE_DOORS;
            m_PRM->NextPhase();
            break;

        case Phase::OPEN_THE_DOORS:
            //TODO: Add the door opening validation
            m_Phase = Phase::COUNTDOWN;
            m_PRM->NextPhase();
            break;

        case Phase::COUNTDOWN:
            // TODO: Add the countdown validation
            LOG_DEBUG("Congratulations! You have completed the Giraffe Adventure!");
            m_CurrentState = State::END;
            break;
    }
}


void App::Update() {

    if (Util::Input::IsKeyPressed(Util::Keycode::ESCAPE) ||
        Util::Input::IfExit()) {
        m_CurrentState = State::END;
    }

    if (m_EnterDown) {
        if (!Util::Input::IsKeyPressed(Util::Keycode::RETURN)) {
            m_PRM->NextPhase();
            ValidTask();
        }
    }
    m_EnterDown = Util::Input::IsKeyPressed(Util::Keycode::RETURN);

    m_Root.Update();
}
