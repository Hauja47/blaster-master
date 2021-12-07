#pragma once
#include "SceneKeyHandler.h"
#include "Game.h"
#include "Sophia.h"
#include "SidescrollingScene.h"

class SidescrollingKeyHandler :
    public SceneKeyHandler
{
public:
	virtual void KeyState(BYTE* states);
	virtual void OnKeyDown(int KeyCode);
	virtual void OnKeyUp(int KeyCode);
	SidescrollingKeyHandler(Scene* s) :SceneKeyHandler(s) {};
};

