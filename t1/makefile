CC = gcc
all: make_main
make_main:
	clang -emit-llvm -S main.c -o main.ll
	./opt -load ./VecPass.so -winmt main.ll -enable-new-pm=0 > out.bc
	llc out.bc -o out.s
	$(CC) out.s -o out
	rm out.bc out.s

test:
	./out
    