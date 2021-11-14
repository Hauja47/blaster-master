#pragma once
#include <Windows.h>
#include <d3d9.h>
#include <d3dx9.h>

#include <dinput.h>

#include "KeyEventHandler.h"
#include "debug.h"
#include "SceneManager.h"

#define DIRECTINPUT_VERSION 0x0800

#define KEYBOARD_BUFFER_SIZE 1024

class Game
{
private:
	static Game* _instance;
	HWND hWnd;

	LPDIRECT3D9 d3d = NULL;
	LPDIRECT3DDEVICE9 d3ddev = NULL;

	LPDIRECT3DSURFACE9 backBuffer = NULL;
	LPD3DXSPRITE spriteHandler = NULL;

	LPDIRECTINPUT8 di;
	LPDIRECTINPUTDEVICE8 didev;

	BYTE keyStates[256];
	DIDEVICEOBJECTDATA keyEvents[KEYBOARD_BUFFER_SIZE];

	LPKEYEVENTHANDLER keyHandler;

	int backBufferHeight = 0;
	int backBufferWidth = 0;

public:
	Game();
	static Game* GetInstance();

	LPDIRECT3DTEXTURE9 LoadTexture(LPCWSTR texturePath, D3DCOLOR transparentColor);

	LPDIRECT3DDEVICE9 GetDirect3DDevice();
	LPDIRECT3DSURFACE9 GetBackBuffer();
	LPD3DXSPRITE GetSpriteHandler();

	void InitKeyboard();
	void SetKeyHandler(LPKEYEVENTHANDLER handler) { keyHandler = handler; }
	void ProcessKeyboard();
	void Init(HWND hWnd);
	void Update();

	void Draw(float x, float y, LPDIRECT3DTEXTURE9 texture, int left, int top, int right, int bottom, int alpha = 255);

	int IsKeyDown(int keyCode);

	int GetBackBufferWidth();
	int GetBackBufferHeight();

	void SetCamPos(float x, float y);

	~Game();
};

