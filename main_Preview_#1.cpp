#include <bits/stdc++.h>
using namespace std;

// 跨平台清屏命令定义
#ifdef _WIN32
#include <windows.h>
#define clear_cmd "cls"
#else 
#include <termios.h>
#define clear_cmd "clear"
#endif

// 跨平台终端命令定义
#ifdef _WIN32
#define Terminal_cmd "cmd"
#else
#define Terminal_cmd "bash"
#endif

// 工具函数：延时（毫秒）
void delay(int ms) {
    this_thread::sleep_for(chrono::milliseconds(ms));
}

// 工具函数：刷新输出屏幕与缓冲区
void flush(){
	system(clear_cmd);
	fflush(stdin);
	fflush(stdout);
}

// 登录界面+终端内容显示
string Terminal_name = "QQcat-Linux V1.2(Preview #1)";
map<string, string> user_to_password_db;
map<string, bool> user_available;
map<string, bool> dir_available;
void Terminal_DOS();
string cmd, current_path=" #", logged_user="root";
void Terminal_logon();

int main(){
	// 启动流程
	printf("Starting");
	for(int i=1; i<=10; i++){
		delay(500);
		printf(".");
	}
	printf("\n");
	flush();

	// 终端核心逻辑
	Terminal_logon();
}

void Terminal_DOS(){
	dir_available["/root"] = 1;
	while(1){
		cout << logged_user << '@' << Terminal_name << current_path << ' ';
		cin >> cmd; 
		// 唤起系统终端
		if (cmd == "systerminal") {
			printf("This command is not available!\n");
			// system(Terminal_cmd);
    	} // 切换目录
		else if (cmd == "cd") {
			string newpath;
			cin >> newpath;
			if(dir_available[newpath] == false)
				printf("cd : No such a directory, you must use \"mkdir\" command to make it first. \n");
			else 
				current_path = newpath;
		} 
		// 创建目录
		else if(cmd == "mkdir"){
			string newdir;
			cin >> newdir;
			dir_available[newdir] = 1;
		}
		//切换用户
		else if (cmd == "chuser") {
			string newuser;
			cin >> newuser;
			if(user_available[newuser] == false)
				printf("chuser : No such user name!\n");
			else {
				string pwd;
				cin >> pwd;
				if(user_to_password_db[newuser] == pwd)
					logged_user = newuser;
			}
		} 
		// 创建用户
		else if (cmd == "mkuser"){
			string newus, newup;
			cout << "Enter new user's name: ";
			cin >> newus;
			cout << "Enter password for " << newus << " :";
			cin >> newup;
			user_available[newus] = 1;
			user_to_password_db[newus] = newup;
		}
		else if (cmd == "time") {
			time_t now = time(0);
			cout << ctime(&now);
			delay(1000);
		} 
		else if (cmd == "clear") {
			flush();
			// cout << "\\****************************************DOS***************************************************************" << endl;
		} 
		else if (cmd == "exit") {
			cout << Terminal_name << " is shutting down.........................." << endl;
			delay(2000);  // 缩短关机等待时间，提升体验
			exit(0);
		} 
		
		else if (!cmd.empty()) {
			cout << "Unknown command." << endl;
			delay(1000);
		}
	}
}

void Terminal_logon(){
	// 初始化密码数据库
    user_to_password_db["root"] = "qqcat_terminal"; // 添加超管用户
	user_available["root"] = 1;
	// 核心逻辑
	flush();
	string user, pwd;
	int attempt = 0;
	cout << Terminal_name << " tty1" << '\n';
	// cout << "user Login:";

	while(1){
		cout << "user Login: ";
		cin >> user;
		cout << "Password: ";
		cin >> pwd;

		if(user_to_password_db[user]==pwd)
			break;
		else {
			printf("User or password incorrect.\n");
			delay(1001);
			continue;
		}
	}

	flush();
	Terminal_DOS();
}
