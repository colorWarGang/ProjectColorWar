#include "Singleton.h"


Singleton::Singleton()
{
}


Singleton::~Singleton()
{
}

void Singleton::AddPoints(int p){
	points += p;
}

int Singleton::GetPoints(){
	return points;
}
