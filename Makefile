listP : listP.o
	gcc -o listP listP.o

listC : listC.o
	gcc -o listC listC.o

listP.o : listP.c
	gcc -c -o listP.o listP.c
  
listC.o : listC.c
	gcc -c -o listC.o listC.c
  
clean : 
	rm *.o listP
	rm *.o listC