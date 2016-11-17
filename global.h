#ifndef GOLBAL_H
#define GOLBAL_H

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "table.h"
#include "score.h"

extern std::string putin;
extern int number;

void start_game();
void main_map(std::string player,int difficulty,int point1,int point2);
bool yes_or_no();
int get_a_random(int max);

#endif