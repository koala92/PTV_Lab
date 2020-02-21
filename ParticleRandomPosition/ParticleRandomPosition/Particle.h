#pragma once
//#include <random>
#include <cstdlib>
#include <time.h>
#include <math.h>
#include <deque>

using namespace std;

class Particle
{
public:
	Particle();
	Particle(float x,float y);
	~Particle();

public:
	float x;
	float y;

	static Particle	 RandomPosition(float min_x, float min_y, float max_x, float max_y);
	bool IsValidDistance(deque<Particle> target,float dia);
};

