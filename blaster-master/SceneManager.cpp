#include "SceneManager.h"

SceneManager* SceneManager::_instance = NULL;

SceneManager::SceneManager()
{
}

SceneManager::~SceneManager()
{
}

SceneManager* SceneManager::GetInstance()
{
	if (_instance == NULL)
	{
		_instance = new SceneManager();
	}
	return _instance;
}

void SceneManager::SetScene(Scene* x)
{
	Scene* scene_temp = _scene;
	_scene = x;
	SAFE_DELETE(scene_temp);
}

void SceneManager::KeyState(BYTE* state)
{
	_scene->GetKeyEventHandler()->KeyState(state);
}

void SceneManager::OnKeyDown(int KeyCode)
{
	_scene->GetKeyEventHandler()->OnKeyDown(KeyCode);
}

void SceneManager::OnKeyUp(int KeyCode)
{
	_scene->GetKeyEventHandler()->OnKeyUp(KeyCode);
}

void SceneManager::LoadResources()
{

}

void SceneManager::Update(DWORD dt)
{
	_scene->Update(dt);
}

void SceneManager::Render()
{
	_scene->Render();
}

void SceneManager::Unload()
{
	_scene->Unload();
}

Scene* SceneManager::GetScene()
{
	return _scene;
}
