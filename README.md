# QQcat-Linux 旧版本介绍 / QQcat-Linux Old Version Introduction / Présentation de la ancienne version de QQcat-Linux

## 概述 (Overview / Aperçu)
QQcat-Linux 旧版本是一个基础的DOS系统模拟程序，提供简单的系统启动、登录验证和命令交互功能，可模拟DOS环境下的基本操作流程。

QQcat-Linux old version is a basic DOS system simulation program that provides simple system startup, login verification and command interaction functions, which can simulate basic operation processes in DOS environment.

La vieille version de QQcat-Linux est un programme de simulation de système DOS de base, offrant des fonctions simples de démarrage du système, de vérification de connexion et d'interaction par commandes, capable de simuler les processus opérationnels de base dans un environnement DOS.

## 核心功能 (Core Features / Fonctionnalités principales)

### 1. 系统启动流程 (System Startup Process / Processus de démarrage du système)
- 启动时显示"Starting"提示，并伴随10个进度点动画
- 使用`sleep`函数实现启动延迟效果
- 启动完成后自动清屏并进入登录界面

- Displays "Starting" prompt on startup with 10 progress dots animation
- Uses `sleep` function to achieve startup delay effect
- Automatically clears screen and enters login interface after startup

- Affiche le message "Starting" au démarrage avec une animation de 10 points de progression
- Utilise la fonction `sleep` pour obtenir un effet de délai de démarrage
- Efface automatiquement l'écran et accède à l'interface de connexion après le démarrage

### 2. 登录验证 (Login Verification / Vérification de connexion)
- 提供简单的用户名/密码验证机制
- 内置用户数据库，默认用户"root"的密码与系统名相同
- 登录失败时支持重新输入用户名和密码

- Provides simple username/password verification mechanism
- Built-in user database, the password of default user "root" is the same as the system name
- Supports re-entering username and password when login fails

- Offre un mécanisme simple de vérification nom d'utilisateur/mot de passe
- Base de données utilisateurs intégrée, le mot de passe de l'utilisateur par défaut "root" est identique au nom du système
- Prend en charge la réentrée du nom d'utilisateur et du mot de passe en cas d'échec de connexion

### 3. DOS命令交互 (DOS Command Interaction / Interaction par commandes DOS)
- 支持基础命令操作，包括：
  - `Windows 10 command`：打开Windows命令提示符
  - `change_path ADMIN:\\114514`：更改当前路径
  - `account ADMIN`：切换到管理员账户（密码为"admin"）
  - `time`：显示当前时间戳
  - `desktop`：清屏并显示桌面标识
  - `shut down`：关闭模拟系统

- Supports basic command operations, including:
  - `Windows 10 command`: Open Windows command prompt
  - `change_path ADMIN:\\114514`: Change current path
  - `account ADMIN`: Switch to admin account (password is "admin")
  - `time`: Display current timestamp
  - `desktop`: Clear screen and display desktop identifier
  - `shut down`: Shut down the simulation system

- Prend en charge les opérations de commande de base, y compris :
  - `Windows 10 command` : Ouvrir l'invite de commandes Windows
  - `change_path ADMIN:\\114514` : Changer le chemin actuel
  - `account ADMIN` : Passer au compte administrateur (mot de passe "admin")
  - `time` : Afficher le timestamp actuel
  - `desktop` : Effacer l'écran et afficher l'identifiant du bureau
  - `shut down` : Arrêter le système de simulation

## 技术特点 (Technical Features / Caractéristiques techniques)
- 使用C++标准库实现基本功能，依赖较少
- 采用简单的全局变量存储用户数据和系统状态
- 通过`system`函数实现清屏等系统操作
- 基础的循环结构实现命令行交互逻辑

- Uses C++ standard library to implement basic functions with few dependencies
- Uses simple global variables to store user data and system status
- Implements system operations such as screen clearing through `system` function
- Basic loop structure implements command line interaction logic

- Utilise la bibliothèque standard C++ pour implémenter des fonctions de base avec peu de dépendances
- Utilise de simples variables globales pour stocker les données utilisateur et l'état du système
- Implémente des opérations système telles que l'effacement de l'écran via la fonction `system`
- Structure de boucle de base implémentant la logique d'interaction en ligne de commande
