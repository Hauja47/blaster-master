#include "Sprite.h"
#include "Game.h"

Sprite::Sprite(int id, int left, int top, int right, int bottom, LPDIRECT3DTEXTURE9 texture)
{
	this->id = id;
	this->left = left;
	this->top = top;
	this->right = right;
	this->bottom = bottom;
	this->texture = texture;

	spriteHandler = Game::GetInstance()->GetSpriteHandler();
}

RECT Sprite::GetRect()
{
	RECT r;

	r.left = left;
	r.right = right;
	r.bottom = bottom;
	r.top = top;

	return r;
}

void Sprite::Draw(float x, float y, int alpha)
{
	D3DXVECTOR3 vector(x, y, 0);
	RECT r = GetRect();
	spriteHandler->Draw(texture, &r, NULL, &vector, D3DCOLOR_ARGB(alpha, 255, 255, 255));
}

void Sprite::DrawFlipX(float x, float y, int alpha)
{
	RECT r = GetRect();

	D3DXMATRIX AA, BB;
	spriteHandler->GetTransform(&AA);

	D3DXVECTOR2 scalingCenter(x, x);
	D3DXVECTOR2 scaling(-1.0f, 1.0f);
	D3DXMatrixTransformation2D(&BB, &scalingCenter, 0.0f, &scaling, NULL, 0.0f, NULL);
	D3DXMATRIX CC = AA * BB;
	spriteHandler->SetTransform(&CC);
	x -= abs(right - left);
	D3DXVECTOR3 p(x, y, 0);
	spriteHandler->Draw(texture, &r, NULL, &p, D3DCOLOR_ARGB(alpha, 255, 255, 255));
	spriteHandler->SetTransform(&AA);
}
