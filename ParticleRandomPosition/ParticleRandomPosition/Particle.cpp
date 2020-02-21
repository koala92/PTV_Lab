#include "Particle.h"



Particle::Particle()
{
}

Particle::Particle(float x, float y)
{
	this->x = x; this->y= y;
}
Particle::~Particle()
{
}


Particle Particle::RandomPosition(float min_x, float min_y, float max_x, float max_y)
{
	
	float x = (max_x - min_x)*rand() / (float)RAND_MAX + min_x;
	float y = (max_y - min_y)*rand() / (float)RAND_MAX + min_y;


	return  Particle(x, y);
}

bool Particle::IsValidDistance(deque<Particle> target, float dia)
{
	for (int i = 0; i < target.size(); i++)
	{
		float r = sqrt(pow(this->x - target[i].x, 2) + pow(this->y - target[i].y, 2));
		if (dia > r)return false;
	}
	return true;
}