#include "App.hpp"

#include "Util/Logger.hpp"

void App::Start() {
    LOG_TRACE("Start");

    m_Giraffe = std::make_shared<Character>(GA_RESOURCE_DIR"/Image/Character/giraffe.png");
    m_Giraffe->SetZIndex(10);
    m_Root.AddChild(m_Giraffe);


    m_PRM = std::make_shared<PhaseResourceManger>();
    m_Root.AddChildren(m_PRM->GetChildren());


    m_CurrentState = State::UPDATE;
}
