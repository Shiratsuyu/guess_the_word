#include "score.h"
using namespace std;

score::score(){
	login = 0;
	file.open("user.sav");
	if (!(file.is_open()))
	{
		ofstream fout("user.sav");
		fout.close();
		file.open("user.sav");
		cout<<"Warning: \"user.sav\" not found, created a new file."<<endl;
	}
}

score::~score(){
	file.seekg(0,ios::beg);
	vector<string> cache;
	string exchange;
	while (!(file.eof())){
		getline(file,exchange);
		cache.push_back(exchange);
	}
	file.close();
	exchange = '['+(*user)[0]+']';
	int i = 0;
	while(exchange!=cache[i]) i++;
	for (int j = 1; j < 5; ++j){
		stringstream number;
		number<<goal[j-1];
		cache[i+j]=(*user)[j]+number.str();
	}
	ofstream rewrite("user.sav",ios::trunc);
	for (int i = 0; i < cache.size()-1; ++i) rewrite<<cache[i]<<endl;
	rewrite.close();
	cache.clear();
}

int score::what_is_your_name(){
	string putin;
putin:
	cout<<"Please enter your username: ";
	cin>>putin;
	cout<<putin<<endl;
	if (get_user(putin)){
		cout<<"This user does not exist!"<<endl;
		cout<<"Do you want to use another user name?(yes/no) ";
		if (yes_or_no()) goto putin;
	}else {
		login = true;
		return 0;
	}
	cout<<"Do you want to creat a new user?(yes/no) ";
	if (yes_or_no()){
		get_user(crate_user());
		login = true;
		return 0;
	}
	else return 1;
}

void score::get_info(){
	char *p;
	for (int i = 1; i < 5; ++i){
		char * p = (char *)(*user)[i].c_str();
		while(!((*p)>='0'&&(*p)<='9')) ++p;
		goal[i-1] = atoi(p);
		*p = '\0';
		p = (char *)(*user)[i].c_str();
		(*user)[i] = p;
	}
	cout<<"Welcome back, "<<(*user)[0]<<'!'<<endl;
}

string score::player_name(){
	if (login) return (*user)[0];
	else return "";
}

void score::print_info(){
	cout<<"Hello, "<<(*user)[0]<<'!'<<endl;
	cout<<"This is your score:"<<endl;
	for (int i = 0; i < 4; ++i)	cout<<(*user)[i+1]<<goal[i]<<endl;
}

string score::crate_user(){
type:
	cout<<"What's your name? ";
	cin>>putin;
	if (check_name(putin)!=string::npos){
		cout<<"This name is existed!"<<endl;
		goto type;
	}else{
		file.seekp(0,ios::end);
		file<<'['<<putin<<']'<<endl;
		file<<"easy = 0"<<endl;
		file<<"normal = 0"<<endl;
		file<<"hard = 0"<<endl;
		file<<"total = 0"<<endl;
	}
	cout<<"You have created a new user named: "<<putin<<endl;
	file.seekg(0,ios::beg);
	return putin;
}

size_t score::check_name(string username){
	username = '['+username+']';
	stringstream ss;
	ss<<file.rdbuf();
	return (ss.str()).find(username);
}

int score::get_user(string username){
	size_t p = check_name(username);
	if (p!=string::npos){
		user = new vector<string>;
		file.seekg(p,ios::beg);
		string line;
		for (int i = 0; i < 5; ++i){
			getline(file,line);
			user->push_back(line);
		}
		(*user)[0] = username;
		get_info();
	}else{
		file.seekg(0,ios::beg);
		return 1;
	}
	return 0;
}

int score::get_score(int difficulty){
	if (!login) return 0;
	else switch (difficulty){
		case 1:
			return goal[0];
		case 2:
			return goal[1];
		case 3:
			return goal[2];
		default:
			return goal[3];
	}
}

void score::achieve(int difficulty){
	switch (difficulty){
	case 1:
		++goal[0];
		++goal[3];
		cout<<"This is Easy mode, you have finished "<<goal[0]<<" words."<<endl;
		break;
	case 2:
		++goal[1];
		++goal[3];
		cout<<"This is Normal mode, you have finished "<<goal[1]<<" words."<<endl;
		break;
	case 3:
		++goal[2];
		++goal[3];
		cout<<"This is Hard mode, you have finished "<<goal[2]<<" words."<<endl;
		break;
	default:
		break;
	}
}