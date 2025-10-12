
b 29 if (i % 5 == 0)
commands
	silent
	printf "m @= %d\n", m
	printf "n @= %d\n", n
	printf "s @= %d\n", s
	printf "cur_value @= %d\n", i
	cont
end
run 1 12 > /dev/null
quit
