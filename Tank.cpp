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

Tank::Tank(int x_, int y_, MoveBehavior* mv)
{
	mv->x = x_;
	mv->y = y_;
	texture = IMG_LoadTexture(renderer, "tank.png");
	mv->direction = UP;
	mv->updateShotTimer();
	mv->updateSwitchMoveDirectionTimer();
	moveComponent = mv;
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
	
	SDL_RenderCopy(renderer, texture, &src, &dst);

}

void LightTank::move()
{
	moveComponent->move();
}

void MediumTank::move()
{
	moveComponent->move();
}

void HeavyTank::move()
{
	moveComponent->move();	
}

void MoveSlow::move()
{
	if (direction == UP) y -= 4;
	if (direction == DOWN) y += 4;
	if (direction == LEFT) x -= 4;
	if (direction == RIGHT) x += 4;

	shotTimer--;
	switchMoveDirectionTimer--;

	if (shotTimer <= 0)
		updateShotTimer();
	if (switchMoveDirectionTimer <= 0)
		updateSwitchMoveDirectionTimer();
}

void MoveModerate::move()
{
	if (direction == UP) y -= 2;
	if (direction == DOWN) y += 2;
	if (direction == LEFT) x -= 2;
	if (direction == RIGHT) x += 2;

	shotTimer--;
	switchMoveDirectionTimer--;

	if (shotTimer <= 0)
		updateShotTimer();
	if (switchMoveDirectionTimer <= 0)
		updateSwitchMoveDirectionTimer();
}

void MoveFast::move()
{
	if (direction == UP) y -= 1;
	if (direction == DOWN) y += 1;
	if (direction == LEFT) x -= 1;
	if (direction == RIGHT) x += 1;

	shotTimer--;
	switchMoveDirectionTimer--;

	if (switchMoveDirectionTimer <= 0)
		updateSwitchMoveDirectionTimer();
	if (shotTimer <= 0)
		updateShotTimer();
}
