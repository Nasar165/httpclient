VERSION = 1.0.4
all: main

http: src/main.c
	mkdir -p src/out
	gcc src/main.c src/common/error.c src/core/dns.c  src/core/http.c -o src/out/main.out

https: src/main.c
	mkdir -p src/out
	gcc src/main.c src/common/error.c src/core/dns.c  src/core/https.c -lssl -lcrypto -o src/out/main.out

run: src/out
	./src/out/main.out $(domain) ${port}

server: src/out
	cd server/ && npm start
 