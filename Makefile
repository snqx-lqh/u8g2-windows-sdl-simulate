# ������
CC = gcc

# ����ѡ��
CFLAGS = -Wall -Wextra -O2 -Icsrc -IE:/Program/mingw64/x86_64-w64-mingw32/include/SDL2

# ����ѡ��
LDFLAGS = -LE:/Program/mingw64/x86_64-w64-mingw32/lib -lSDL2

# Ŀ���ִ���ļ�
TARGET = main.exe

# Դ�ļ�
SRCS = main.c

# u8g2 Դ�ļ�
U8G2_SRCS = $(wildcard csrc/*.c)

# ����Դ�ļ�
ALL_SRCS = $(SRCS) $(U8G2_SRCS)

# Ŀ���ļ�
OBJS = $(ALL_SRCS:.c=.o)

# Ĭ��Ŀ��
all: $(TARGET)

# ���ɿ�ִ���ļ�
$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)

# �������
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# �������ɵ��ļ�
clean:
	rm -f $(OBJS) $(TARGET)

# αĿ��
.PHONY: all clean