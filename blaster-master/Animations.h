#pragma once
#include <unordered_map>

#include "Animation.h"

class Animations
{
private:
	static Animations* _instance;

	std::unordered_map<int, LPANIMATION> animations;
public:
	void Add(int id, LPANIMATION animation);
	LPANIMATION Get(int id);

	static Animations* GetInstance();
};

typedef Animations* LPANIMATIONSET;