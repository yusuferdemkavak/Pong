SRCS = main.c GameData.c UIManager.c GameManager.c
RAYLIB ?= ./external/raylib-5.5/src/
CFLAGS = -std=c99 -Wall -Wextra -Werror
LDFLAGS = -L$(RAYLIB) -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
INCLUDES = -I$(RAYLIB)

all:
	gcc $(CFLAGS) $(SRCS) $(INCLUDES) $(LDFLAGS)
	./a.out

clean:
	rm -rf ./a.out

re: clean all

.PHONY: all re clean
