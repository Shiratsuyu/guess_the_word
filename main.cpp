#include <iostream>
#include "table.h"
#include "guess.h"
#include "global.h"

using namespace std;
table *wt;	//指向单词表对象的指针
guess *word;	//指向被猜单词对象的指针
extern string putin;	//输入缓存
extern int number;	//主函数的int的临时存储

int main()
{
	wt = new table;
	start_game();
	wt->get_difficulty();
	while(1){
		word = new guess(wt->get_a_word());
		word->guessloop();
		cout<<"Try again？";
		if (!(yes_or_no())){
			cout<<"Thank you!"<<endl;
			exit(-1);
			delete wt;
		}
		cout<<"Do you want to change the difficulty? ";
		if (yes_or_no()) wt->get_difficulty();
	}
	return 0;
}