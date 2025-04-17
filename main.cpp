#include<bits/stdc++.h>
#ifdef _WIN32
#include <windows.h>
#define "clear" "cls"
#else 
#include <termios.h>
#endif
using namespace std;
const string PCname = "QQcat Linux";
map<string, string> password_db;
bool loginpage(string username, string password){
	return password_db[username] == password;
}
int main(){
	password_db["root"] = PCname;
	//boot
	printf("Starting");
	for(int i=1; i<=10; i++){
		sleep(500);
		cout << '.';
	}
	system("cls");
	//login
	cout<<endl;
	cout<<"\\*******************************"<<endl;
	cout<<"wangjy_DOS Login"<<endl;
	string user,password;
	cout<<"INPUT YOUR USERNAME:";
	cin>>user;
	cout<<endl;
	cout<<"INPUT YOUR PASSWORD:";
	cin>>password;
	if(loginpage(user,password)==true) {
		cout<<"WELCOME TO USE QQCAT LINUX"<<endl;
		cout<<"**********************************************************\\";
		sleep(1500);
		system("cls");
	}
	else{
		cout<<"USERNAME OR PASSWORD WRONG!!"<<endl;
		cout<<"INPUT YOUR USERNAME:";
		cin>>user;
		cout<<endl;
		cout<<"INPUT YOUR PASSWORD:";
		cin>>password;
	}
	system("cls");
	//dos system
	string issue;
	string user_LOGINED;
	string path="SYSTEM:\\qqcat\\Home\\DOS>>",path1;
	cout<<"\\****************************************DOS***************************************************************"<<endl;
	while(1){
		cout<<path;
		//spesial proseed
		system("cls");
		cout<<"\\****************************************DOS***************************************************************"<<endl;
		cout<<path;
		//end
		getline(cin,issue);
		if(issue=="Windows 10 command") system("start cmd.exe");
		else if(issue=="change_path ADMIN:\\114514") {
			path="ADMIN:\\114514>>";
		}
		else if(issue=="account ADMIN") {
			cout<<endl;
			cout<<"INPUT PASSWORD FOR ADMIN:";
			cin>>password;
			if(password=="admin"){
			user_LOGINED="ADMIN";
			path="SYSTEM:\\ADMIN\\Home\\DOS>>";
			}
		}
		else if(issue=="time"){
			cout << time(0);
		}
		else if(issue=="desktop") {
			system("cls");
			cout<<"\\****************************************DOS***************************************************************"<<endl;
		}
		else if(issue=="shut down") {
			cout<<"QQcat Linux is shutting.........................."<<endl;
			sleep(15000);
			return 0;
		}
	}
}
