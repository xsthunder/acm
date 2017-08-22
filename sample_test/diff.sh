#!/bin/bash
g++ -std=c++11 sam.cpp -o sam.exe
g++ -std=c++11 my.cpp -o my.exe
echo "finish build"
while true;do
	python3 ./py.py>input
	echo "end input gen"
	time ./sam.exe <input >output.sam
	if [ $? -ne 0 ] ; then break; fi
	time ./my.exe <input >output.my
	if [ $? -ne 0 ] ; then break; fi
	diff output.my output.sam
	if [ $? -ne 0 ] ; then break; fi
done
