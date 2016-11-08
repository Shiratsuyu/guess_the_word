#ifndef GUESS_H
#define GUESS_H

#include <iostream>
#include "table.h"

class guess
{
private:
	std::string word;
	int chance;
public:
	guess(std::string getting);
	~guess();
};

#endif