VERSION = 1.0.0
all: main

arduino: src/main.c
	mkdir -p src/out
	gcc src/main.c src/common/aerror.c -o src/out/main.out

main: src/main.c
	mkdir -p src/out
	gcc src/main.c src/common/error.c src/common/dns.c -o src/out/main.out

