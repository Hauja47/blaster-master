#include "Gun.h"

Gun::Gun(float x, float y)
{
	GameObject::SetPosition(x, y);

	animation = Animations::GetInstance()->Get(2009);
}

void Gun::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
}

void Gun::Update(DWORD dt)
{
}

void Gun::Render()
{
	animation->Render(x, y);
}

void Gun::SetState(int state)
{
}
