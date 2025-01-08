// Camera.h: interface for the CCamera class.
//
//////////////////////////////////////////////////////////////////////

#pragma once

#define ROTATION_SENS	5
#define ZOOM_MAX		60
#define ZOOM_MIN		15
#define ZOOM_INTER		1
#define CAMERA_DEBUG	1
#define PERCF(x, y)		((float)x / 100.0f * (float)y)

typedef struct
{
	float	Zoom;
	float	RotationY;
	float	RotationZ;
	float	PositionZ;
	double	ClipX;
	float	ClipY;
	double	ClipZ;
	double	ClipX2;
	float	ClipY2;
	float	ClipZ2;
	float	ClipGL;
} DefaultData, *lpDefData;


struct CAMERA_ZOOM
{
	float MinPercent;
	float MaxPercent;
	float MinLimit;
	float MaxLimit;
	float Precision;
};

struct CAMERA_ADDR
{
	float* Zoom;
	float* RotX;
	float* RotY;
	double* PosZ;
	double* ClipX[2];
	float* ClipY[2];
	float* ClipGL;
};

struct CAMERA_INFO
{
	int IsLoad;
	float Zoom;
	float RotX;
	float RotY;
	double PosZ;
	double ClipX[2];
	float ClipY[2];
	float ClipGL;
};

class CCamera
{
public:
	CCamera();
	virtual ~CCamera();
	void Toggle();
	void Restore();
	void SetIsMove(BOOL IsMove);
	void SetCursorX(LONG CursorXX);
	void SetCursorY(LONG CursorYY);
	void Zoom(MOUSEHOOKSTRUCTEX* lpMouse);
	void Move(MOUSEHOOKSTRUCTEX* lpMouse);
	void SetCurrentValue();
	void SetDefaultValue();
	bool m_Enable;
	float		ZoomPercent;
	bool getEnabled();
					 
	static void RotateDmg(float& X, float& Y, float D);
	static void RotateFix();
	void SmartCameraZoom();
	DefaultData Default;
//private:

	//BOOL m_Enable;
	BOOL m_IsMove;
	LONG m_CursorX;
	LONG m_CursorY;
	CAMERA_ZOOM m_Zoom;
	CAMERA_ADDR m_Address;
	CAMERA_INFO m_Default;

	float Temp_Zoom_Value;
	float Temp_Zoom_ValueX;
};

extern CCamera gCamera;
