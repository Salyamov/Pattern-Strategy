#pragma once
#pragma warning(disable : 26812)
#include <SDL_image.h>
#include <memory>
#include "RndGenerator.h"

using std::unique_ptr;
using std::make_unique;

class Game;

enum DIR {UP, LEFT, DOWN, RIGHT};

class MoveBehavior
{
public:
	int switchMoveDirectionTimer;
	int shotTimer;
	DIR direction;
	Rnd r;
	int x;
	int y;

	void updateSwitchMoveDirectionTimer();
	void updateShotTimer();

public:
	virtual void move() = 0;
};

class MoveSlow : public MoveBehavior
{
public:
	void move();
};

class MoveModerate : public MoveBehavior
{
public:
	void move();
};

class MoveFast : public MoveBehavior
{
public:
	void move();
};


class Tank
{
	SDL_Texture* texture;
protected:
	unique_ptr<MoveBehavior> moveComponent;
public:
	Tank(int x_, int y_, unique_ptr<MoveBehavior> mv);
	virtual ~Tank() { if (texture) SDL_DestroyTexture(texture); }
	virtual void move() = 0;
	void draw();
};

class LightTank : public Tank
{
	
public:
	LightTank(int x_, int y_) : Tank(x_, y_, make_unique<MoveFast>())  { }
	void move();
};

class MediumTank : public Tank
{
public:
	MediumTank(int x_, int y_) : Tank(x_, y_, make_unique<MoveModerate>()) { }
	void move();
};

class HeavyTank : public Tank
{
public:
	HeavyTank(int x_, int y_) : Tank(x_, y_, make_unique<MoveSlow>()) { }
	void move();
};