VERSION = 1.0.0
all: main
	
main: src/main.c
	mkdir -p src/out
	gcc src/main.c src/common/error.c -o src/out/main.out

