#include "Animation.h"

Animation::Animation(int defaultTime)
{
	this->defaultTime = defaultTime;
	lastFrameTime = -1;
	currentFrame = -1;
}

void Animation::Add(int spriteId, DWORD time)
{
	int t = (time == 0 ? this->defaultTime : time);

	LPSPRITE sprite = Sprites::GetInstance()->Get(spriteId);
	LPFRAME frame = new Frame(sprite, t);
	frames.push_back(frame);
}

void Animation::GetFrameByTime()
{
	DWORD now = GetTickCount();
	if (currentFrame == -1)
	{
		currentFrame = 0;
		lastFrameTime = now;
	}
	else
	{
		DWORD t = frames[currentFrame]->GetTime();
		if (now - lastFrameTime > t)
		{
			currentFrame++;
			lastFrameTime = now;
			if (currentFrame == frames.size())
			{
				currentFrame = 0;
			}
		}
	}
}

void Animation::GetFrameByTime_Reverse()
{
	DWORD now = GetTickCount();
	if (currentFrame == frames.size())
	{
		currentFrame = frames.size() - 1;
		lastFrameTime = now;
	}
	else
	{
		DWORD t = frames[currentFrame]->GetTime();
		if (now - lastFrameTime > t)
		{
			currentFrame--;
			lastFrameTime = now;
			if (currentFrame == -1)
			{
				currentFrame = frames.size() - 1;
			}
		}
	}
}

void Animation::SetCurrentFrame(int frame)
{
	this->currentFrame = frame;
}

int Animation::GetCurrentFrame()
{
	return currentFrame;
}

void Animation::Render(float x, float y)
{
	GetFrameByTime();
	frames[currentFrame]->GetSprite()->Draw(x, y);
}

void Animation::RenderFlipX(float x, float y)
{
	GetFrameByTime();
	frames[currentFrame]->GetSprite()->DrawFlipX(x, y);
}

void Animation::RenderCurrentFrame(float x, float y)
{
	frames[currentFrame]->GetSprite()->Draw(x, y);
}

void Animation::RenderByFrame(float x, float y, int frame)
{
	frames[frame]->GetSprite()->Draw(x, y);
}

void Animation::Render_Reverse(float x, float y)
{
	GetFrameByTime_Reverse();
	frames[currentFrame]->GetSprite()->Draw(x, y);
}
