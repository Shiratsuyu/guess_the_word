#include "table.h"
using namespace std;

table::table(){
	data.open("words.dat");
}

table::~table(){
	data.close();
}

void table::get_difficulty(int choose){
	reset();
	wordtable = new vector<string>;
	ostringstream os;
	os<<data.rdbuf();
	string content,memory(os.str());
	size_t p;
	switch(choose){
		case easy:{
			p = memory.find("[easy]");
			cout<<p<<endl;
			break;
		}
		case normal:{
			p = memory.find("[normal]");
			cout<<p<<endl;
			break;
		}
		case hard:{
			p = memory.find("[hard]");
			cout<<p<<endl;
			break;
		}
		default:{
			cout<<"非法输入！"<<endl;
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
	cout<<(*wordtable)[5]<<endl;
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
	int rand = get_a_random(wordtable->size());
	cout<<endl<<(*wordtable)[rand]<<endl;
	return (*wordtable)[rand];
}