#include "Body.h"

Body::Body(float x, float y)
{
	GameObject::SetPosition(x, y);

	animation = Animations::GetInstance()->Get(2004);
}

void Body::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
}

void Body::Update(DWORD dt)
{

}

void Body::Render()
{
	animation->RenderByFrame(x, y, 0);
}

void Body::SetState(int state)
{
}
