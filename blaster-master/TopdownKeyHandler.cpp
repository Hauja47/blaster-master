#include "TopdownKeyHandler.h"

void TopdownKeyHandler::KeyState(BYTE* states)
{
	Game* game = Game::GetInstance();
	TopdownJason* jason = ((TopdownScene*)scence)->GetPlayer();

	if (game->IsKeyDown(DIK_UP))
	{
		jason->SetSpeedY(-JASON_SPEED);
	}
	if (game->IsKeyDown(DIK_DOWN))
	{
		jason->SetSpeedY(JASON_SPEED);
	}
	if (game->IsKeyDown(DIK_LEFT))
	{
		jason->SetSpeedX(-JASON_SPEED);
	}
	if (game->IsKeyDown(DIK_RIGHT))
	{
		jason->SetSpeedX(JASON_SPEED);
	}
	else
	{
		jason->SetSpeed(0.0f, 0.0f);
	}
}

void TopdownKeyHandler::OnKeyDown(int KeyCode)
{
	DebugOut(L"[INFO] KeyDown: %d\n", KeyCode);

	TopdownJason* jason = ((TopdownScene*)scence)->GetPlayer();

	switch (KeyCode)
	{
	case DIK_UP:
		jason->SetState(JASON_GO_UP);
		break;
	case DIK_DOWN:
		jason->SetState(JASON_GO_DOWN);
		break;
	case DIK_LEFT:
		jason->SetState(JASON_GO_LEFT);
		break;
	case DIK_RIGHT:
		jason->SetState(JASON_GO_RIGHT);
		break;
	default:
		jason->SetIdleState();
		break;
	}
}
