#pragma once
#include "GameObject.h"

#define	HATCH_LEFT		0
#define HATCH_RIGHT		1
#define HATCH_UP		2
#define HATCH_UP_LEFT	3
#define HATCH_UP_RIGHT	4

class Hatch : public GameObject
{
public:
	Hatch(float x = 0.0f, float y = 0.0f);

	void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	void Update(DWORD dt);
	void Render();
	void SetState(int state);
};

