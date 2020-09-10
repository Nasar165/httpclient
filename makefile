VERSION = 1.0.0
all: main

main: src/main.c
	mkdir -p src/out
	gcc src/main.c src/common/error.c src/core/dns.c  src/core/http.c -o src/out/main.out

tls: src/main.c
	mkdir -p src/out
	gcc src/main.c src/common/error.c src/core/dns.c  src/core/https.c -lssl -lcrypto -o src/out/main.out

run: src/out
	./src/out/main.out $(domain)

