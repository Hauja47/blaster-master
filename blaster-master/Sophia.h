#pragma once
#include "GameObject.h"
#include "Body.h"
#include "Gun.h"
#include "Hatch.h"
#include "Wheel.h"

#define SOPHIA_GO_LEFT 1
#define SOPHIA_GO_RIGHT 2
#define SOPHIA_AIM_DIAGONAL_LEFT 3
#define SOPHIA_AIM_DIAGONAL_RIGHT 4
#define SOPHIA_AIM_UP_LEFT 5
#define SOPHIA_AIM_UP_RIGHT 6

#define SOPHIA_JUMPING 10

#define SOPHIA_SPEED 0.1f
#define SOPHIA_JUMP_SPEED 0.5f

class Sophia : public GameObject
{
private:
	float start_x;
	float start_y;

	int direction;

	Body* body;
	Gun* gun;
	Hatch* hatch;
	std::vector<Wheel*> wheels;
public:
	Sophia(float x = 0.0f, float y = 0.0f);

	virtual void Update(DWORD dt);
	virtual void Render();
	virtual void SetState(int state);

	void Reset();

	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
};

