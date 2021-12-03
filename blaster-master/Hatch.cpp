#include "Hatch.h"

Hatch::Hatch(float x, float y)
{
	GameObject::SetPosition(x, y);

	animation = Animations::GetInstance()->Get(2000);
}

void Hatch::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
}

void Hatch::Update(DWORD dt)
{

}

void Hatch::Render()
{
	animation->Render(x, y);
}

void Hatch::SetState(int state)
{
}
