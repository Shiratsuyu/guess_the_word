#include "table.h"
using namespace std;

table::table(){
	data.open("words.dat");
}

table::~table(){
	data.close();
}

void table::get_difficulty(){
	reset();
	extern int number;
	do{
		cout<<"Please choose you difficulty(press '1' is easy,'2' is normal, '3' is hard):";
		(cin>>number).get();
	}while(number<1||number>3);
	wordtable = new vector<string>;
	ostringstream os;
	os<<data.rdbuf();
	string content,memory(os.str());
	size_t p;
	switch(number){
		case easy:{
			p = memory.find("[easy]");
			break;
		}
		case normal:{
			p = memory.find("[normal]");
			break;
		}
		case hard:{
			p = memory.find("[hard]");
			break;
		}
		default:{
			p = memory.find("[easy]");
			break;
		}
	}
	data.seekg(p,ios::beg);
	getline(data,content);
	while(content!="[end]"){
		wordtable->push_back(content);
		getline(data,content);
		// cout<<content<<endl;
	}
	formet();
	// cout<<(*wordtable)[5]<<endl;
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