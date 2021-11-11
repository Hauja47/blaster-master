#include "Trigger.h"
#include "Game.h"

Trigger::Trigger()
{
	SetState(TRIGGER_GO_RIGHT);
	x = 0;
	y = 0;
	vx = vy = TRIGGER_SPEED;
}

void Trigger::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
}

void Trigger::Update(DWORD dt)
{
	int backBufferWidth = Game::GetInstance()->GetBackBufferWidth();
	int backBufferHeight = Game::GetInstance()->GetBackBufferHeight();

	GameObject::Update(dt);

	switch (GetState())
	{
	case TRIGGER_GO_UP:
		y += dy;

		if (y <= 0)
		{
			y == 0;

			vy = -vy;

			SetState(TRIGGER_GO_RIGHT);
		}
		break;
	case TRIGGER_GO_DOWN:
		y += dy;

		if (y >= backBufferHeight - TRIGGER_HEIGHT)
		{
			y = backBufferHeight - TRIGGER_HEIGHT;

			vy = -vy;

			SetState(TRIGGER_GO_LEFT);
		}
		break;
	case TRIGGER_GO_LEFT:
		x += dx;

		if (x <= 0)
		{
			x = 0;

			vx = -vx;

			SetState(TRIGGER_GO_UP);
		}
		break;
	case TRIGGER_GO_RIGHT:
		x += dx;

		if (x >= backBufferWidth - TRIGGER_WIDTH)
		{
			x = backBufferWidth - TRIGGER_WIDTH;

			vx = -vx;

			SetState(TRIGGER_GO_DOWN);
		}
		break;
	default:
		break;
	}
}

void Trigger::Render()
{
	LPANIMATION animation = NULL;

	switch (GetState())
	{
	case TRIGGER_GO_UP:
		animation = Animations::GetInstance()->Get(36004);
		break;
	case TRIGGER_GO_DOWN:
		animation = Animations::GetInstance()->Get(36003);
		break;
	case TRIGGER_GO_LEFT:
		animation = Animations::GetInstance()->Get(36002);
		break;
	case TRIGGER_GO_RIGHT:
		animation = Animations::GetInstance()->Get(36001);
		break;
	default:
		break;
	}

	animation->Render(x, y);
}
