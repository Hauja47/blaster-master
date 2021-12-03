#include "Sophia.h"

Sophia::Sophia(float x, float y)
{
	start_x = x;
	start_y = y;

	this->x = x;
	this->y = y;

	SetState(SOPHIA_GO_LEFT);
	hatch = new Hatch(x, y);
	body = new Body(x + 1.0, y + 9.0);
	gun = new Gun(x - 8.0, y);
	wheels.push_back(new Wheel(x - 7.0, y + 10.0));
	wheels.push_back(new Wheel(x + 9.0, y + 10.0));
}

void Sophia::Update(DWORD dt)
{
	//GameObject::Update(dt);
}

void Sophia::Render()
{
	hatch->Render();

	body->Render();

	gun->Render();

	wheels[0]->Render();
	int frame = wheels[0]->GetAnimation()->GetCurrentFrame();
	wheels[1]->RenderByFrame(++frame > 3 ? 0 : frame);
}

void Sophia::SetState(int state)
{
	
}

void Sophia::Reset()
{

}

void Sophia::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{

}
