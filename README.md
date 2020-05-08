compilation:
  clang++ -std=c++14 -stdlib=libc++ -Wall -pedantic run.cpp -o run

assemble the sum function with:
  as sum.s -o sum.o

dump the result with:
  objdump -x86-asm-syntax=intel -D sum.o

The result can be used as machine code
