
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
	//DrawBackground(d3ddv);
	G_SpriteHandler->Begin(D3DXSPRITE_ALPHABLEND);
	ball.Draw();
	leftPaddle.Draw();
	rightPaddle.Draw();
	G_SpriteHandler->End();
}

void SceneMain::ProcessInput(LPDIRECT3DDEVICE9 d3ddv, int Delta)
{
	ball.Move(); 
	
	int isScore = ball.IsScore();
	if (isScore == 2) {
		score2++;
	}
	else if (isScore == 1) {
		score1++;
	}
	if (IsKeyDown(DIK_UPARROW)) {
		leftPaddle.MoveUp();

		rightPaddle.MoveUp();
	}
	if (IsKeyDown(DIK_DOWNARROW)) {

		leftPaddle.MoveDown();

		rightPaddle.MoveDown();
	}
	//  constraint the paddle to the screen's edges
	leftPaddle.ConstrainPosition();
	rightPaddle.ConstrainPosition();

	//see if ball hit the paddle
	if ((CheckCollision(ball, leftPaddle) == 2) || (CheckCollision(ball, rightPaddle) == 2))
	{
		ball.SetVelocity(ball.VelX()*(-1), ball.VelY());
	}
	else if ((CheckCollision(ball, leftPaddle) == 1) || (CheckCollision(ball, rightPaddle) == 1))
	{
		ball.SetVelocity(ball.VelX(), ball.VelY()*(-1));
	}
}

void SceneMain::LoadResources(LPDIRECT3DDEVICE9 d3ddv)
{
	srand(time(NULL));
	//DrawBackground(d3ddv);
	ball.Init("ball.bmp", 1, 1, 1);
	ball.InitPosition();
	leftPaddle.Init("paddle.bmp", 1, 1, 1);
	leftPaddle.isLeft = true;
	rightPaddle.Init("paddle.bmp", 1, 1, 1);

	leftPaddle.InitPosition();
	rightPaddle.InitPosition();
}
void SceneMain::OnKeyDown(int KeyCode)
{
	

}

SceneMain::~SceneMain(void)
{
}
