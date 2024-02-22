#include "AnimatedCharacter.hpp"


AnimatedCharacter::AnimatedCharacter(const std::vector<std::string>& AnimationPaths) {
    m_Drawable = std::make_shared<Util::Animation>(AnimationPaths, false, 500, false, 0);
}

bool AnimatedCharacter::IfAnimationEnds() const {
    auto animation = std::dynamic_pointer_cast<std::shared_ptr<Util::Animation>>(m_Drawable)->get();
        return animation->GetCurrentFrameIndex() == animation->GetFrameCount() - 1;
}
