#pragma once
#include "GameObject.h"

#define JASON_TOP_DOWN_HEIGHT 32
#define JASON_TOP_DOWN_WIDTH 24

#define	JASON_GO_UP 0
#define	JASON_GO_DOWN 1
#define	JASON_GO_LEFT 2
#define	JASON_GO_RIGHT 3

#define	JASON_IDLE_UP -11
#define	JASON_IDLE_DOWN -12
#define	JASON_IDLE_LEFT -13
#define	JASON_IDLE_RIGHT -14


#define JASON_SPEED 0.1f

class TopdownJason : public GameObject
{
private:
	float start_x;
	float start_y;
public:
	TopdownJason(float x = 0.0f, float y = 0.0f);

	void SetSpeedX(float vx);
	void SetSpeedY(float vy);

	void SetIdleState();

	virtual void Update(DWORD dt);
	virtual void Render();
	virtual void SetState(int state);

	void Reset();

	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
};

