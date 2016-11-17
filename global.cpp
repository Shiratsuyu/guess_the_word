#include "global.h"
using namespace std;

string putin;
int number;

void start_game(){
	cout<<"Welcome to this game!"<<endl;
	cout<<"Do you want to play it?(yes/no) ";
	if (!(yes_or_no())) exit(-1);
}

void main_map(string player,int difficulty,int point1,int point2){
	cout<<"┌────────────────────────────────────────────────┐"<<endl;
	cout<<"│                 Guess The Word                 │"<<endl;
	cout<<"├───┬───────────────────┬────────────────────────┤"<<endl;
	cout<<"│ 1 │ Start Game        │                        │";
	if (player=="") cout<<"\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b"<<"Try Now !"<<endl;
	else cout<<"\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b"<<"Try Again ?"<<endl;
	cout<<"├───┼───────────────────┼────────────────────────┤"<<endl;
	cout<<"│ 2 │ Change User       │                        │";
	if (player!="") cout<<"\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b"<<player<<endl;
	else cout<<"\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b"<<"Not login!"<<endl;
	cout<<"├───┼───────────────────┼────────────────────────┤"<<endl;
	cout<<"│ 3 │ Change Difficult  │                        │";
	cout<<"\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
	switch(difficulty){
		case 1:
			cout<<"Easy Mode"<<endl;
			break;
		case 2:
			cout<<"Normal Mode"<<endl;
			break;
		case 3:
			cout<<"Hard Mode"<<endl;
			break;
		default:
			cout<<"Not choose!"<<endl;
			break;
	}
	cout<<"├───┼───────────────────┼────────────────────────┤"<<endl;
	cout<<"│ 4 │ My Score          │                        │";
	cout<<"\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
	switch(difficulty){
		case 1:
			cout<<point1<<"/"<<point2<<" (Easy/Total)"<<endl;
			break;
		case 2:
			cout<<point1<<"/"<<point2<<" (Normal/Total)"<<endl;
			break;
		case 3:
			cout<<point1<<"/"<<point2<<" (Hard/Total)"<<endl;
			break;
		default:
			cout<<"No Data"<<endl;
			break;
	}
	cout<<"├───┼───────────────────┼────────────────────────┤"<<endl;
	cout<<"│ 5 │ Exit              │                        │"<<endl;
	cout<<"└───┴───────────────────┴────────────────────────┘"<<endl;
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