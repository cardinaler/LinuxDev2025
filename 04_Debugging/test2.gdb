set $cnt = 0
b 29

commands
	silent
	set $cnt = $cnt + 1


if ($cnt >= 28 && $cnt <= 35)
	printf "m @= %d\n", m
	printf "n @= %d\n", n
	printf "s @= %d\n", s
	printf "cur_value @= %d\n", i
end
	cont

end

run -100 100 3 > /dev/null
quit
