CFLAGS = -fPIC
TRASH = *.o *.out
GENERATES = prog prog-a prog-so liboutput_static.a liboutput.so
liboutput_static.a: fun.o const.o
	ar -rcs $@ $^
liboutput.so: fun.o const.o
	cc -shared $^ -o $@
clean:
	rm -f $(TRASH) $(GENERATES)
all: prog prog-a prog-so

prog: fun.o prog.o const.o

prog-a:	prog.o liboutput_static.a 
	cc -L. $< -loutput_static -o $@
prog-so: prog.o liboutput.so
	cc -L. $< -loutput -o $@

fun.c: outlib.h

test: prog prog-a prog-so
	./prog > file1.out 2>&1
	./prog-a > file1_a.out 2>&1
	LD_LIBRARY_PATH=`pwd` ./prog-so > file1_so.out 2>&1

	cmp file1.out file1_a.out
	cmp file1.out file1_so.out
	cmp file1_a.out file1_so.out

	./prog ar > file2.out
	./prog-a ar > file2_a.out
	LD_LIBRARY_PATH=`pwd` ./prog-so ar > file2_so.out

	cmp file2.out file2_a.out
	cmp file2.out file2_so.out
	cmp file2_a.out file2_so.out

	./prog ar1 ar2 ar3 > file3.out
	./prog-a ar1 ar2 ar3 > file3_a.out
	LD_LIBRARY_PATH=`pwd` ./prog-so ar1 ar2 ar3 > file3_so.out

	cmp file3.out file3_a.out
	cmp file3.out file3_so.out
	cmp file3_a.out file3_so.out
