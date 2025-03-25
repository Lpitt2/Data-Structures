program: ./src/main.c
	gcc -std=c11 -g -Wall -o ./bin/program ./src/main.c ./src/stack/*.c ./src/queue/*.c ./src/list/*.c
