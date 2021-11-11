#pragma once
#include "Sprite.h"

class Frame
{
private:
	DWORD time;
	LPSPRITE sprite;
public:
	Frame(LPSPRITE sprite, DWORD time);
	DWORD GetTime();
	LPSPRITE GetSprite();
};

typedef Frame* LPFRAME;
