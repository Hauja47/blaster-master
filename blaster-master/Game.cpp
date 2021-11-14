#include "Game.h"

#include "debug.h"

Game* Game::_instance = NULL;

Game::Game()
{
}

Game* Game::GetInstance()
{
	if (_instance == NULL)
	{
		_instance = new Game();
	}

	return _instance;
}

LPDIRECT3DTEXTURE9 Game::LoadTexture(LPCWSTR texturePath, D3DCOLOR transparentColor)
{
	D3DXIMAGE_INFO imageInfo;
	LPDIRECT3DTEXTURE9 texture;

	HRESULT result = D3DXGetImageInfoFromFile(texturePath, &imageInfo);
	if (result != D3D_OK)
	{
		MessageBox(hWnd, L"Can not get image from file", L"Error!", MB_ICONERROR);
		return NULL;
	}

	LPDIRECT3DDEVICE9 d3ddv = Game::GetInstance()->GetDirect3DDevice();

	result = D3DXCreateTextureFromFileEx(
		d3ddv,
		texturePath,
		imageInfo.Width,
		imageInfo.Height,
		1,
		D3DUSAGE_DYNAMIC,
		D3DFMT_UNKNOWN,
		D3DPOOL_DEFAULT,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		transparentColor,
		&imageInfo,
		NULL,
		&texture
	);
	if (result != D3D_OK)
	{
		MessageBox(hWnd, L"Can not create texture from file", L"Error!", MB_ICONERROR);
		return NULL;
	}

	return texture;
}

LPDIRECT3DDEVICE9 Game::GetDirect3DDevice()
{
	return this->d3ddev;
}

LPDIRECT3DSURFACE9 Game::GetBackBuffer()
{
	return this->backBuffer;
}

LPD3DXSPRITE Game::GetSpriteHandler()
{
	return this->spriteHandler;
}

void Game::InitKeyboard()
{
	HRESULT result = DirectInput8Create(
		(HINSTANCE)GetWindowLong(hWnd, GWLP_HINSTANCE),
		DIRECTINPUT_VERSION,
		IID_IDirectInput8,
		(VOID**)&di,
		NULL
	);
	if (result != DI_OK)
	{
		DebugOut(L"[ERROR] DirectInput8Create failed!\n");
		return;
	}

	result = di->CreateDevice(GUID_SysKeyboard, &didev, NULL);
	if (result != DI_OK)
	{
		DebugOut(L"[ERROR] CreateDevice failed!\n");
		return;
	}

	result = didev->SetDataFormat(&c_dfDIKeyboard);

	result = didev->SetCooperativeLevel(hWnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);

	DIPROPDWORD dipdw;

	dipdw.diph.dwSize = sizeof(DIPROPDWORD);
	dipdw.diph.dwHeaderSize = sizeof(DIPROPHEADER);
	dipdw.diph.dwObj = 0;
	dipdw.diph.dwHow = DIPH_DEVICE;
	dipdw.dwData = KEYBOARD_BUFFER_SIZE;

	result = didev->SetProperty(DIPROP_BUFFERSIZE, &dipdw.diph);

	result = didev->Acquire();
	if (result != DI_OK)
	{
		DebugOut(L"[ERROR] DINPUT8::Acquire failed!\n");
		return;
	}

	DebugOut(L"[INFO] Keyboard has been initialized successfully\n");
}

void Game::ProcessKeyboard()
{
	HRESULT hr = didev->GetDeviceState(sizeof(keyStates), keyStates);

	if (FAILED(hr))
	{
		if ((hr == DIERR_INPUTLOST) || (hr == DIERR_NOTACQUIRED))
		{
			HRESULT h = didev->Acquire();
			if (h == DI_OK)
			{
				DebugOut(L"[INFO] Keyboard re-acquired!\n");
			}
			else
			{
				return;
			}
		}
		else
		{
			DebugOut(L"[ERROR] DINPUT::GetDeviceState failed. Error: %d\n", hr);
			return;
		}
	}

	keyHandler->KeyState((BYTE*)&keyStates);

	DWORD dwElements = KEYBOARD_BUFFER_SIZE;
	hr = didev->GetDeviceData(sizeof(DIDEVICEOBJECTDATA), keyEvents, &dwElements, 0);
	if (FAILED(hr))
	{
		DebugOut(L"[ERROR] DINPUT::GetDeviceData failed. Error: %d\n", hr);
		return;
	}

	for (DWORD i = 0; i < dwElements; i++)
	{
		int keyCode = keyEvents[i].dwOfs;
		int keyState = keyEvents[i].dwData;
		if ((keyState & 0x80) > 0)
		{
			keyHandler->OnKeyDown(keyCode);
		}
		else
		{
			keyHandler->OnKeyUp(keyCode);
		}
	}
}

void Game::Init(HWND hWnd)
{
	d3d = Direct3DCreate9(D3D_SDK_VERSION);
	if (!d3d)
	{
		OutputDebugString(L"[ERROR] Direct3DCreate9 failed\n");
		return;
	}

	this->hWnd = hWnd;

	D3DPRESENT_PARAMETERS d3dpp;

	ZeroMemory(&d3dpp, sizeof(d3dpp));

	d3dpp.Windowed = true;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8;
	d3dpp.BackBufferCount = 1;

	RECT r;
	GetClientRect(hWnd, &r);

	d3dpp.BackBufferHeight = r.bottom + 1;
	d3dpp.BackBufferWidth = r.right + 1;

	backBufferHeight = d3dpp.BackBufferHeight;
	backBufferWidth = d3dpp.BackBufferWidth;

	d3d->CreateDevice(
		D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		hWnd,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&d3dpp,
		&d3ddev
	);

	if (d3ddev == NULL)
	{
		OutputDebugString(L"[ERROR] CreateDevice failed\n");
		return;
	}

	d3ddev->GetBackBuffer(0, 0, D3DBACKBUFFER_TYPE_MONO, &backBuffer);

	D3DXCreateSprite(d3ddev, &spriteHandler);

	OutputDebugString(L"InitGame completed\n");
}

void Game::Update()
{

}

void Game::Draw(float x, float y, LPDIRECT3DTEXTURE9 texture, int left, int top, int right, int bottom, int alpha)
{
	D3DXVECTOR3 vector(x, y, 0);
	RECT r;
	r.left = left;
	r.right = right;
	r.bottom = bottom;
	r.top = top;
	spriteHandler->Draw(texture, &r, NULL, &vector, D3DCOLOR_ARGB(alpha, 255, 255, 255));
}

int Game::IsKeyDown(int keyCode)
{
	return (keyStates[keyCode] & 0x80) > 0;
}

int Game::GetBackBufferWidth()
{
	return backBufferWidth;
}

int Game::GetBackBufferHeight()
{
	return backBufferHeight;
}

void Game::SetCamPos(float x, float y)
{
	//TODO
}

Game::~Game()
{
	if (spriteHandler != NULL)
	{
		spriteHandler->Release();
	}
	if (backBuffer != NULL)
	{
		backBuffer->Release();
	}
	if (d3ddev != NULL)
	{
		d3ddev->Release();
	}
	if (d3d != NULL)
	{
		d3d->Release();
	}
}
