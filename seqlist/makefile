CC=gcc
CFLAGS=-Wall -g -Iinclude

BUILD_DIR=build
OBJ_DIR=$(BUILD_DIR)/obj
TARGET=$(BUILD_DIR)/main

SRC=$(wildcard src/*.c)
OBJ=$(patsubst src/%.c,$(OBJ_DIR)/%.o,$(SRC))

# 默认目标
all: $(TARGET)

# 链接可执行文件
$(TARGET): $(OBJ)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $^ -o $@

# 编译每个源文件为对象文件
$(OBJ_DIR)/%.o: src/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# 清理
clean:
	rm -rf $(BUILD_DIR)

# 运行程序
run: all
	./$(TARGET)

.PHONY: all clean run