#include "Game.h"
#include "GameObject.h"
#include "Textures.h"
#include "Constants.h"

GameObject::GameObject()
{
	this->x = this->y = 0;
	this->vx = this->vy = 0;
}

void GameObject::SetPosition(float x, float y)
{
	this->x = x;
	this->y = y;
}

void GameObject::SetSpeed(float vx, float vy)
{
	this->vx = vx;
	this->vy = vy;
}

void GameObject::GetPosition(float& x, float& y)
{
	x = this->x;
	y = this->y;
}

void GameObject::GetSpeed(float& vx, float& vy)
{
	vx = this->vx;
	vy = this->vy;
}

void GameObject::Update(DWORD dt)
{
	this->dt = dt;
	dx = vx * dt;
	dy = vy * dt;
}

void GameObject::SetState(int state)
{
	this->state = state;
}

void GameObject::SetAnimation(LPANIMATIONSET animations)
{
	this->animations = animations;
}

int GameObject::GetState()
{
	return this->state;
}

void GameObject::RenderBoundingBox()
{
	D3DXVECTOR3 p(x, y, 0);
	RECT rect;

	LPDIRECT3DTEXTURE9 boundingBox = Textures::GetInstance()->Get(ID_TEX_BBOX); 
	float l, t, r, b;

	GetBoundingBox(l, t, r, b);
	rect.left = 0;
	rect.top = 0;
	rect.right = (int)r - (int)l;
	rect.bottom = (int)b - (int)t;

	Game::GetInstance()->Draw(x, y, boundingBox, rect.left, rect.top, rect.right, rect.bottom, 32);
}

GameObject::~GameObject()
{
}