#pragma once
#include "GameObject.h"

#define	GUN_LEFT		0
#define GUN_RIGHT		1
#define GUN_UP			2
#define GUN_UP_LEFT		3
#define GUN_UP_RIGHT	4

class Gun : public GameObject
{
public:
	Gun(float x = 0.0f, float y = 0.0f);

	void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	void Update(DWORD dt);
	void Render();
	void SetState(int state);
};

