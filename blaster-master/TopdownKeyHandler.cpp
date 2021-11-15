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

	TopdownJason* jason = ((TopdownScene*)scence)->GetPlayer();

	switch (KeyCode)
	{
	case DIK_UP:
		if (jason->GetState() == JASON_GO_LEFT || jason->GetState() == JASON_GO_RIGHT)
			return;
		jason->SetState(JASON_GO_UP);
		break;
	case DIK_DOWN:
		if (jason->GetState() == JASON_GO_LEFT || jason->GetState() == JASON_GO_RIGHT)
			return;
		jason->SetState(JASON_GO_DOWN);
		break;
	case DIK_LEFT:
		if (jason->GetState() == JASON_GO_UP || jason->GetState() == JASON_GO_DOWN)
			return;
		jason->SetState(JASON_GO_LEFT);
		break;
	case DIK_RIGHT:
		if (jason->GetState() == JASON_GO_UP || jason->GetState() == JASON_GO_DOWN)
			return;
		jason->SetState(JASON_GO_RIGHT);
		break;
	default:
		jason->SetIdleState();
		break;
	}
}
