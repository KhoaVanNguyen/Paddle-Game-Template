
#include "SceneMain.h"

SceneMain::SceneMain(int _nCmdShow): CGame(_nCmdShow)
{
	//gameObj = new GameObject("ball.png");
}

void SceneMain::RenderFrame(LPDIRECT3DDEVICE9 d3ddv, int t)
{

	GameObject *gameObj = new GameObject("ball.png", 1, 1, 1);
	G_SpriteHandler->Begin(D3DXSPRITE_ALPHABLEND);
	gameObj->Draw(12, 12);
	G_SpriteHandler->End();
}

void SceneMain::ProcessInput(LPDIRECT3DDEVICE9 d3ddv, int Delta)
{
}

void SceneMain::LoadResources(LPDIRECT3DDEVICE9 d3ddv)
{
	LPDIRECT3DSURFACE9 background;
	background = CreateSurfaceFromFile(d3ddv, "background.jpg");
	d3ddv->StretchRect(background, NULL, G_BackBuffer, NULL, D3DTEXF_NONE);
}

void SceneMain::OnKeyDown(int KeyCode)
{

}

SceneMain::~SceneMain(void)
{
}
