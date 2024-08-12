# コンパイラとフラグの設定
CC = gcc
CFLAGS = -I./include -I./src
LDFLAGS = -L./lib -lmingw32 -lSDL2main -lSDL2 -mconsole -lglew32 -lopengl32 -lglu32 -lstdc++ -o simple_paint

# ソースファイル
SRC_DIR = src
APP_SRC = $(SRC_DIR)/Application/Application.cpp
RENDERER_SRC = $(SRC_DIR)/Renderer/Renderer.cpp
MAIN_SRC = $(SRC_DIR)/main.cpp

# オブジェクトファイル
OBJ_DIR = .
APP_OBJ = $(OBJ_DIR)/Application.o
RENDERER_OBJ = $(OBJ_DIR)/Renderer.o
MAIN_OBJ = $(OBJ_DIR)/main.o

# ターゲット
TARGET = simple_paint

# デフォルトターゲット
all: $(TARGET)

# ターゲットのリンク
$(TARGET): $(MAIN_OBJ) $(RENDERER_OBJ) $(APP_OBJ)
	$(CC) $^ $(LDFLAGS) -o $@

# 各ソースファイルのコンパイル
$(MAIN_OBJ): $(MAIN_SRC)
	$(CC) -c $< -o $@ $(CFLAGS)

$(RENDERER_OBJ): $(RENDERER_SRC)
	$(CC) -c $< -o $@ $(CFLAGS)

$(APP_OBJ): $(APP_SRC)
	$(CC) -c $< -o $@ $(CFLAGS)

# クリーンアップ
clean:
	rm -f $(OBJ_DIR)/*.o $(TARGET)

# Makefile のターゲットに clean を追加
.PHONY: all clean
