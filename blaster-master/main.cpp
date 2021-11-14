#include <Windows.h>
#include <d3d9.h>
#include <d3dx9.h>

#include "Game.h"
#include "GameObject.h"
#include "Constants.h"
#include "Textures.h"

#include "Trigger.h"

#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")

Game* game;

Trigger* trigger;

bool isOver = false;

LRESULT WINAPI WinProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hWnd, msg, wParam, lParam);
}

HWND CreateGameWindow(HINSTANCE hInstance, int nCmdShow)
{
    //initialize window settings
    WNDCLASSEX wc;
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = (WNDPROC)WinProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = NULL;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wc.lpszMenuName = NULL;
    wc.lpszClassName = WINDOW_CLASS_NAME;
    wc.hIconSm = NULL;
    RegisterClassEx(&wc);

    //create a new window
    HWND window = CreateWindow(
        WINDOW_CLASS_NAME,
        MAIN_WINDOW_TITLE,
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        SCREEN_WIDTH,
        SCREEN_HEIGHT,
        NULL,
        NULL,
        hInstance,
        NULL
    );
    if (!window) return 0;

    //display the window
    ShowWindow(window, nCmdShow);
    UpdateWindow(window);

    return window;
}

void Update(DWORD timeBetweenLastAndNow)
{
    trigger->Update(timeBetweenLastAndNow);
}

void Render()
{
    LPDIRECT3DDEVICE9 d3ddev = game->GetDirect3DDevice();
    LPDIRECT3DSURFACE9 backBuffer = game->GetBackBuffer();
    LPD3DXSPRITE spriteHandler = game->GetSpriteHandler();

    if (d3ddev->BeginScene())
    {
        d3ddev->ColorFill(backBuffer, NULL, BACKGROUND_COLOR);

        spriteHandler->Begin(D3DXSPRITE_ALPHABLEND);

        trigger->Render();

        spriteHandler->End();
        d3ddev->EndScene();
    }

    d3ddev->Present(NULL, NULL, NULL, NULL);
}

void Run()
{
    // main message loop
    MSG message;
    DWORD frameStart = GetTickCount();
    DWORD tickPerFrame = 1000 / MAX_FRAME_RATE;

    while (!isOver)
    {
        if (PeekMessage(&message, NULL, 0, 0, PM_REMOVE))
        {
            if (message.message == WM_QUIT) isOver = true;

            TranslateMessage(&message);
            DispatchMessage(&message);
        }

        DWORD now = GetTickCount();
        DWORD timeBetweenLastAndNow = now - frameStart;

        if (timeBetweenLastAndNow >= tickPerFrame)
        {
            frameStart = now;
            Update(timeBetweenLastAndNow);
            Render();
        }
        else
        {
            Sleep(tickPerFrame - timeBetweenLastAndNow);
        }
    }
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    HWND hWnd = CreateGameWindow(hInstance, nCmdShow);
    game = Game::GetInstance();
    game->Init(hWnd);

    LoadResource();
    Run();

    return 0;
}