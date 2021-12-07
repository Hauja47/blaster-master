#include "Camera.h"

Camera* Camera::_instance = NULL;

Camera* Camera::GetInstance()
{
	if (_instance == NULL) 
		_instance = new Camera(); 
	
	return _instance;
}

Camera::Camera(float x, float y)
{
	/*viewport.x = x;
	viewport.y = y;*/
}

D3DXVECTOR2 Camera::Transform(float x, float y)
{
	D3DXMATRIX matrix;
	D3DXMatrixIdentity(&matrix);
	matrix._22 = -1;
	matrix._41 = -viewport.x;
	matrix._42 = viewport.y;

	D3DXVECTOR3 pos3(x, y, 1);
	D3DXVECTOR4 MatrixResult;
	D3DXVec3Transform(&MatrixResult, &pos3, &matrix);

	D3DXVECTOR2 result = D3DXVECTOR2(MatrixResult.x, MatrixResult.y);
	return result;
}

void Camera::Update()
{
}
