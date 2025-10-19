TRASH = *.o 
GENERATES = *.out esub 

esub: esub.c

clean:
	rm -f $(TRASH) $(GENERATES)

test:
	./esub "([0-9]+)" "NUM=\\1" "abc123def" > out_1.out
	echo "abc123def" | sed -E 's/([0-9]+)/NUM=\1/' > sed_1.out
	cmp out_1.out sed_1.out

	./esub "x" "\\\\" "xx" > out_2.out
	echo "xx" | sed -E 's/x/\\/' > sed_2.out
	cmp out_2.out sed_2.out

	
