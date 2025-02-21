#include "DashEffect.h"
#include "Animation.h"
#include "AnimationComponent.h"

DashEffect::DashEffect(Level* _level, const RectangleShapeData& _data, const string& _name) : Prop(_level, _data, _name)
{
    GetMesh()->SetOriginAtMiddle();
	dash = CreateComponent<AnimationComponent>();
    DashAnimation();
}

DashEffect::DashEffect(const DashEffect& _other) : Prop(_other)
{
    dash = GetComponent<AnimationComponent>();
    DashAnimation();
}

void DashEffect::DashAnimation()
{

    vector<SpriteData> _sprites =
    {
        SpriteData(Vector2i(0, 0), Vector2i(814, 512)),
        SpriteData(Vector2i(814, 0), Vector2i(814, 512)),
        SpriteData(Vector2i(1628, 0), Vector2i(814, 512)),
        SpriteData(Vector2i(2442, 0), Vector2i(814, 512)),
        SpriteData(Vector2i(3256, 0), Vector2i(814, 512)),
        SpriteData(Vector2i(4070, 0), Vector2i(814, 512)),
    };

    AnimationData _animationData = AnimationData(0.3f, _sprites, true, false);
    Animation* _dashAnimaion = new Animation("Dash", GetMesh()->GetShape(), _animationData);

    _animationData.notifies[6] = [&]()
        {
            dash->StopAnimation();
        };

    dash->AddAnimation(_dashAnimaion);
    dash->SetCurrentAnimation("Dash");
    dash->StartAnimation();
}


