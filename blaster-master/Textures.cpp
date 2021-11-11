#include "Textures.h"
#include "Game.h"

Textures* Textures::_instance = NULL;

Textures::Textures()
{
}

Textures* Textures::GetInstance()
{
	if (_instance == NULL)
	{
		_instance = new Textures();
	}

	return _instance;
}

void Textures::Add(int id, LPCWSTR filePath, D3DCOLOR transparentColor)
{
	textures[id] = Game::GetInstance()->LoadTexture(filePath, transparentColor);
}

LPDIRECT3DTEXTURE9 Textures::Get(unsigned int i)
{
	return textures[i];
}

Textures::~Textures()
{
	SAFE_DELETE(_instance);
}
