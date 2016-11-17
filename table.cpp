#include "table.h"
using namespace std;

table::table(){
	data.open("words.dat");
	diff = 0;
	if (!(data.is_open())){
		cout<<"error: not find \'words.dat\'!"<<endl;
		exit(-1);
	}
}

table::~table(){
	delete wordtable;
	data.close();
}

void table::change_difficulty(){
	reset();
	string number;
typing:
	cout<<"Please choose you difficulty(press '1' is easy,'2' is normal, '3' is hard):";
	getline(cin,number);
	if (number[0]>'3'||number[0]<'1'){
	cout<<"Just use 1/2/3 !"<<endl;
	goto typing;
	}
	wordtable = new vector<string>;
	stringstream ss;
	ss<<data.rdbuf();
	string content;
	size_t p;
	switch(number[0]){
		case '1':
			p = (ss.str()).find("[easy]");
			diff = easy;
			break;
		case '2':
			p = (ss.str()).find("[normal]");
			diff = normal;
			break;
		case '3':
			p = (ss.str()).find("[hard]");
			diff = hard;
			break;
		default:
			p = (ss.str()).find("[easy]");
			break;
	}
	data.seekg(p,ios::beg);
	getline(data,content);
	while(content!="[end]"){
		wordtable->push_back(content);
		getline(data,content);
	}
	formet();
}

int table::get_difficulty(){
	return diff;
}

void table::reset(){
	delete wordtable;
	data.seekg(0,ios::beg);
}

void table::formet(){
	for (int i = 1; i < wordtable->size(); ++i){
		char * p = (char *)(*wordtable)[i].c_str();
		while(!((*p)>='a'&&(*p)<='z')) ++p;
		string str(p);
		(*wordtable)[i] = str;
	}
}

string table::get_a_word(){
	int rand = get_a_random(wordtable->size()-1);
	return (*wordtable)[rand];
}