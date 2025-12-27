#include "SystemFunc.hpp"

// 定义常量
const string USERS_JSON_FILE = "users.json";

int main(){
	printf("starting...");
	system("./SearchFiles");
	delay(3000);
	flush();

	while(1){
		// 从JSON文件加载用户数据
		map<string, string> user_to_password_db = load_users_from_json(USERS_JSON_FILE);
		
		// 初始化用户可用性映射
		map<string, bool> user_available;
		for (auto it = user_to_password_db.begin(); it != user_to_password_db.end(); ++it) {
			const string& user = it->first;
			user_available[user] = true;
		}
		
		// 核心逻辑
		flush();
		string user, pwd;
		int attempt = 0;
		cout << Terminal_name << " tty1" << '\n';

		while(1){
			cout << "user Login: ";
			cin >> user;
			cout << "Password: ";
			cin >> pwd;

			if(user_available.count(user) && user_to_password_db[user] == hash_password(pwd))
				break;
			else {
				printf("User or password incorrect.\n");
				delay(1000);
				continue;
			}
		}

		flush();
		system("./Terminal");
	}
}