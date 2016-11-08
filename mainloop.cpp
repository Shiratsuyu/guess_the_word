#include "mainloop.h"
using namespace std;

int main()
{
	*wt = new table;
	while(loop){
		cout<<"Welcome to this game!"<<endl;
		cout<<"Do you want to play it?(yes/no) ";
		do{

		}while()
		cout<<"Please choose you difficulty(press '1' is easy,'2' is normal, '3' is hard):";
		int difficult;
		cin>>difficult;
		wt->get_difficulty(difficult);
		guess word(wt->get_a_word());

	}
	delete wt;
	return 0;
}