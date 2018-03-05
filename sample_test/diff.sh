#!/bin/bash
g++ -std=c++11 -D DIFF sam.cc -o sam.out
g++ -std=c++11 -D DIFF my.cc -o my.out 
echo "finish build"
while true;do
	python3 ./py.py>input; echo "end input gen"


	time sh -c "./sam.out <input >output.sam"
	#./sam.out 
	if [ $? -ne 0 ] ; then echo "sam err" break; fi

	time sh -c "./my.out <input >output.my"
	#./my.out 
	if [ $? -ne 0 ] ; then echo "my err ";break; fi

	#diff output.my output.sam 
	diff output.my output.sam >log.diff
	if [ $? -ne 0 ] ; then echo "find diff";break; fi
done
