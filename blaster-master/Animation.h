#pragma once
#include <vector>

#include "Sprites.h"
#include "Frame.h"

class Animation
{
private:
	DWORD lastFrameTime;
	int defaultTime;
	int currentFrame;
	std::vector<LPFRAME> frames;
public:
	Animation(int defaultTime);
	void Add(int spriteId, DWORD time = 0);
	void GetFrameByTime();
	void Render(float x, float y);
	void RenderFlipX(float x, float y);
};

typedef Animation* LPANIMATION;
