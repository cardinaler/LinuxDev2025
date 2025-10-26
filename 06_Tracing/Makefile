TRASH = *.o 
GENERATES = *.out move qwe test prot.so testPROTECTtest

move: move.c

clean:
	rm -f $(TRASH) $(GENERATES)

prot.so: prot.c
	cc -shared prot.c -o prot.so

test: move prot.so
	echo "Mayst thou thy peace" > test
	./move test qwe
	if [ $$? -eq 0 ] && [ -f qwe ] && [ ! -f test ]; then echo "OK"; else echo "NO"; fi
	./move > /dev/null 2>&1 || if [ $$? -eq 1 ] && [ -f qwe ] && [ ! -f test ]; then echo "OK"; else echo "NO"; fi
	strace -e fault=openat:error=1:when=3 ./move qwe test > /dev/null 2>&1 || if [ $$? -eq 2 ] && [ -f qwe ] && [ ! -f test ]; then echo "OK"; else echo "NO"; fi
	strace -e fault=openat:error=1:when=4 ./move qwe test > /dev/null 2>&1 || if [ $$? -eq 3 ] && [ -f qwe ] && [ ! -f test ]; then echo "OK"; else echo "NO"; fi
	strace -e fault=close:error=1:when=3 ./move qwe test > /dev/null 2>&1 || if [ $$? -eq 4 ] && [ -f qwe ] && [ ! -f test ]; then echo "OK"; else echo "NO"; fi
	strace -e fault=write:error=1 ./move qwe test > /dev/null 2>&1 || if [ $$? -eq 6 ] && [ -f qwe ] && [ ! -f test ]; then echo "OK"; else echo "NO"; fi
	strace -e fault=close:error=1:when=4 ./move qwe test > /dev/null 2>&1 || if [ $$? -eq 7 ] && [ -f qwe ] && [ ! -f test ]; then echo "OK"; else echo "NO"; fi
	strace -e fault=read:error=1:when=2 ./move qwe test > /dev/null 2>&1 || if [ $$? -eq 8 ] && [ -f qwe ] && [ ! -f test ]; then echo "OK"; else echo "NO"; fi
	strace -e fault=unlink:error=1:when=1 ./move qwe test > /dev/null 2>&1 || if [ $$? -eq 9 ] && [ -f qwe ] && [ ! -f test ]; then echo "OK"; else echo "NO"; fi
	
	@cp qwe testPROTECTtest
	LD_PRELOAD=`pwd`/prot.so ./move testPROTECTtest test
	if [ -f testPROTECTtest ] && [ -f test ]; then echo "OK"; else echo "NO"; fi



