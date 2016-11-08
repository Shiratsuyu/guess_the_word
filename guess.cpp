#include "guess.h"
using namespace std;

guess::guess(string getting){
	word = getting;
	check = new char;
	for (int i = 0; i < getting.size(); ++i) check[i]='-';
	check[getting.size()] = '\0';
	print = check;
	chance = 10;
	trying = 0;
}

guess::~guess(){
}

void guess::guessloop(){
	for (int i = 0; i < word.size(); ++i) check[i]=word[i];
	used = new std::vector<char>;
	do{
		cout<<"The word like this: "<<print<<endl;
		cout<<"You tried "<<trying<<" times, and you have "<<chance<<" chances left."<<endl;
		cout<<"now you can try typing a letter: ";
		cin>>putinchar;
		guesswork(putinchar);
	}while(chance>0&&print.find('-')!=string::npos);
	word = check;
	if (chance == 0){
		cout<<"Game Over!"<<endl;
		cout<<"You lost all the chance."<<endl;
		cout<<"The correctly word is: "<<word<<endl;
	}else{
		cout<<"Congratulations!"<<endl;
		cout<<"You get it!"<<endl;
		cout<<"Yes! The word is: "<<print<<endl;
	}
	delete used;
}

int guess::guesswork(char letter){
	if (letter<'a'||letter>'z'){
		cout<<"Illegally input!"<<endl;
		return 0;
	}else if (find(used->begin(),used->end(),letter)!=used->end()){
		cout<<"You have already been used \'"<<letter<<"\'!"<<endl;
		return 0;
	}
	size_t ergodic = word.find(letter);
	if (ergodic==string::npos){
		--chance;
		cout<<"No this letter! You have only "<<chance<<" chances left."<<endl;
	}else{
		do{
			print[ergodic] = letter;
			word[ergodic] = '-';
			ergodic = word.find(letter);
		}while(ergodic!=string::npos);
		cout<<"Yes,it is!"<<endl;
	}
	used->push_back(letter);
	++trying;
	return 0;
}