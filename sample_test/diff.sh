#!/bin/bash
g++ -std=c++11 sam.cc -o sam.out
g++ -std=c++11 my.cc -o my.out
echo "finish build"
while true;do
	python3 ./py.py>input
	echo "end input gen"
	time ./sam.exe 
	#./sam.exe <input >output.sam
	if [ $? -ne 0 ] ; then break; fi
	time ./my.exe 
	#./sam.exe <input >output.my
	if [ $? -ne 0 ] ; then break; fi
	diff output.my output.sam >log.diff
	#diff output.my output.sam 
	if [ $? -ne 0 ] ; then break; fi
done
