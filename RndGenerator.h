#pragma once
#include <random>

class Rnd
{
	std::random_device rd;
	std::mt19937 gen;
public:
	Rnd() : gen(rd()) { }
	int getNum(int right) { std::uniform_int_distribution<> distrib(0, right); return distrib(gen); }
	int getNum(int left, int right) { std::uniform_int_distribution<> distrib(left, right); return distrib(gen); }
};