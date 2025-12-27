@echo off

echo =============================
echo C++14 Build and Open Script
echo =============================
echo.

:: 设置工作目录
set "WORK_DIR=%~dp0"
set "SYS_DIR=%WORK_DIR%disk\system"

:: 检查disk/system目录是否存在
if not exist "%SYS_DIR%" (
    echo Error: Directory %SYS_DIR% does not exist!
    pause
    exit /b 1
)

:: 递归搜索所有.cpp文件
echo Searching for .cpp files in %SYS_DIR%...
setlocal enabledelayedexpansion
set "cpp_files="
for /r "%SYS_DIR%" %%f in (*.cpp) do (
    set "cpp_files=!cpp_files! %%f"
)
endlocal & set "cpp_files=%cpp_files%"

if "%cpp_files%"=="" (
    echo No .cpp files found in %SYS_DIR%!
    pause
    exit /b 1
)

:: 显示找到的.cpp文件
echo Found the following .cpp files:
for %%f in (%cpp_files%) do (
    echo %%f
)
echo.
echo Compiling with C++14...

:: 编译所有.cpp文件
for %%f in (%cpp_files%) do (
    :: 获取文件名（不含路径和扩展名）
    set "filename=%%~nf"
    :: 获取文件所在目录
    set "dirname=%%~dpnxf"
    set "dirname=!dirname:%%~nxf=!"
    
    :: 编译命令
    g++ -std=c++14 "%%f" -o "!dirname!!filename!.exe" -lssl -lcrypto
    
    if !errorlevel! equ 0 (
        echo Compiled %%f successfully!
    ) else (
        echo Error compiling %%f!
    )
)

:: 检查logon文件是否存在
set "LOGON_FILE=%WORK_DIR%disk\sysytem\logon"
if exist "%LOGON_FILE%" (
    echo.
    echo Opening .\disk\sysytem\logon...
    :: 使用默认编辑器打开logon文件
    start "" "%LOGON_FILE%"
) else (
    echo.
    echo Error: .\disk\sysytem\logon not found!
    :: 检查正确拼写的路径
    set "LOGON_FILE_CORRECT=%WORK_DIR%disk\system\logon"
    if exist "%LOGON_FILE_CORRECT%" (
        echo Note: Found .\disk\system\logon ^(with correct spelling^).
    )
)

echo.
echo Script completed!
pause