coronablinkern: coronablinkern.o date.o
	gcc -Wall -pedantic -g coronablinkern.o date.o -o coronablinkern
coronablinkern.o: coronablinkern.c date.h
	gcc -Wall -pedantic -c -g coronablinkern.c -o coronablinkern.o
date.o: date.c date.h
	gcc -Wall -pedantic -g -c date.c -o date.o