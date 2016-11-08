#include "random.h"

int get_a_random(int max){
	srand((int)time(NULL));
	int r = rand();
	r%=max;
	return ++r;
}