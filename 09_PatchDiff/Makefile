TRASH = *.o
GENERATES = lab1.c lab2.c lab3.c lab lab1 lab2 lab3

run: lab lab1 lab2 lab3
	./lab
	./lab1 13
	./lab2 ' @' 13
	./lab3 '.@' 13 24
	./lab3 '.@' 13 42

lab: lab.c

lab1.c:
	cp lab.c lab1.c
	patch lab1.c < lab1.patch

lab1: lab1.c

lab2.c:
	cp lab.c lab2.c
	patch lab2.c < lab2.patch

lab2: lab2.c

lab3.c: 
	cp lab.c lab3.c
	patch lab3.c < lab3.patch

lab3: lab3.c

clean:
	rm -f $(TRASH) $(GENERATES)
