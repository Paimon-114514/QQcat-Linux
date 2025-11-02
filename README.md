# QQcat-Linux 优化版介绍 / QQcat-Linux Optimized Version Introduction / Présentation de la version optimisée de QQcat-Linux

## 概述 (Overview / Aperçu)
QQcat-Linux 是一个模拟DOS系统的轻量级程序，经过优化后，代码结构更清晰、功能更完善、用户体验更流畅，同时具备更好的跨平台兼容性。

QQcat-Linux is a lightweight program simulating a DOS system. After optimization, it has a clearer code structure, more complete functions, smoother user experience, and better cross-platform compatibility.

QQcat-Linux est un programme léger simulant un système DOS. Après optimisation, il présente une structure de code plus claire, des fonctions plus complètes, une expérience utilisateur plus fluide et une meilleure compatibilité multiplateforme.

## 主要优化点 (Key Optimizations / Principales optimisations)

### 1. 代码结构优化 (Code Structure Optimization / Optimisation de la structure du code)
- 将功能模块化，拆分为多个独立函数（清屏、延时、登录验证等）
- 常量集中管理，便于维护和修改
- 添加详细注释，提高代码可读性

- Modularized functions, split into multiple independent functions (screen clearing, delay, login verification, etc.)
- Centralized management of constants for easy maintenance and modification
- Added detailed comments to improve code readability

- Modularisation des fonctions, divisées en plusieurs fonctions indépendantes (effacement de l'écran, délai, vérification de connexion, etc.)
- Gestion centralisée des constantes pour une maintenance et une modification faciles
- Ajout de commentaires détaillés pour améliorer la lisibilité du code

### 2. 功能增强 (Function Enhancement / Amélioration des fonctions)
- 增加登录失败次数限制（最多3次尝试）
- 添加`help`命令，显示所有可用指令
- 完善时间显示功能，输出人类可读的时间格式
- 扩展用户体系，增加默认普通用户

- Added login failure limit (maximum 3 attempts)
- Added `help` command to display all available instructions
- Improved time display function to output human-readable time format
- Expanded user system with additional default regular users

- Ajout d'une limite de tentatives de connexion échouées (maximum 3 tentatives)
- Ajout de la commande `help` pour afficher toutes les instructions disponibles
- Amélioration de la fonction d'affichage de l'heure pour produire un format lisible par l'homme
- Extension du système d'utilisateurs avec des utilisateurs réguliers par défaut supplémentaires

### 3. 用户体验改进 (User Experience Improvement / Amélioration de l'expérience utilisateur)
- 优化输入输出流程，减少不必要的屏幕刷新
- 增加操作反馈信息和状态提示
- 缩短关机等待时间，提升使用效率
- 显示剩余登录尝试次数，增强用户感知

- Optimized input and output processes to reduce unnecessary screen refreshes
- Added operation feedback and status prompts
- Shortened shutdown waiting time to improve efficiency
- Displayed remaining login attempts to enhance user perception

- Optimisation des processus d'entrée et de sortie pour réduire les rafraîchissements d'écran inutiles
- Ajout de commentaires d'opération et d'indicateurs d'état
- Réduction du temps d'attente d'arrêt pour améliorer l'efficacité
- Affichage des tentatives de connexion restantes pour améliorer la perception de l'utilisateur

### 4. 跨平台兼容性 (Cross-platform Compatibility / Compatibilité multiplateforme)
- 修复原代码中平台相关的宏定义错误
- 使用C++11标准库实现跨平台延时功能
- 对Windows特定命令增加平台判断，避免在非Windows系统出错

- Fixed platform-related macro definition errors in the original code
- Implemented cross-platform delay function using C++11 standard library
- Added platform checks for Windows-specific commands to avoid errors on non-Windows systems

- Correction des erreurs de définition de macros liées à la plateforme dans le code original
- Mise en œuvre d'une fonction de délai multiplateforme à l'aide de la bibliothèque standard C++11
- Ajout de vérifications de plateforme pour les commandes spécifiques à Windows afin d'éviter les erreurs sur les systèmes non Windows

## 支持的命令 (Supported Commands / Commandes prises en charge)
- `Windows 10 command` - 打开Windows命令提示符（仅Windows系统）
- `change_path ADMIN:\\114514` - 更改工作目录
- `account ADMIN` - 切换到管理员账户
- `time` - 显示当前时间
- `desktop` - 清屏并显示桌面
- `shut down` - 关闭系统
- `help` - 显示帮助信息

- `Windows 10 command` - Open Windows command prompt (Windows only)
- `change_path ADMIN:\\114514` - Change working directory
- `account ADMIN` - Switch to admin account
- `time` - Show current time
- `desktop` - Clear screen and show desktop
- `shut down` - Shutdown system
- `help` - Show help information

- `Windows 10 command` - Ouvrir l'invite de commandes Windows (seulement Windows)
- `change_path ADMIN:\\114514` - Changer le répertoire de travail
- `account ADMIN` - Passer au compte administrateur
- `time` - Afficher l'heure actuelle
- `desktop` - Effacer l'écran et afficher le bureau
- `shut down` - Arrêter le système
- `help` - Afficher les informations d'aide