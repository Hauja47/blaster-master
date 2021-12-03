#pragma once
#include "GameObject.h"

#define IS_IDLE 0
#define IS_RUN 1

#define RUN_ANI 2005

class Wheel : public GameObject
{
public:
	Wheel(float x = 0.0f, float y = 0.0f, int frame = -1);

	void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	void Update(DWORD dt);
	void Render();

	void RenderByFrame(int frame);
	void SetState(int state);
};
