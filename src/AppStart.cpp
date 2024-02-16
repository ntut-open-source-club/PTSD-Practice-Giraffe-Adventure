#include "App.hpp"

#include "Util/Logger.hpp"

void App::Start() {
    LOG_TRACE("Start");

    m_Giraffe = std::make_shared<Character>(GA_RESOURCE_DIR"/Image/Character/giraffe.png");
    m_Giraffe->SetPosition({-112.5f, -140.5f});
    m_Giraffe->SetZIndex(50);
    m_Root.AddChild(m_Giraffe);


    m_Chest = std::make_shared<Character>(GA_RESOURCE_DIR"/Image/Character/chest.png");
    m_Chest->SetZIndex(5);
    m_Chest->SetPosition({197.5f, -3.5f});
    m_Chest->SetVisible(false);
    m_Root.AddChild(m_Chest);

    m_Bee = std::make_shared<Character>(GA_RESOURCE_DIR"/Image/Character/bee_1.png");
    m_Bee->SetZIndex(15);
    m_Bee->SetVisible(false);
    m_Root.AddChild(m_Bee);

    for (int i = 0; i < 3; ++i) {
        m_Doors.push_back(std::make_shared<Character>(GA_RESOURCE_DIR"/Image/Character/door_close.png"));
        m_Doors[i]->SetZIndex(10);
        m_Doors[i]->SetPosition({205.5f - 80.f * i, -3.5f});
        m_Doors[i]->SetVisible(false);
        m_Root.AddChild(m_Doors[i]);
    }

    m_PRM = std::make_shared<PhaseResourceManger>();
    m_Root.AddChildren(m_PRM->GetChildren());


    m_CurrentState = State::UPDATE;
}
