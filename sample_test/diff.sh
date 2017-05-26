#!/bin/bash
while true;do
	./rand >input
	./sam <input >output.sam
	if [ $? -ne 0 ] ; then break; fi
	./my <input >output.my
	if [ $? -ne 0 ] ; then break; fi
	diff output.sam output.my
	if [ $? -ne 0 ] ; then break; fi
done
