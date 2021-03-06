#pragma once
#include "KeyEventHandler.h"

class Scene
{
protected:
	KeyEventHandler* key_handler;
	int id;
	LPCWSTR sceneFilePath;
public:
	Scene(int id, LPCWSTR filePath);

	KeyEventHandler* GetKeyEventHandler();

	virtual void Load() = 0;
	virtual void Unload() = 0;
	virtual void Update(DWORD dt) = 0;
	virtual void Render() = 0;
};

