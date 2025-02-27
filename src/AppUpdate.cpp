#include "App.hpp"

#include "Util/Input.hpp"
#include "Util/Keycode.hpp"

#include <chrono>
#include <thread>

void App::Update() {

    // TODO: Add your own logics to finish the tasks in README.md

    // 取得長頸鹿的當前位置
    auto giraffePosition = m_Giraffe.GetPosition();

    // 設定移動速度
    const float moveSpeed = 5.0f;
 
    // 檢查鍵盤輸入並更新長頸鹿的位置
    if (Util::Input::IsKeyPressed(Util::Keycode::UP)) {
        giraffePosition.y -= moveSpeed;
    }
    if (Util::Input::IsKeyPressed(Util::Keycode::DOWN)) {
        giraffePosition.y += moveSpeed;
    }
    if (Util::Input::IsKeyPressed(Util::Keycode::LEFT)) {
        giraffePosition.x -= moveSpeed;
    }
    if (Util::Input::IsKeyPressed(Util::Keycode::RIGHT)) {
        giraffePosition.x += moveSpeed;
    }
 
    // 更新長頸鹿的位置
    m_Giraffe.SetPosition(giraffePosition);
 
    // 檢查長頸鹿是否進入紅色區域
    if (IsInRedArea(giraffePosition)) {
        // 處理長頸鹿進入紅色區域的邏輯
    }
    // 定義倒數時間（秒）
    int countdownTime = 30;

    // 開始倒數
    while (countdownTime > 0) {
        // 顯示剩餘時間
        std::cout << "Time remaining: " << countdownTime << " seconds" << std::endl;
 
        // 等待一秒
        std::this_thread::sleep_for(std::chrono::seconds(1));
 
        // 減少倒數時間
        --countdownTime;
    }
 
     // 倒數結束，執行相應的遊戲邏輯
     std::cout << "Time's up!" << std::endl;
    /*
     *  Do not touch the code below as they serve the purpose for validating the tasks,
     *  rendering the frame, and exiting the game.
    */

    if (Util::Input::IsKeyPressed(Util::Keycode::ESCAPE) || Util::Input::IfExit()) {
        m_CurrentState = State::END;
    }

    if (m_EnterDown) {
        if (!Util::Input::IsKeyPressed(Util::Keycode::RETURN)) {
            ValidTask();
        }
    }
    m_EnterDown = Util::Input::IsKeyPressed(Util::Keycode::RETURN);

    m_Root.Update();
}
