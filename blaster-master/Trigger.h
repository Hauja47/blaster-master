#pragma once
#include "GameObject.h"
#include "Constants.h"

#define TRIGGER_HEIGHT 32
#define TRIGGER_WIDTH 22

#define	TRIGGER_GO_UP 0
#define	TRIGGER_GO_DOWN 1
#define	TRIGGER_GO_LEFT 2
#define	TRIGGER_GO_RIGHT 3

#define TRIGGER_SPEED 0.1f

class Trigger : public GameObject
{

public:
	Trigger();

	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	void Update(DWORD dt);
	void Render();
};
