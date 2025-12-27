#include <bits/stdc++.h>
#include <openssl/sha.h>
#include <nlohmann/json.hpp>
#include <dirent.h>
#include <sys/stat.h>
// Include nlohmann/json single header (download and place in project directory first)
#include "nlohmann/json.hpp"

using namespace std;
using json = nlohmann::json;
string Terminal_name = "QQcat-Linux V1.2(Stable)";

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

void flush(){
	system(clear_cmd);
	fflush(stdin);
	fflush(stdout);
}
 
void delay(int ms) {
    this_thread::sleep_for(chrono::milliseconds(ms));
}

// SHA-256 哈希函数
string hash_password(const string &password) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, password.c_str(), password.length());
    SHA256_Final(hash, &sha256);
    
    stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        ss << hex << setw(2) << setfill('0') << (int)hash[i];
    }
    return ss.str();
}

// 将用户数据保存到JSON文件
void save_users_to_json(const map<string, string> &users, const string &filename) {
    json j;
    
    for (auto it = users.begin(); it != users.end(); ++it) {
        const string& user = it->first;
        const string& password = it->second;
        j[user] = password;
    }
    
    ofstream file(filename);
    if (file.is_open()) {
        file << j.dump(4);  // 格式化输出，缩进4个空格
        file.close();
    } else {
        cerr << "Error saving users to JSON: Could not open file " << filename << endl;
    }
}

// 从JSON文件加载用户数据
map<string, string> load_users_from_json(const string &filename) {
    map<string, string> users;
    ifstream file(filename);
    
    if (file.is_open()) {
        try {
            json j;
            file >> j;
            
            for (auto it = j.begin(); it != j.end(); ++it) {
                const string& user = it.key();
                const string& password = it.value().get<string>();
                users[user] = password;
            }
        } catch (const exception& e) {
            // JSON文件格式错误或空文件
            cerr << "Error loading users from JSON: " << e.what() << endl;
        }
        file.close();
    } else {
        // 文件不存在，创建默认用户
        users["root"] = hash_password("qqcat_terminal");
        save_users_to_json(users, filename);
    }
    
    return users;
}

bool cat_available_from_json(string filename){
	ifstream file("file_paths.json");
	if (file.is_open()) {
		try {
			json j;
			file >> j;
			if (j.contains(filename)) {
				return j["cat"].get<bool>();
			}
		} catch (const exception& e) {
			// JSON文件格式错误或空文件
			cerr << "Error loading cat availability from JSON: " << e.what() << endl;
		}
		file.close();
	} else {
		// 文件不存在，创建默认用户
		json j;
		j["cat"] = true;
		save_users_to_json(j, "file_paths.json");
		return true;
	}
}