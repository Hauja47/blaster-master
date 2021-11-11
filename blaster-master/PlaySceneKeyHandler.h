#pragma once
#include "Scene.h"
#include "SceneKeyHandler.h"
#include "Jason.h"

class PlaySceneKeyHandler : public SceneKeyHandler
{
public:
	virtual void KeyState(BYTE* states);
	virtual void OnKeyDown(int KeyCode);
	virtual void OnKeyUp(int KeyCode) {};
	PlaySceneKeyHandler(Scene* s) : SceneKeyHandler(s) {};
};

