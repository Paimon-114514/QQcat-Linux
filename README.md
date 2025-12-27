# QQcat-Linux V1.2(Stable Version) Terminal Emulator  
# QQcat-Linux V1.2(稳定版本) 终端模拟器  

## Introduction / 项目简介  
A simple terminal emulator program that simulates basic functions of a Linux-like terminal, supporting user login, command execution, directory management, and other operations. It is cross-platform and can run on Windows and Unix-like systems (such as Linux, macOS).  
这是一个简易的终端模拟器程序，模拟了类Linux终端的基本功能，支持用户登录、命令执行、目录管理等操作。程序具有跨平台特性，可在Windows和类Unix系统（如Linux、macOS）上运行。  


## Project Structure / 项目结构  
```
QQcat-Linux/
├── disk/
│   ├── system/
│   │   ├── SystemFunc.hpp       # Core system functions (password hashing, JSON handling)
│   │   ├── SearchFiles.cpp      # File search utility
│   │   ├── logon.cpp            # Login program
│   │   ├── Terminal.cpp         # Terminal emulator
│   │   ├── users.json           # User database (password hashes)
│   │   └── ...
│   └── users/                   # User files
├── nlohmann/
│   └── json.hpp                 # JSON library for C++
├── main_Preview_1.cpp           # Preview version main program
├── build_and_open.sh            # Linux/macOS build script
├── build_and_open.bat           # Windows build script
└── README.md                    # This file
```  


## Features / 功能说明  

### 1. User Management / 用户管理  
- Supports user login (default admin user: `root`, password: `qqcat_terminal`)
- Allows creating new users (`mkuser` command)
- Enables switching users (`chuser` command)
- Secure password storage using SHA-256 hashing

- 支持用户登录（默认管理员用户：`root`，密码：`qqcat_terminal`）
- 可创建新用户（`mkuser`命令）
- 可切换用户（`chuser`命令）
- 使用SHA-256哈希安全存储密码


### 2. File and Directory Operations / 文件和目录操作  
- Create directories (`mkdir` command)
- Change directories (`cd` command)
- View file contents (`cat` command)
- Recursive file search capability

- 支持创建目录（`mkdir`命令）
- 支持切换目录（`cd`命令）
- 查看文件内容（`cat`命令）
- 递归文件搜索功能


### 3. System Commands / 系统命令  
- Display current time (`time` command)
- Clear screen (`clear` command)
- Exit terminal (`exit` command)
- Evoke system terminal (`systerminal` command)

- 显示当前时间（`time`命令）
- 清屏操作（`clear`命令）
- 退出终端（`exit`命令）
- 唤起系统终端（`systerminal`命令）


## Installation and Compilation / 安装与编译  

### Prerequisites / 前置条件  
- C++14 compatible compiler (g++ 5.1+, clang++ 3.4+)
- OpenSSL library (for SHA-256 hashing)

#### For Linux/macOS:  
```bash
# Debian/Ubuntu
apt-get install g++ libssl-dev

# CentOS/RHEL
yum install gcc-c++ openssl-devel

# macOS
brew install gcc openssl
```  

#### For Windows:  
- Install MinGW-w64 (https://www.mingw-w64.org/)
- Install OpenSSL for Windows


### Quick Build (Recommended) / 快速构建（推荐）  

#### For Linux/macOS:  
```bash
chmod +x build_and_open.sh
./build_and_open.sh
```  

#### For Windows:  
Double-click `build_and_open.bat` file, or run in Command Prompt:
```cmd
build_and_open.bat
```  

The script will:  
1. Recursively search for all `.cpp` files in `disk/system` directory
2. Compile them using C++14 standard
3. Attempt to open the login program

脚本将：
1. 递归搜索`disk/system`目录中的所有`.cpp`文件
2. 使用C++14标准编译它们
3. 尝试打开登录程序


### Manual Compilation / 手动编译  

#### For Linux/macOS:  
```bash
# Compile all programs
cd disk/system
g++ -std=c++14 SearchFiles.cpp -o SearchFiles -lssl -lcrypto
g++ -std=c++14 logon.cpp -o logon -lssl -lcrypto
g++ -std=c++14 Terminal.cpp -o Terminal -lssl -lcrypto

# Run the login program
./logon
```  

#### For Windows:  
```cmd
# Compile all programs
cd disk\system
g++ -std=c++14 SearchFiles.cpp -o SearchFiles.exe -lssl -lcrypto
g++ -std=c++14 logon.cpp -o logon.exe -lssl -lcrypto
g++ -std=c++14 Terminal.cpp -o Terminal.exe -lssl -lcrypto

# Run the login program
logon.exe
```  


## Usage / 使用方法  

### Login / 登录系统  
Run the login program:  
运行登录程序：
```bash
# Linux/macOS
./disk/system/logon

# Windows
disk\system\logon.exe
```  

Log in with the default user `root` and password `qqcat_terminal`, or use other created users.  
使用默认用户`root`和密码`qqcat_terminal`登录，或使用已创建的其他用户。  


### Execute Commands / 执行命令  
After logging in, you can use supported commands. Here are some examples:  
登录后即可使用支持的命令进行操作。以下是一些示例：  

```bash
# Create a new user
mkuser
Enter new user's name: alice
Enter password for alice: mypassword

# Switch user
chuser alice
mypassword

# Create directory
mkdir /home

# Change directory
cd /home

# View current time
time

# Clear screen
clear

# Exit terminal
exit
```  


## List of Supported Commands / 支持的命令列表  

| Command / 命令 | Description / 功能描述 |  
|----------------|------------------------|  
| `systerminal`  | Evoke system terminal |  
|                | 唤起系统终端 |  
| `cd [dir]`     | Switch to the specified directory (must be created with `mkdir` first) |  
|                | 切换到指定目录（需先使用`mkdir`创建） |  
| `mkdir [dir]`  | Create a new directory |  
|                | 创建新目录 |  
| `chuser [user]`| Switch to the specified user (requires password) |  
|                | 切换到指定用户（需要密码） |  
| `mkuser`       | Create a new user (will prompt for username and password) |  
|                | 创建新用户（会提示输入用户名和密码） |  
| `time`         | Display current system time |  
|                | 显示当前系统时间 |  
| `clear`        | Clear the screen |  
|                | 清空屏幕 |  
| `exit`         | Exit the terminal emulator |  
|                | 退出终端模拟器 |  
| `cat [file]`   | View file contents |  
|                | 查看文件内容 |  


## Security Features / 安全特性  
- Passwords are stored as SHA-256 hashes, not plain text
- JSON file used for secure user data storage
- C++14 compatible for better security and performance

- 密码存储为SHA-256哈希值，而非明文
- 使用JSON文件安全存储用户数据
- 兼容C++14标准，提高安全性和性能


## Notes / 注意事项  
- C++14 compatible compiler is required
- OpenSSL library must be installed for password hashing
- The `users.json` file stores password hashes securely
- User and directory information is stored during the session
- Cross-platform support: Automatically adapts to different operating systems

- 需要C++14兼容的编译器
- 必须安装OpenSSL库以支持密码哈希
- `users.json`文件安全存储密码哈希
- 用户和目录信息在会话期间保存
- 跨平台支持：自动适配不同操作系统


## Version Information / 版本信息  
Current version: QQcat-Linux V1.2(Stable Version)  
当前版本：QQcat-Linux V1.2(稳定版本)  


## Changelog / 更新日志  
- Improved security with SHA-256 password hashing
- Added JSON-based user database
- Implemented recursive file search functionality
- Added cross-platform build scripts
- Fixed C++14 compatibility issues
- Enhanced terminal functionality

- 使用SHA-256密码哈希提高安全性
- 添加了基于JSON的用户数据库
- 实现了递归文件搜索功能
- 添加了跨平台构建脚本
- 修复了C++14兼容性问题
- 增强了终端功能
