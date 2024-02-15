#include "App.hpp"

#include "Util/Logger.hpp"

void App::Start() {
    LOG_TRACE("Start");

    m_Background = std::make_shared<Character>(GA_RESOURCE_DIR"/phase21_background.bmp");
    m_Background->SetZIndex(-10);
    m_Root.AddChild(m_Background);

    m_Giraffe = std::make_shared<Character>(/*GA_RESOURCE_DIR"/giraffe.png"*/);
    m_Giraffe->SetZIndex(10);
    m_Root.AddChild(m_Giraffe);


    m_TaskText = std::make_shared<TaskText>();
    m_Root.AddChild(m_TaskText);

    m_CurrentState = State::UPDATE;
}
