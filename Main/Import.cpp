#include "stdafx.h"
#include "Import.h"

signed int sub_9CEBF0( double a1 )
{
	return (signed int)a1;
}

bool pCheckMouseOverMiddle(int x, int y, int w, int h)
{
	int Addr = (pWinWidth / pWinHeightReal / 2) - 320;
	return pCheckMouseOver(x + Addr, y, w, h);
}

void RenderBitmapMiddle(int ImageID, float PosX, float PosY, float Width, float Height, float Arg6, float Arg7, float ScaleX, float ScaleY, bool ScaleSize, bool ScalePosition, float ScaleAlpha)
{
	int Addr = (pWinWidth / pWinHeightReal / 2) - 320;

	RenderBitmap(ImageID, PosX + Addr, PosY, Width,  Height,  Arg6,  Arg7,  ScaleX,  ScaleY,  ScaleSize,  ScalePosition, ScaleAlpha);
}

void RenderBitmapRight(int ImageID, float PosX, float PosY, float Width, float Height, float Arg6, float Arg7, float ScaleX, float ScaleY, bool ScaleSize, bool ScalePosition, float ScaleAlpha)
{
	int Addr = pWinWidth / pWinHeightReal - 640;

	RenderBitmap(ImageID, PosX + Addr, PosY, Width,  Height,  Arg6,  Arg7,  ScaleX,  ScaleY,  ScaleSize,  ScalePosition, ScaleAlpha);
}

void CRenderImageMiddle(int a1, float a2, float a3, float a4, float a5)
{
	int Addr = (pWinWidth / pWinHeightReal / 2) - 320;

	pDrawGUI(a1, a2 + Addr, a3, a4, a5);
}

void CRenderImageRight(int a1, float a2, float a3, float a4, float a5)
{
	int Addr = pWinWidth / pWinHeightReal - 640;

	pDrawGUI(a1, a2 + Addr, a3, a4, a5);
}

void BarFormMiddle(float PosX, float PosY, float Width, float Height, float Arg5, int Arg6)
{
	int Addr = (pWinWidth / pWinHeightReal / 2) - 320;

	pDrawBarForm(PosX + Addr, PosY, Width,  Height,  Arg5,  Arg6);
}

void BarFormRight(float PosX, float PosY, float Width, float Height, float Arg5, int Arg6)
{
	int Addr = pWinWidth / pWinHeightReal - 640;

	pDrawBarForm(PosX + Addr, PosY, Width,  Height,  Arg5,  Arg6);
}

void pDrawButtonMiddle(DWORD ModelID, float X, float Y, float W, float H, float CurrentX, float CurrentY)
{
	int Addr = (pWinWidth / pWinHeightReal / 2) - 320;
	pDrawButton(ModelID, X + Addr, Y, W, H, CurrentX, CurrentY);
}


double sub_636450(float a1)
{
	return (float)((double)(unsigned int)pWinHeight * a1 / 480.0);
}

GLvoid GetDrawCircle(int ID, float X, float Y, float W, float CurrenX, float CurrenY, float SetScale, int ScaleSize, int ScalePosicion, float Alpha)
{
	float v14; // ST1C_4@1
	float v15; // ST18_4@1
	GLuint vertexcount; // ST1C_4@5
	float v33; // ST1C_4@5
	GLfloat angle; // ST1C_4@5
	GLfloat texturecoord[2]; // [sp+2Ch] [bp-40h]@5
	GLfloat VertexCoord[4]; // [sp+4Ch] [bp-20h]@5

	SetScale = SetScale / 2;
	//--
	W = W / 2;
	X = X + W;
	Y = Y + W;

	if ( ScalePosicion )
	{
		X = sub_636420( X );
		Y = sub_636450( Y );
	}

	if ( ScaleSize )
	{
		W = sub_636420( W );
	}

	v33 = (double)pWinHeight - Y;

	vertexcount = 20;

	GetBindTexture( ID );

	glBegin( GL_TRIANGLE_FAN );

	angle = 2.0 * 3.1415926 / vertexcount;
	//--
	if ( Alpha > 0.0 )
		glColor4f(1.0, 1.0, 1.0, Alpha);
	texturecoord[0] = CurrenX;
	texturecoord[1] = CurrenY;
	glTexCoord2fv(texturecoord);
	//--
	VertexCoord[0] = X;
	VertexCoord[1] = v33;
	VertexCoord[2] = 0.0;
	VertexCoord[3] = 1.0;
	glVertex4fv(VertexCoord);

	for(int i = 0; i < vertexcount ; i++) 
	{
		texturecoord[0] = (std::cos(angle * i) * SetScale) + CurrenX;
		texturecoord[1] = (std::sin(angle * i) * SetScale) + CurrenY;
		glTexCoord2fv(texturecoord);
		VertexCoord[0] = (std::cos(angle * i) * W) + X;
		VertexCoord[1] = (std::sin(angle * i) * -W) + v33;
		VertexCoord[2] = 0.0;
		VertexCoord[3] = 1.0;
		glVertex4fv(VertexCoord);
	}
	//--
	texturecoord[0] = ( 1.0 * SetScale ) + CurrenX;
	texturecoord[1] = ( 0.0 * SetScale ) + CurrenY;
	glTexCoord2fv(texturecoord);
	//--
	VertexCoord[0] = (1.0 * W) + X;
	VertexCoord[1] = (0.0 * -W) + v33;
	VertexCoord[2] = 0.0;
	VertexCoord[3] = 1.0;
	glVertex4fv(VertexCoord);
	//--
	if ( Alpha > 0.0 )
		glColor4f(1.0, 1.0, 1.0, 1.0);
	//--
	glEnd();
}



GLvoid GetDrawCircleTab(int ID, float X, float Y, float W, float CurrenX, float CurrenY, float SetScale, int ScaleSize, int ScalePosicion, float Alpha)
{


	float v14; // ST1C_4@1
	float v15; // ST18_4@1
	GLuint vertexcount; // ST1C_4@5
	float v33; // ST1C_4@5
	GLfloat angle; // ST1C_4@5
	GLfloat texturecoord[2]; // [sp+2Ch] [bp-40h]@5
	GLfloat VertexCoord[4]; // [sp+4Ch] [bp-20h]@5

	SetScale = SetScale;// / 2;
	//--
	W = W / 2;
	X = X + W;
	Y = Y + W;

	if ( ScalePosicion )
	{
		X = sub_636420( X );
		Y = sub_636450( Y );
	}

	if ( ScaleSize )
	{
		W = sub_636420( W );
	}

	v33 = (double)pWinHeight - Y;

	vertexcount = 20;

	GetBindTexture( ID );

	glBegin( GL_TRIANGLE_FAN );

	angle = 2.0 * 3.1415926 / vertexcount;
	//--
	if ( Alpha > 0.0 )
		glColor4f(1.0, 1.0, 1.0, Alpha);
	texturecoord[0] = CurrenX;
	texturecoord[1] = CurrenY;
	glTexCoord2fv(texturecoord);
	//--
	VertexCoord[0] = X;
	VertexCoord[1] = v33;
	VertexCoord[2] = 0.0;
	VertexCoord[3] = 1.0;
	glVertex4fv(VertexCoord);

	for(int i = 0; i < vertexcount ; i++) 
	{
		texturecoord[0] = (std::cos(angle * i) * SetScale) + CurrenX;
		texturecoord[1] = (std::sin(angle * i) * SetScale) + CurrenY;
		glTexCoord2fv(texturecoord);
		VertexCoord[0] = (std::cos(angle * i) * W) + X;
		VertexCoord[1] = (std::sin(angle * i) * -W) + v33;
		VertexCoord[2] = 0.0;
		VertexCoord[3] = 1.0;
		glVertex4fv(VertexCoord);
	}
	//--
	texturecoord[0] = ( 1.0 * SetScale ) + CurrenX;
	texturecoord[1] = ( 0.0 * SetScale ) + CurrenY;
	glTexCoord2fv(texturecoord);
	//--
	VertexCoord[0] = (1.0 * W) + X;
	VertexCoord[1] = (0.0 * -W) + v33;
	VertexCoord[2] = 0.0;
	VertexCoord[3] = 1.0;
	glVertex4fv(VertexCoord);
	//--
	if ( Alpha > 0.0 )
		glColor4f(1.0, 1.0, 1.0, 1.0);
	//--
	glEnd();
}