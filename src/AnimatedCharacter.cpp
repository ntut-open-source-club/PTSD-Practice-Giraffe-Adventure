#include "AnimatedCharacter.hpp"


AnimatedCharacter::AnimatedCharacter(const std::vector<std::string>& AnimationPaths) {
    m_Drawable = std::make_shared<Util::Animation>(AnimationPaths, 100, false, 0);
    auto temp = std::dynamic_pointer_cast<Util::Animation>(m_Drawable);
    temp->SetLooping(true);
}

bool AnimatedCharacter::IfAnimationEnds() const {
//    auto animation = std::dynamic_pointer_cast<std::shared_ptr<Util::Animation>>(m_Drawable)->get();
//        return animation->GetCurrentIndex() == animation->GetFrames().size() - 1;
    return true;
}
