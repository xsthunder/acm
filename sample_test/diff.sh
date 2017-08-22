#!/bin/bash
g++ -std=c++11 sam.cc -o sam.out
g++ -std=c++11 my.cc -o my.out 
echo "finish build"
while true;do
	python3 ./py.py>input
	echo "end input gen"

	#./my.out <input >output.my
	time ./my.out 
	if [ $? -ne 0 ] ; then break; fi

	time ./sam.out 
	#./sam.out <input >output.sam
	if [ $? -ne 0 ] ; then break; fi

	#diff output.my output.sam 
	diff output.my output.sam >log.diff
	if [ $? -ne 0 ] ; then break; fi
done
