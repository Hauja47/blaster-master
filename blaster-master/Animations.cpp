#include "Animations.h"

Animations* Animations::_instance = NULL;

void Animations::Add(int id, LPANIMATION animation)
{
	animations[id] = animation;
}

LPANIMATION Animations::Get(int id)
{
	return animations[id];
}

Animations* Animations::GetInstance()
{
	if (_instance == NULL)
	{
		_instance = new Animations();
	}
	return _instance;
}
