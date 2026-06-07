CC=gcc
CFLAGS=-Wall -g -Iinclude   # -Iinclude 自动引入头文件目录，解决找不到queue.h

BUILD_DIR=build
OBJ_DIR=$(BUILD_DIR)/obj
TARGET=$(BUILD_DIR)/queue_test

# 搜集src下所有.c源码
SRC=$(wildcard src/*.c)
# src/xxx.c → build/obj/xxx.o
OBJ=$(patsubst src/%.c,$(OBJ_DIR)/%.o,$(SRC))

# 终极目标：生成可执行文件
all: $(TARGET)

# 链接所有.o生成程序
$(TARGET): $(OBJ)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $^ -o $@

# 单文件编译成.o
$(OBJ_DIR)/%.o: src/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# 删除编译产物
clean:
	rm -rf $(BUILD_DIR)

# 一键编译+运行
run: all
	./$(TARGET)

# 伪目标，避免和文件重名
.PHONY: all clean run