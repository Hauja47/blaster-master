#pragma once
#include <d3d9.h>
#include <unordered_map>
#include "dxutil.h"
#include "Sprite.h"

class Sprites
{
private:
	static Sprites* _instance;
	std::unordered_map<int, LPSPRITE> sprites;
public:
	static Sprites* GetInstance();

	LPSPRITE Get(int id);
	void Add(int id, int left, int top, int right, int bottom, LPDIRECT3DTEXTURE9 texture);

	~Sprites();
};
