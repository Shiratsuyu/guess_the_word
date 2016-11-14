#include "global.h"
using namespace std;

string putin;
int number;

void start_game(){
	cout<<"Welcome to this game!"<<endl;
	cout<<"Do you want to play it?(yes/no) ";
	if (!(yes_or_no())) exit(-1);
}

bool yes_or_no(){
	do{
		getline(cin,putin);
	}while(!(putin[0]=='y'||putin[0]=='n'));
	if (putin[0]=='y'){
		return true;
	}else{
		return false;
	}
}

int get_a_random(int max){
	srand((int)time(NULL));
	int r = rand();
	r%=max;
	return ++r;
}