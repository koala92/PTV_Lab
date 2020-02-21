#include <stdlib.h>
#include <cstdlib>
#include <deque>
#include "Particle.h"
#include <iostream>
#include <fstream>
#include <direct.h>
using namespace std;

int num;
float dia;
float min_x;
float min_y;
float max_x;
float max_y;
deque<Particle> par;

int main(int argc, char* argv[] )
{
	srand(time(NULL));
	if (argc == 1) return 1;
	num = atoi(argv[1]);
	dia = atof(argv[2]);
	min_x = atof(argv[3]);
	min_y = atof(argv[4]);
	max_x = atof(argv[5]);
	max_y = atof(argv[6]);

	for (int i = 0; i < num; i++)
	{
		while (true)
		{
			Particle newp = Particle::RandomPosition(0, 0, 1023, 1023);
			if (newp.IsValidDistance(par, dia)) 
			{
				par.push_back(newp);
				break;
			}
		}
	
	}


	ofstream os;
	os.open("D:\\position.bin", ostream::binary);
	os.write(reinterpret_cast<const char*>(&num), sizeof(int));
	for (int i = 0; i < par.size(); i++) 
	{
		os.write(reinterpret_cast<const char*>(&par[i].x), sizeof(float));
		os.write(reinterpret_cast<const char*>(&par[i].y), sizeof(float));
	}

	os.close();

	return 0;
}