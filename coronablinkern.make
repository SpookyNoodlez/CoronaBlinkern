CFLAGS = -Wall -pedantic

coronablinkern: coronablinkern.o linkedCodeList.o date.o
    gcc $ (CFLAGS) coronablinkern.o linkedCodeList.o date.o -o coronablinkern
    
coronablinkern.o: coronablinkern.c linkedCodeList.h date.h
    gcc $ (CFLAGS) -c coronablinkern.c -o coronablinkern.o

linkedCodeList.o: linkedCodeList.c linkedCodeList.h date.h
    gcc $ (CFLAGS) -c linkedCodeList.c -o linkedCodeList.o

date.o: date.c date.h
    gcc $ (CFLAGS) -c date.c -o date.o