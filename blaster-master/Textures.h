#pragma once
#include <unordered_map>
#include <d3dx9.h>

#include "dxutil.h"

class Textures
{
private:
	static Textures* _instance;

	std::unordered_map<int, LPDIRECT3DTEXTURE9> textures;
public:
	Textures();
	static Textures* GetInstance();
	void Add(int id, LPCWSTR filePath, D3DCOLOR transparentColor);
	LPDIRECT3DTEXTURE9 Get(unsigned int i);

	~Textures();
};
