#pragma once
#include "GameObject.h"
class Ball : public GameObject
{
public:
	virtual void Move();
	void ResetPosition();
	int IsScore();
	Ball();
	~Ball();
};

