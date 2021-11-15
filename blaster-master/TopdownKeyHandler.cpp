#include "TopdownKeyHandler.h"

void TopdownKeyHandler::KeyState(BYTE* states)
{
	Game* game = Game::GetInstance();
	TopdownJason* jason = ((TopdownScene*)scence)->GetPlayer();

	float vx = .0f, vy = .0f;

	if (game->IsKeyDown(DIK_UP))
	{
		vy += -JASON_SPEED;
	}
	if (game->IsKeyDown(DIK_DOWN))
	{
		vy += JASON_SPEED;
	}
	if (game->IsKeyDown(DIK_LEFT))
	{
		vx += -JASON_SPEED;
	}
	if (game->IsKeyDown(DIK_RIGHT))
	{
		vx += JASON_SPEED;
	}

	jason->SetSpeed(vx, vy);
}

void TopdownKeyHandler::OnKeyDown(int KeyCode)
{
	DebugOut(L"[INFO] KeyDown: %d\n", KeyCode);
}

void TopdownKeyHandler::OnKeyUp(int KeyCode)
{
	DebugOut(L"[INFO] KeyUp: %d\n", KeyCode);

	Game* game = Game::GetInstance();
	TopdownJason* jason = ((TopdownScene*)scence)->GetPlayer();

	float vx, vy;
	jason->GetSpeed(vx, vy);

	switch (KeyCode)
	{
	case DIK_UP:
	case DIK_DOWN:
		if (vx > 0)
		{
			jason->SetState(JASON_GO_RIGHT);
		}
		else if (vx < 0)
		{
			jason->SetState(JASON_GO_LEFT);
		}
		break;
	case DIK_LEFT:
	case DIK_RIGHT:
		if (vy > 0)
		{
			jason->SetState(JASON_GO_DOWN);
		}
		else if (vy < 0)
		{
			jason->SetState(JASON_GO_UP);
		}
		break;
	default:
		break;
	}
}
