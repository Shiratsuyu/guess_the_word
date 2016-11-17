#ifndef TABLE_H
#define TABLE_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include "global.h"

class table
{
private:
	enum difficulty
	{
		easy = 1,
		normal = 2,
		hard = 3
	};
	int diff;
	std::ifstream data; 
	std::vector<std::string> *wordtable;
public:
	table();
	~table();
	void change_difficulty();
	int get_difficulty();
	void reset();
	void formet();
	std::string get_a_word();
};

#endif