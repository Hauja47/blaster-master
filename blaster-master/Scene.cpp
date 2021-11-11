#include "Scene.h"

Scene::Scene(int id, LPCWSTR filePath)
{
	this->id = id;
	this->sceneFilePath = filePath;
}

KeyEventHandler* Scene::GetKeyEventHandler()
{
	return key_handler;
}
