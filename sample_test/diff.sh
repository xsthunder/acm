#!/bin/bash
g++ -std=c++11 sam.cc -o sam.out
g++ -std=c++11 my.cc -o my.outt 
echo "finish build"
while true;do
	python3 ./py.py>input
	echo "end input gen"
	#./sam.out <input >output.my
	if [ $? -ne 0 ] ; then break; fi
	diff output.my output.sam >log.diff
	time ./sam.out 
	#./sam.out <input >output.sam
	if [ $? -ne 0 ] ; then break; fi
	time ./my.out 
	#diff output.my output.sam 
	if [ $? -ne 0 ] ; then break; fi
done
