#pragma once
#include <d3dx9.h>

class Sprite
{
private:
	int id;

	int left;
	int top;
	int right;
	int bottom;

	LPDIRECT3DTEXTURE9 texture;

	LPD3DXSPRITE spriteHandler;

public:
	Sprite(int id, int left, int top, int right, int bottom, LPDIRECT3DTEXTURE9 texture);
	RECT GetRect();
	void Draw(float x, float y, int alpha = 255);
	void DrawFlipX(float x, float y, int alpha = 255);
};

typedef Sprite* LPSPRITE;
