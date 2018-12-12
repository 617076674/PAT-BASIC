# !/bin/bash

read input
sum=0
digits=("ling" "yi" "er" "san" "si" "wu" "liu" "qi" "ba" "jiu")
for (( i = 0; i < ${#input}; i++ ));
do
	sum=$(expr $sum + ${input:${i}:1})
done
for (( i = 0; i < ${#sum}; i++));
do
	echo -e "${digits[${sum:${i}:1}]}\c"
	if [ $i -ne $(expr ${#sum} - 1) ]
	then
		echo -e " \c"
	fi
done