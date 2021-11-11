#include "Frame.h"

Frame::Frame(LPSPRITE sprite, DWORD time)
{
	this->sprite = sprite;
	this->time = time;
}

DWORD Frame::GetTime()
{
	return time;
}

LPSPRITE Frame::GetSprite()
{
	return sprite;
}
