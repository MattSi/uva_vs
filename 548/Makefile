CC=clang
CPP=g++
CFLAGS=-O2 -pipe -ansi 
CPPFLAGS=-lm -lcrypt -O2 -pipe 
LIBS=-lm -lcrypt 
ALL= 120 548 112 123 263  264 340 400 401 424 644 673 755 755ac 10152 10152ac 10010 10115 10361 10815
TESTDIR=./tests/
all:$(ALL)

112:112.c
	$(CC) $< -o $@ $(CFLAGS) $(LIBS) 
120:120.c
	$(CC) $< -o $@ $(CFLAGS) $(LIBS) 
123:123.c
	$(CC) $< -o $@ $(CFLAGS) $(LIBS) 

263:263.c
	$(CC) $< -o $@ $(CFLAGS) $(LIBS) 

264:264.c
	$(CC) $< -o $@ $(CFLAGS) $(LIBS) 

340:340.c
	$(CC) $< -o $@ $(CFLAGS) $(LIBS) 
401:401.c
	$(CC) $< -o $@ $(CFLAGS) $(LIBS)

424:424.c
	$(CC) $< -o $@ $(CFLAGS) $(LIBS)
644:644.c
	$(CC) $< -o $@ $(CFLAGS) $(LIBS) 
673:673.c
	$(CC) $< -o $@ $(CFLAGS) $(LIBS) 

400:400.c
	$(CC) $< -o $@ $(CFLAGS) $(LIBS) 

548:548.c
	$(CC) $< -o $@ $(CFLAGS) $(LIBS) 
755:755.cpp
	$(CC) $< -o $@ $(CFLAGS) $(LIBS) 
	
755ac:755ac.cpp
	$(CC) $< -o $@ $(CFLAGS) $(LIBS) 
10010:10010.c
	$(CC) $< -o $@ $(CFLAGS) $(LIBS) 

10115:10115.c
	$(CC) $< -o $@ $(CFLAGS) $(LIBS) 
10152:10152.c
	$(CC) $< -o $@ $(CFLAGS) $(LIBS) 
10152ac:10152ac.c
	$(CC) $< -o $@ $(CFLAGS) $(LIBS) 
10361:10361.c
	$(CC) $< -o $@ $(CFLAGS) $(LIBS)
	
10815:10815.c
	$(CC) $< -o $@ $(CFLAGS) $(LIBS) 


.PYONY: clean cleanobj cleanout
clean:cleanobj cleanout
	-rm  -rf $(ALL) 

cleanobj:
	-rm -f *.o

cleanout:
	-rm -f $(TESTDIR)*.out



