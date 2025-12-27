#include "SystemFunc.hpp"

// 定义常量
const string USERS_JSON_FILE = "users.json";

int main(){
	// 初始化变量
	map<string, bool> dir_available;
	string logged_user = "root";  // 默认登录用户
	string current_path = "/root";  // 默认当前路径
	string cmd;
	
	// 初始化目录可用性
	dir_available["/root"] = true;
	
	// 从JSON文件加载用户数据
	map<string, string> user_to_password_db = load_users_from_json(USERS_JSON_FILE);
	map<string, bool> user_available;
	for (auto it = user_to_password_db.begin(); it != user_to_password_db.end(); ++it) {
		const string& user = it->first;
		user_available[user] = true;
	}
	
	while(1){
		cout << logged_user << '@' << Terminal_name << current_path << ' ';
		cin >> cmd; 
		// 唤起系统终端
		if (cmd == "systerminal") {
			// printf("This command is not available!\n");
			system(Terminal_cmd);
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
			dir_available[newdir] = true;
		}
		//切换用户
		else if (cmd == "chuser") {
			string newuser;
			cin >> newuser;
			if(user_available.count(newuser) == 0 || user_available[newuser] == false)
				printf("chuser : No such user name!\n");
			else {
				string pwd;
				cin >> pwd;
				if(user_to_password_db[newuser] == hash_password(pwd))
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
			user_available[newus] = true;
			user_to_password_db[newus] = hash_password(newup);
			save_users_to_json(user_to_password_db, USERS_JSON_FILE);
		}
		else if (cmd == "time") {
			time_t now = time(0);
			cout << ctime(&now);
			delay(1000);
		} 
		else if (cmd == "clear") {
			flush();
			// cout << "\****************************************DOS***************************************************************" << endl;
		} 
		else if (cmd == "exit") {
				flush();
				return 0;
		} 
		else if(cmd == "cat"){
			string filename;
			cin >> filename;
			FILE *file = fopen(filename.c_str(), "r");
			if (file == NULL) {
				cout << "cat: No such file or directory" << endl;
			}
			else {
				char ch;
				while ((ch = fgetc(file)) != EOF) {
					putchar(ch);
				}
				fclose(file);
			}
		}
		
		else if (!cmd.empty()) {
			cout << "Unknown command." << endl;
			delay(1000);
		}
	}
}