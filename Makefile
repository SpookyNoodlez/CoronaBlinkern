coronablinkern: coronablinkern.o linkedCodeList.o date.o
	gcc $ -Wall -pedantic coronablinkern.o linkedCodeList.o date.o -o coronablinkern
coronablinkern.o: coronablinkern.c linkedCodeList.h date.h
	gcc $ -Wall -pedantic -c coronablinkern.c -o coronablinkern.o
linkedCodeList.o: linkedCodeList.c linkedCodeList.h date.h
	gcc $ -Wall -pedantic -c linkedCodeList.c -o linkedCodeList.o
date.o: date.c date.h
	gcc $ -Wall -pedantic -c date.c -o date.o