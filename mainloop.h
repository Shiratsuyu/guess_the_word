#include <iostream>
#include "table.h"
#include "guess.h"

void exit(){
	goto end;
}

table *wt;	//指向单词表对象的指针
bool loop = true;	//游戏主循环判断
std::string putin;	//输入缓存