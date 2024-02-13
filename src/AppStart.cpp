#include "App.hpp"

#include "Util/Logger.hpp"

void App::Start() {
    LOG_TRACE("Start");

    m_CurrentState = State::UPDATE;
}
