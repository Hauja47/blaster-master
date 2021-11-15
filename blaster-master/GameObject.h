#pragma once
#include <Windows.h>
#include <d3d9.h>
#include <vector>

#include "Sprites.h"
#include "Animations.h"

class GameObject
{
protected:
	float x;
	float y;

	float vx;
	float vy;

	float dx;
	float dy;

	int state;

	DWORD dt;


public:
	GameObject();

	void SetPosition(float x, float y);
	void SetSpeed(float vx, float vy);
	void GetPosition(float& x, float& y);
	void GetSpeed(float& vx, float& vy);

	int GetState();

	void RenderBoundingBox();

	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom) = 0;
	virtual void Update(DWORD dt);
	virtual void Render() = 0;
	virtual void SetState(int state);

	~GameObject();
};
