#include <iostream>
#include "table.h"
#include "guess.h"
#include "score.h"
#include "global.h"
using namespace std;

table *wt;
guess *word;
score *user;
string choice;
extern string putin;
extern int number;

int main()
{
	wt = new table;
	user = new score;
	start_game();
	while(1){
		main_map(user->player_name(),wt->get_difficulty(),user->get_score(wt->get_difficulty()),user->get_score(4));
		cout<<"Type in a digit: ";
		getline(cin,choice);
		cout<<"--------------------------------------------------"<<endl;
		switch(choice[0]){
			case '1':
				if (user->player_name()=="") user->what_is_your_name();
				if (!(wt->get_difficulty())) wt->change_difficulty();
				word = new guess(wt->get_a_word());
				if (word->guessloop()) user->achieve(wt->get_difficulty());
				delete word;
				cin.get();
				break;
			case '2':
				if (user->player_name()!="") delete user;
				user = new score;
				user->what_is_your_name();
				cin.get();
				break;
			case '3':
				wt->change_difficulty();
				break;
			case '4':
				if (user->player_name()=="") cout<<"Please log in first!"<<endl;
				else user->print_info();
				break;
			case '5':
			cout<<"Thank you!"<<endl;
				delete wt;
				if (user->player_name()!="") delete user;
				exit(-1);
				break;
			default:
				break;
		}
		cout<<"--------------------------------------------------"<<endl;
	}
	return 0;
}