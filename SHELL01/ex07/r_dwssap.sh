#!/bin/sh
cat /etc/passwd | sed 's/:.*//' | sed -n 'n;p' | rev | sort -r | sed ''"$FT_LINE1"','"$FT_LINE2"'!d' | tr -s '\n' ',' | sed 's/, */, /g' | sed 's/, $/./g'
