#pragma once
#include <vector>

#include "Sprites.h"
#include "Frame.h"

#include "debug.h"

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
	void GetFrameByTime_Reverse();

	void SetCurrentFrame(int frame);
	int GetCurrentFrame();

	void Render(float x, float y);
	void RenderFlipX(float x, float y);
	void RenderCurrentFrame(float x, float y);
	void RenderByFrame(float x, float y, int frame);
	void Render_Reverse(float x, float y);
};

typedef Animation* LPANIMATION;
