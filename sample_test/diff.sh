#!/bin/bash
g++ -std=c++11 sam.cpp -o sam.exe
g++ -std=c++11 my.cpp -o my.exe
while true;do
	python3 ./py.py>input
	./sam <input >output.sam
	if [ $? -ne 0 ] ; then break; fi
	./my <input >output.my
	if [ $? -ne 0 ] ; then break; fi
	diff output.my output.sam 
	if [ $? -ne 0 ] ; then break; fi
done
