CFLAGS = -o0 -g
TRASH = *.o 
GENERATES = *.out range

range: range.c

clean:
	rm -f $(TRASH) $(GENERATES)

test: test1 test2

test1: range test1.gdb
	gdb ./range -x test1.gdb | grep @= > ans_test1.out
	cmp ans_test1.out ans_true1.txt

test2: range test2.gdb
	gdb ./range -x test2.gdb | grep @= > ans_test2.out
	cmp ans_test2.out ans_true2.txt



