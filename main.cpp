#include <bits/stdc++.h>
#include <chrono>
#include <thread>
#include <ctime>

// 跨平台清屏命令定义
#ifdef _WIN32
#include <windows.h>
#define CLEAR_COMMAND "cls"
#else 
#include <termios.h>
#define CLEAR_COMMAND "clear"
#endif

using namespace std;

// 常量与全局变量集中管理
const string SYSTEM_NAME = "QQcat Linux";
const string LOGIN_TITLE = "wangjy_DOS Login";
map<string, string> password_db;  // 用户名-密码数据库

// 工具函数：清屏
void clearScreen() {
    system(CLEAR_COMMAND);
}

// 工具函数：延时（毫秒）
void delay(int ms) {
    this_thread::sleep_for(chrono::milliseconds(ms));
}

// 工具函数：获取当前时间字符串
string getCurrentTime() {
    time_t now = time(0);
    return ctime(&now);
}

// 登录验证函数
bool login(const string& username, const string& password) {
    auto it = password_db.find(username);
    return (it != password_db.end() && it->second == password);
}

// 显示启动进度
void showBootProgress() {
    cout << "Starting";
    for (int i = 1; i <= 10; ++i) {
        delay(500);
        cout << '.';
        cout.flush();  // 立即刷新输出
    }
    cout << endl;
}

// 登录流程处理
bool handleLogin() {
    string username, password;
    int maxAttempts = 3;
    int attempts = 0;

    while (attempts < maxAttempts) {
        clearScreen();
        cout << "\\*******************************" << endl;
        cout << LOGIN_TITLE << endl;
        
        cout << "INPUT YOUR USERNAME: ";
        cin >> username;
        cout << "INPUT YOUR PASSWORD: ";
        cin >> password;

        if (login(username, password)) {
            clearScreen();
            cout << "WELCOME TO USE " << SYSTEM_NAME << endl;
            cout << "***********************************************************\\" << endl;
            delay(1500);
            return true;
        } else {
            attempts++;
            cout << "USERNAME OR PASSWORD WRONG!! (" 
                 << maxAttempts - attempts << " attempts left)" << endl;
            delay(1000);
        }
    }

    cout << "TOO MANY FAILED ATTEMPTS. EXITING..." << endl;
    return false;
}

// 处理命令行输入
void handleCommand(string& currentPath, string& loggedInUser) {
    string command;
    cout << currentPath;
    cin.ignore();  // 清除输入缓冲区
    getline(cin, command);

    if (command == "Windows 10 command") {
#ifdef _WIN32
        system("start cmd.exe");
#else
        cout << "This command is only available on Windows systems" << endl;
        delay(1000);
#endif
    } 
    else if (command == "change_path ADMIN:\\114514") {
        currentPath = "ADMIN:\\114514>>";
    } 
    else if (command == "account ADMIN") {
        string password;
        cout << "INPUT PASSWORD FOR ADMIN: ";
        cin >> password;
        if (password == "admin") {
            loggedInUser = "ADMIN";
            currentPath = "SYSTEM:\\ADMIN\\Home\\DOS>>";
            cout << "Switched to admin account" << endl;
            delay(1000);
        } else {
            cout << "Admin password incorrect" << endl;
            delay(1000);
        }
    } 
    else if (command == "time") {
        cout << getCurrentTime() << endl;
        delay(1000);
    } 
    else if (command == "desktop") {
        clearScreen();
        cout << "\\****************************************DOS***************************************************************" << endl;
    } 
    else if (command == "shut down") {
        cout << SYSTEM_NAME << " is shutting down.........................." << endl;
        delay(2000);  // 缩短关机等待时间，提升体验
        exit(0);
    } 
    else if (command == "help") {
        cout << "Available commands:" << endl;
        cout << "  Windows 10 command - Open Windows command prompt (Windows only)" << endl;
        cout << "  change_path ADMIN:\\114514 - Change working directory" << endl;
        cout << "  account ADMIN - Switch to admin account" << endl;
        cout << "  time - Show current time" << endl;
        cout << "  desktop - Clear screen and show desktop" << endl;
        cout << "  shut down - Shutdown system" << endl;
        cout << "  help - Show this help message" << endl;
        delay(3000);
    }
    else if (!command.empty()) {
        cout << "Unknown command. Type 'help' to see available commands." << endl;
        delay(1000);
    }
}

int main() {
    // 初始化密码数据库
    password_db["root"] = SYSTEM_NAME;
    password_db["user"] = "123456";  // 添加示例用户

    // 启动流程
    showBootProgress();
    clearScreen();

    // 登录验证
    if (!handleLogin()) {
        return 1;  // 登录失败退出
    }

    // DOS系统主循环
    string currentPath = "SYSTEM:\\qqcat\\Home\\DOS>>";
    string loggedInUser = "user";  // 默认登录用户

    clearScreen();
    cout << "\\****************************************DOS***************************************************************" << endl;
    
    while (true) {
        handleCommand(currentPath, loggedInUser);
        clearScreen();
        cout << "\\****************************************DOS***************************************************************" << endl;
    }

    return 0;
}