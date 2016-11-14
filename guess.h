#ifndef GUESS_H
#define GUESS_H

#include <iostream>
#include "table.h"

class guess
{
private:
	std::string word;
	std::string print;
	std::vector<char> *used;
	int chance,trying;
	char putinchar;
	char *check;
public:
	guess(std::string getting);
	~guess();
	void guessloop();
	int guesswork(char letter);
};

#endif