#ifndef GUESS_H
#define GUESS_H

#include <iostream>
#include "table.h"

class guess
{
private:
	std::string word;	//存储原单词
	std::string print;	//存储将要被打印的单词
	std::vector<char> *used;	//存储已经被使用过的数组
	int chance,trying;	//剩余机会次数和已经输入的次数
	char putinchar;	//输入字母的缓存
	char *check;	//黑科技指针
public:
	guess(std::string getting);
	~guess();
	void guessloop();
	int guesswork(char letter);
};

#endif