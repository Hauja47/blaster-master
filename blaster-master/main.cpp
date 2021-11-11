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

void LoadResource()
{
    Textures* textures = Textures::GetInstance();

    textures->Add(ID_TEXTURES_ENEMIES, L"resources\\enemies\\enemies.png", D3DCOLOR_XRGB(255, 255, 255));
    textures->Add(ID_TEXTURES_PLAYER, L"resources\\character\\jason_and_sophia.png", D3DCOLOR_XRGB(0, 57, 115));

    Sprites* sprites = Sprites::GetInstance();

    Animations* animations = Animations::GetInstance();
    LPANIMATION animation;

    #pragma region Load Trigger sprite

    LPDIRECT3DTEXTURE9 textureTrigger = textures->Get(ID_TEXTURES_ENEMIES);

    // Go right
    sprites->Add(360011, 132, 813, 154, 844, textureTrigger);
    sprites->Add(360012, 158, 812, 180, 844, textureTrigger);
    sprites->Add(360013, 184, 813, 206, 844, textureTrigger);

    animation = new Animation(100);
    animation->Add(360011);
    animation->Add(360012);
    animation->Add(360013);
    animations->Add(36001, animation);

    // Go left
    sprites->Add(360021, 48, 813, 70, 844, textureTrigger);
    sprites->Add(360022, 74, 812, 96, 844, textureTrigger);
    sprites->Add(360023, 100, 813, 122, 844, textureTrigger);

    animation = new Animation(100);
    animation->Add(360021);
    animation->Add(360022);
    animation->Add(360023);
    animations->Add(36002, animation);

    // Go down
    sprites->Add(360031, 132, 779, 154, 811, textureTrigger);
    sprites->Add(360032, 157, 780, 179, 811, textureTrigger);
    sprites->Add(360033, 181, 780, 203, 811, textureTrigger);

    animation = new Animation(100);
    animation->Add(360031);
    animation->Add(360032);
    animation->Add(360033);
    animations->Add(36003, animation);

    // Go up
    sprites->Add(360041, 56, 780, 76, 811, textureTrigger);
    sprites->Add(360042, 79, 779, 99, 811, textureTrigger);
    sprites->Add(360043, 102, 780, 122, 811, textureTrigger);

    animation = new Animation(100);
    animation->Add(360041);
    animation->Add(360042);
    animation->Add(360043);
    animations->Add(36004, animation);

    #pragma endregion

    #pragma region Load Jason top-down sprite
    //LPDIRECT3DTEXTURE9 textureJason = textures->Get(ID_TEXTURES_PLAYER);

    //// Go right
    //sprites->Add(000011, 232, 69, 208, 101, textureJason);
    //sprites->Add(000012, 257, 69, 233, 101, textureJason);
    //sprites->Add(000013, 282, 69, 258, 101, textureJason);

    //animation = new Animation(100);
    //animation->Add(000011);
    //animation->Add(000012);
    //animation->Add(000013);
    //animations->Add(00001, animation);

    //// Go left
    //sprites->Add(000021, 208, 69, 232, 101, textureJason);
    //sprites->Add(000022, 233, 69, 257, 101, textureJason);
    //sprites->Add(000023, 258, 69, 282, 101, textureJason);

    //animation = new Animation(100);
    //animation->Add(000021);
    //animation->Add(000022);
    //animation->Add(000023);
    //animations->Add(00002, animation);

    //// Go down
    //sprites->Add(000031, 208, 3, 232, 35, textureJason);
    //sprites->Add(000032, 233, 3, 257, 35, textureJason);
    //sprites->Add(000033, 258, 3, 282, 35, textureJason);

    //animation = new Animation(100);
    //animation->Add(000031);
    //animation->Add(000032);
    //animation->Add(000033);
    //animations->Add(00003, animation);

    //// Go up
    //sprites->Add(000041, 208, 36, 232, 68, textureJason);
    //sprites->Add(000042, 233, 36, 257, 68, textureJason);
    //sprites->Add(000043, 258, 36, 282, 68, textureJason);

    //animation = new Animation(100);
    //animation->Add(000041);
    //animation->Add(000042);
    //animation->Add(000043);
    //animations->Add(00004, animation);
    #pragma endregion

    trigger = new Trigger();
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