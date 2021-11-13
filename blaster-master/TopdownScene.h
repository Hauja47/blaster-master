#pragma once
#include <vector>

#include "Scene.h"
#include "Textures.h"
#include "TopdownKeyHandler.h"

#include "TopdownJason.h"
#include "Trigger.h"

class TopdownScene : public Scene
{
protected:
	TopdownJason* jason;

	std::vector<GameObject*> listObj;
public:
	TopdownScene(int id);

	virtual void Load();
	virtual void Update(DWORD dt);
	virtual void Render();
	virtual void Unload();

	TopdownJason* GetPlayer();
};

