#pragma once
#include "GameObject.h"
#include "Character.h"

#define JASON_TOP_DOWN_HEIGHT 32
#define JASON_TOP_DOWN_WIDTH 24

#define	JASON_GO_UP 0
#define	JASON_GO_DOWN 1
#define	JASON_GO_LEFT 2
#define	JASON_GO_RIGHT 3

#define JASON_SPEED 0.1f

class Jason : public GameObject
{
private:
	float start_x;
	float start_y;
public:
	Jason(float x = 0.0f, float y = 0.0f);
	virtual void Update(DWORD dt);
	virtual void Render();

	//void Reset();

	//virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
};
