listP : listP.o
	gcc -o listP listP.o

listA : listA.o
	gcc -o listA listA.o

listP.o : listP.c
	gcc -c -o listP.o listP.c
  
listA.o : listA.c
	gcc -c -o listA.o listA.c
  
clean : 
	rm *.o listP
	rm *.o listA