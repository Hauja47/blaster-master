#include "SidescrollingKeyHandler.h"

void SidescrollingKeyHandler::KeyState(BYTE* states)
{
	Game* game = Game::GetInstance();
	GameObject* sophia = ((SidescrollingScene*)scene)->GetPlayer();

	float vx = .0f;

	if (game->IsKeyDown(DIK_LEFT))
	{
		vx -= SOPHIA_SPEED;
	}
	if (game->IsKeyDown(DIK_RIGHT))
	{
		vx += SOPHIA_SPEED;
	}

	sophia->SetSpeed(vx, 0);
}

void SidescrollingKeyHandler::OnKeyDown(int KeyCode)
{

}

void SidescrollingKeyHandler::OnKeyUp(int KeyCode)
{

}
