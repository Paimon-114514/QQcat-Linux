# QQcat-Linux V1.2(Preview #1) Terminal Emulator  
# QQcat-Linux V1.2(Preview #1) 终端模拟器  

## Introduction / 项目简介  
A simple terminal emulator program that simulates basic basic basic functions of a Linux-like terminal, supporting user login, command execution, directory management, and other basic operations. It is cross-platform and can run on Windows and Unix-like systems (such as Linux, macOS).  
这是一个简易的终端模拟器程序，模拟了类Linux终端的基本功能，支持用户登录、命令执行、目录管理等操作。程序具有跨平台特性，可在Windows和类Unix系统（如Linux、macOS）上运行。  


## Features / 功能说明  

### 1. User Management / 用户管理  
- Supports user login (default admin user: `root`, password: `qqcat_terminal`)  
- Allows creating new users (`mkuser` command)  
- Enables switching users (`chuser` command)  

- 支持用户登录（默认管理员用户：`root`，密码：`qqcat_terminal`）  
- 可创建新用户（`mkuser`命令）  
- 可切换用户（`chuser`命令）  


### 2. Directory Operations / 目录操作  
- Create directories (`mkdir` command)  
- Change directories (`cd` command)  

- 支持创建目录（`mkdir`命令）  
- 支持切换目录（`cd`命令）  


### 3. System Commands / 系统命令  
- Display current time (`time` command)  
- Clear screen (`clear` command)  
- View help information (`help` command)  
- Exit terminal (`exit` command)  

- 显示当前时间（`time`命令）  
- 清屏操作（`clear` command）  
- 查看帮助信息（`help`命令）  
- 退出终端（`exit`命令）  


## Usage / 使用方法  

### 1. Compile the Program / 编译程序  
Use a compiler that supports C++11 or higher to compile the `main_Preview_#1.cpp` file:  
使用支持C++11及以上标准的编译器编译`main_Preview_#1.cpp`文件：  
```bash
g++ main_Preview_1.cpp -o qqcat_terminal -lpthread
```  


### 2. Run the Program / 运行程序  
```bash
# Windows system
.\qqcat_terminal.exe

# Linux/macOS system
./qqcat_terminal
```  

```bash
# Windows系统
.\qqcat_terminal.exe

# Linux/macOS系统
./qqcat_terminal
```  


### 3. Login / 登录系统  
Log in with the default user `root` and password `qqcat_terminal`, or use other created users.  
使用默认用户`root`和密码`qqcat_terminal`登录，或使用已创建的其他用户。  


### 4. Execute Commands / 执行命令  
After logging in, you can use supported commands. Type `help` to view all available commands.  
登录后即可使用支持的命令进行操作，输入`help`可查看所有可用命令。  


## List of Supported Commands / 支持的命令列表  

| Command / 命令 | Description / 功能描述 |  
|----------------|------------------------|  
| `systerminal`  | Attempt to evoke the system terminal (currently unavailable) |  
|                | 尝试唤起系统终端（当前不可用） |  
| `cd [dir]`     | Switch to the specified directory (must be created with `mkdir` first) |  
|                | 切换到指定目录（需先使用`mkdir`创建） |  
| `mkdir [dir]`  | Create a new directory |  
|                | 创建新目录 |  
| `chuser [user] [pwd]` | Switch to the specified user |  
|                       | 切换到指定用户 |  
| `mkuser`       | Create a new user (will prompt for username and password) |  
|                | 创建新用户（会提示输入用户名和密码） |  
| `time`         | Display current system time |  
|                | 显示当前系统时间 |  
| `clear`        | Clear the screen |  
|                | 清空屏幕 |  
| `exit`         | Exit the terminal emulator |  
|                | 退出终端模拟器 |  
| `help`         | Display help information |  
|                | 显示帮助信息 |  


## Notes / 注意事项  
- The program displays a short startup animation when launching.  
- Directory and user information are only valid for the current session and will not be saved after exiting the program.  
- Cross-platform support: Automatically adapts to screen-clearing commands and terminal types for Windows and Unix-like systems.  

- 程序启动时会有一个简短的启动动画  
- 目录和用户信息仅在当前会话有效，程序退出后不会保存  
- 跨平台支持：自动适配Windows和类Unix系统的清屏命令和终端类型  


## Version Information / 版本信息  
Current version: QQcat-Linux V1.2(Preview #1)  
当前版本：QQcat-Linux V1.2(Preview #1)
