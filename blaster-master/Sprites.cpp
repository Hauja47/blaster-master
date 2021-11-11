#include "Sprites.h"

Sprites* Sprites::_instance = NULL;

Sprites* Sprites::GetInstance()
{
	if (_instance == NULL)
	{
		_instance = new Sprites();
	}
	return _instance;
}

LPSPRITE Sprites::Get(int id)
{
	return sprites[id];
}

void Sprites::Add(int id, int left, int top, int right, int bottom, LPDIRECT3DTEXTURE9 texture)
{
	LPSPRITE sprite = new Sprite(id, left, top, right, bottom, texture);
	sprites[id] = sprite;
}

Sprites::~Sprites()
{
	SAFE_DELETE(_instance);
}
