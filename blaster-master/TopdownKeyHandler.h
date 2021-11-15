#pragma once
#include "SceneKeyHandler.h"

#include "TopdownJason.h"
#include "TopdownScene.h"
#include "Game.h"

#include "debug.h"

class TopdownKeyHandler : public SceneKeyHandler
{
public:
	virtual void KeyState(BYTE* states);
	virtual void OnKeyDown(int KeyCode);
	virtual void OnKeyUp(int KeyCode);
	TopdownKeyHandler(Scene* s) :SceneKeyHandler(s) {};
};

