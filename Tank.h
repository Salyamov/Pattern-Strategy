#pragma once
#pragma warning(disable : 26812)
#include <SDL_image.h>
#include <memory>
#include "RndGenerator.h"

using std::unique_ptr;
using std::make_unique;

class Game;

enum DIR {UP, RIGHT, DOWN, LEFT};

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

class MoveRand : public MoveBehavior
{
public:
	void move();
};

class MoveLeftRight : public MoveBehavior
{
public:
	void move();
};

class MoveUpDown : public MoveBehavior
{
public:
	void move();
};

//новое поведение
class StayStill : public MoveBehavior
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
	void move() { moveComponent->move(); }
	void draw();
};

class LightTank : public Tank
{
	
public:
	LightTank(int x_, int y_) : Tank(x_, y_, make_unique<MoveRand>())  {}
};

class MediumTank : public Tank
{
public:
	MediumTank(int x_, int y_) : Tank(x_, y_, make_unique<MoveLeftRight>()) {}
};

class HeavyTank : public Tank
{
public:
	HeavyTank(int x_, int y_) : Tank(x_, y_, make_unique<MoveUpDown>()) {}
};

class MonumentTank : public Tank
{
public:
	MonumentTank(int x_, int y_) : Tank(x_, y_, make_unique<StayStill>()) {}
};