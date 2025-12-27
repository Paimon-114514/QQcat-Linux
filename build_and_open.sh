#!/bin/bash

# 设置工作目录
WORK_DIR="$(pwd)"
SYS_DIR="$WORK_DIR"

# 检查disk/system目录是否存在
if [ ! -d "$SYS_DIR" ]; then
    echo "Error: Directory $SYS_DIR does not exist!"
    exit 1
fi

# 递归搜索所有.cpp文件
cpp_files=$(find "$SYS_DIR" -name "*.cpp")

if [ -z "$cpp_files" ]; then
    echo "No .cpp files found in $SYS_DIR!"
    exit 1
fi

# 编译所有.cpp文件
echo "Found the following .cpp files:"
echo "$cpp_files"
echo ""
echo "Compiling with C++14..."

for file in $cpp_files; do
    # 获取文件名（不含路径和扩展名）
    filename=$(basename "$file" .cpp)
    # 获取文件所在目录
    dirname=$(dirname "$file")
    # 编译命令
    g++ -std=c++14 "$file" -o "$dirname/$filename" -lssl -lcrypto --no-warnings -O2
    
    if [ $? -eq 0 ]; then
        echo "Compiled $file successfully!"
    else
        echo "Error compiling $file!"
    fi
done

# 检查logon文件是否存在
LOGON_FILE="$WORK_DIR/disk/system/logon"
if [ -f "$LOGON_FILE" ]; then
    echo ""
    echo "Opening ./disk/system/logon..."
    # 打开logon文件
    ./disk/system/logon || echo "Could not open ./disk/system/logon automatically. Please open it manually."
else
    echo ""
    echo "Error: ./disk/system/logon not found!"
    # 检查正确拼写的路径
    LOGON_FILE_CORRECT="$WORK_DIR/disk/system/logon"
    if [ -f "$LOGON_FILE_CORRECT" ]; then
        echo "Note: Found ./disk/system/logon (with correct spelling)."
    fi
fi

echo ""
# echo "Script completed!"
clear