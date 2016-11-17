#ifndef SCORE_H
#define SCORE_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "global.h"


class score
{
private:
	std::fstream file;
	std::vector<std::string> *user;
	int goal[4];
	bool login;
public:
	score();
	~score();
	int what_is_your_name();
	void get_info();
	void print_info();
	std::string crate_user();
	std::string player_name();
	size_t check_name(std::string username);
	int get_user(std::string username);
	int get_score(int difficulty);
	void achieve(int difficulty);
};

#endif