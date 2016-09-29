#!/bin/bash
while true;do
	./rand >input
	./sam <input >output.sam
	./my <input >output.my
	echo -e "#####################"
	echo -e "\n------------------------input\n ------------"
	cat input
	echo -e "\n-----------------------output.my \n ------------"
	cat output.my
	echo -e "\n------------------------output,sam \n ------------"
	cat output.sam
	diff output.sam output.my
	if [ $? -ne 0 ] ; then break; fi
	echo -e "#####################"
done
