coronablinkern: coronablinkern.o tree.o date.o
	gcc -Wall -pedantic -g coronablinkern.o tree.o date.o -o coronablinkern
coronablinkern.o: coronablinkern.c tree.h date.h
	gcc -Wall -pedantic -c -g coronablinkern.c -o coronablinkern.o
tree.o: tree.c tree.h date.h
	gcc -Wall -pedantic -c -g tree.c -o tree.o
date.o: date.c date.h
	gcc -Wall -pedantic -g -c date.c -o date.o