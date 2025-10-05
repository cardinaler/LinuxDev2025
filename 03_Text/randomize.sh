#!/bin/bash
exit_handler() {
  trap - EXIT
  test -r "$TMPFILE" && rm -vf "$TMPFILE"
}

trap exit_handler EXIT HUP INT QUIT PIPE TERM
tput clear
TMPFILE="`mktemp ./tmp.XXXXXX`"

ln_cnt=1

while IFS= read -r line;
do
	cnt=${#line}
	sym_cnt=1
	for (( i=0; i<cnt; i++ ));
	do
		echo "${line:$i:1},$ln_cnt,$sym_cnt"
		((sym_cnt++))
	done
	((ln_cnt++))
done > $TMPFILE

shuf $TMPFILE -o $TMPFILE

while read -r line;
do
	tmp="${line%,*}"
	a1="${tmp%,*}"
	a2="${tmp##*,}"
	a3="${line##*,}"
	tput cup $a2 $a3
	printf "%s" "$a1"
	
	if [ -n "$1" ]; then
		sleep $1
	fi

done < $TMPFILE

echo
tput cup $(tput lines) 0
