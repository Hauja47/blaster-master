#pragma once
#include "GameObject.h"
class Body : public GameObject
{
public:
	Body(float x = 0.0f, float y = 0.0f);

	void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	void Update(DWORD dt);
	void Render();
	void SetState(int state);
};

