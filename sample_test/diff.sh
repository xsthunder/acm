#!/bin/bash
while true;do
	./rand >input
	./sam <input >output.sam
	./my <input >output.my
	diff output.sam output.my
	if [ $? -ne 0 ] ; then break; fi
done
