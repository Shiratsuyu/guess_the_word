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
	tips = false;
}

guess::~guess(){
}

int guess::guessloop(){
	for (int i = 0; i < word.size(); ++i) check[i]=word[i];
	used = new std::vector<char>;	//存储已经使用过的字母
	do{
		cout<<endl;
		cout<<"The word like this: "<<print<<endl;
		cout<<"You tried "<<trying<<" times, and you have "<<chance<<" chances left."<<endl;
		cout<<"now you can try typing a letter: ";
		cin>>putinchar;
		guesswork(putinchar);
	}while(chance>0&&print.find('-')!=string::npos);
	word = check;	//把word恢复成原单词
	cout<<endl;
	if (chance == 0){
		cout<<"Game Over!"<<endl;
		cout<<"You lost all the chance."<<endl;
		cout<<"The correctly word is: "<<word<<endl;
		delete used;
		return 0;
	}else{
		cout<<"Congratulations!"<<endl;
		cout<<"You get it!"<<endl;
		cout<<"Yes! The word is: "<<print<<endl;
		delete used;
		return 1;
	}
}

void guess::help(){
	int random;
	int i = 0;
	do{
		if (i<5) random = get_a_random(word.size());
		else random = i - 5;
		++i;
	}while(word.find(check[random])==string::npos);
	cout<<"The word have this letter: "<<check[random]<<endl;
	tips = true;
}

int guess::guesswork(char letter){
	if (letter=='?'&&tips==false){	//判断是否请求帮助
		help();
		return 0;
	}
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
		if (!tips) cout<<"If you need tips, you can type \'?\' to randomly get a letter in this word."<<endl;
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
