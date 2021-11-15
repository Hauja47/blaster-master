#include "TopdownJason.h"

TopdownJason::TopdownJason(float x, float y)
{
	start_x = x;
	start_y = y;

	this->x = x;
	this->y = y;

	SetState(JASON_IDLE_RIGHT);
}

void TopdownJason::SetSpeedX(float vx)
{
	this->vx = vx;
}

void TopdownJason::SetSpeedY(float vy)
{
	this->vy = vy;
}

void TopdownJason::Update(DWORD dt)
{
	GameObject::Update(dt);

	if (vx == 0 && vy == 0)
	{
		this->SetIdleState();
		return;
	}
	else
	{
		x += dx;
		y += dy;

		if (vx > 0)
		{
			if (this->GetState() == JASON_GO_UP || this->GetState() == JASON_GO_DOWN)
				return;
			this->SetState(JASON_GO_RIGHT);
		}
		else if (vx < 0)
		{
			if (this->GetState() == JASON_GO_UP || this->GetState() == JASON_GO_DOWN)
				return;
			this->SetState(JASON_GO_LEFT);
		}

		if (vy > 0)
		{
			if (this->GetState() == JASON_GO_LEFT || this->GetState() == JASON_GO_RIGHT)
				return;
			this->SetState(JASON_GO_DOWN);
		}
		else if (vy < 0)
		{
			if (this->GetState() == JASON_GO_LEFT || this->GetState() == JASON_GO_RIGHT)
				return;
			this->SetState(JASON_GO_UP);
		}
	}
}

void TopdownJason::Render()
{
	LPANIMATION animation = NULL;

	DebugOut(L"[INFO] Jason current state: %d\n", this->GetState());

	switch (GetState())
	{
	case JASON_IDLE_UP:
		animation = Animations::GetInstance()->Get(-00004);
		break;
	case JASON_IDLE_DOWN:
		animation = Animations::GetInstance()->Get(-00003);
		break;
	case JASON_IDLE_LEFT:
		animation = Animations::GetInstance()->Get(-00002);
		break;
	case JASON_IDLE_RIGHT:
		animation = Animations::GetInstance()->Get(-00002);
		animation->RenderFlipX(x, y);
		return;
	case JASON_GO_UP:
		animation = Animations::GetInstance()->Get(00004);
		break;
	case JASON_GO_DOWN:
		animation = Animations::GetInstance()->Get(00003);
		break;
	case JASON_GO_LEFT:
		animation = Animations::GetInstance()->Get(00002);
		break;
	case JASON_GO_RIGHT:
		animation = Animations::GetInstance()->Get(00002);
		animation->RenderFlipX(x, y);
		return;
	default:
		break;
	}

	animation->Render(x, y);
}

void TopdownJason::SetIdleState()
{
	switch (this->GetState())
	{
	case JASON_GO_UP:
		this->SetState(JASON_IDLE_UP);
		break;
	case JASON_GO_DOWN:
		this->SetState(JASON_IDLE_DOWN);
		break;
	case JASON_GO_LEFT:
		this->SetState(JASON_IDLE_LEFT);
		break;
	case JASON_GO_RIGHT:
		this->SetState(JASON_IDLE_RIGHT);
		break;
	default:
		break;
	}
}

void TopdownJason::SetState(int state)
{
	GameObject::SetState(state);

	/*switch (state)
	{
	case JASON_GO_UP:
		vy = -JASON_SPEED;
		break;
	case JASON_GO_DOWN:
		vy = JASON_SPEED;
		break;
	case JASON_GO_LEFT:
		vx = -JASON_SPEED;
		break;
	case JASON_GO_RIGHT:
		vx = JASON_SPEED;
		break;
	default:
		vx = 0.0f;
		vy = 0.0f;
		break;
	}*/
}

void TopdownJason::Reset()
{
}

void TopdownJason::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
}
