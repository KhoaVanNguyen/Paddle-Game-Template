
#include "SceneMain.h"
void DrawBackground(LPDIRECT3DDEVICE9 d3ddv) {
	LPDIRECT3DSURFACE9 background;
	background = CreateSurfaceFromFile(d3ddv, "background.jpg");
	d3ddv->StretchRect(background, NULL, G_BackBuffer, NULL, D3DTEXF_NONE);
}
SceneMain::SceneMain(int _nCmdShow): CGame(_nCmdShow)
{

}

void SceneMain::RenderFrame(LPDIRECT3DDEVICE9 d3ddv, int t)
{

	/*DrawBackground(d3ddv);

	G_SpriteHandler->Begin(D3DXSPRITE_ALPHABLEND);
	ball.Draw();
	leftPaddle.Draw();
	rightPaddle.Draw();
	G_SpriteHandler->End();*/
	if (d3ddv->BeginScene())
	{
		//// Clear back buffer with image
		DrawBackground(d3ddv);
		G_SpriteHandler->Begin(D3DXSPRITE_ALPHABLEND);
		//----- start drawing
		ball.Draw();
		leftPaddle.Draw();
		rightPaddle.Draw();
		//---- end drawing
		G_SpriteHandler->End();
		d3ddv->EndScene();
	}
	d3ddv->Present(NULL, NULL, NULL, NULL);
}

void SceneMain::ProcessInput(LPDIRECT3DDEVICE9 d3ddv, int Delta)
{
	if (IsKeyDown(DIK_UPARROW)) {

		leftPaddle.y -= 10;
	}
	if (IsKeyDown(DIK_DOWNARROW)) {

		leftPaddle.y += 10;
	}
}

void SceneMain::LoadResources(LPDIRECT3DDEVICE9 d3ddv)
{
	DrawBackground(d3ddv);
	ball.Init("ball.bmp", 1, 1, 1);
	leftPaddle.Init("paddle.bmp", 1, 1, 1);
	rightPaddle.Init("paddle.bmp", 1, 1, 1);
	ball.x = 20;
	ball.y = 40;
	leftPaddle.x = 40;
	leftPaddle.y = rightPaddle.y = G_ScreenHeight / 2;
	rightPaddle.x = G_ScreenWidth - 66;
}
void SceneMain::OnKeyDown(int KeyCode)
{
	

}

SceneMain::~SceneMain(void)
{
}
