#pragma once
#include "Sprite.h"

class Camera
{
private:
	static Camera* _instance;

public:
	static Camera* GetInstance();
	D3DXVECTOR2 viewport;
	int maxSize, minSize;

	Camera() 
	{ 
		viewport.x = 0;
		viewport.y = 0;
	};
	Camera(float x, float y);
	D3DXVECTOR2 Transform(float x, float y);
	void Update();
};

