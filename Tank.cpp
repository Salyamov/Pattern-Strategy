#include "Tank.h"
#include "Game.h"

void MoveBehavior::updateSwitchMoveDirectionTimer()
{
	direction = (DIR)r.getNum(3);
	switchMoveDirectionTimer = r.getNum(5);
}

void MoveBehavior::updateShotTimer()
{
	shotTimer = r.getNum(2);
}

Tank::Tank(int x_, int y_, unique_ptr<MoveBehavior> mv) : moveComponent(std::move(mv))
{
	moveComponent->x = x_;
	moveComponent->y = y_;
	texture = IMG_LoadTexture(renderer, "tank.png");
	moveComponent->direction = UP;
	moveComponent->updateShotTimer();
	moveComponent->updateSwitchMoveDirectionTimer();
}


void Tank::draw()
{
	SDL_Rect src;
	src.x = 0;
	src.y = 0;
	src.w = 10;
	src.h = 10;
	SDL_Rect dst;
	dst.x = moveComponent->x;
	dst.y = moveComponent->y;
	dst.w = 10;
	dst.h = 10;
	
	SDL_RenderCopyEx(renderer, texture, &src, &dst, moveComponent->direction * 90, 0, SDL_FLIP_NONE);

}

void MoveRand::move()
{
	//двигается случайным образом
	if (direction == UP) y -= 1;
	if (direction == DOWN) y += 1;
	if (direction == LEFT) x -= 1;
	if (direction == RIGHT) x += 1;

	shotTimer--;
	switchMoveDirectionTimer--;

	if (shotTimer <= 0)
		updateShotTimer();
	if (switchMoveDirectionTimer <= 0)
		updateSwitchMoveDirectionTimer();
}

void MoveLeftRight::move()
{
	//двигается в право-влево
	static int ct;

	ct++;

	if (ct < 20)
		direction = RIGHT;
	else if (ct < 40)
	{
		direction = LEFT;
	}
	else
		ct = 0;

	if (direction == RIGHT)
		x++;
	else if (direction == LEFT)
		x--;
	
}

void MoveUpDown::move()
{
	//двигается вверх-вниз ромбом
	static int ct;

	ct++;

	if (ct < 20)
	{
		direction = DOWN;
	}
		
	else if (ct < 40)
	{
		direction = UP;
	}
	else
		ct = 0;

	if (direction == UP)
		y--;
	else if (direction == DOWN)
		y++;
}

void StayStill::move()
{

}
