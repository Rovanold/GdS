prog:	main.c fonction.c header.h procedure.c
	gcc main.c -o main

run:	
	./main

clean:	
	rm prog
