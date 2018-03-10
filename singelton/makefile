#######################################################
# makefile for Design Pattern example code - singelton
# hprakash@iu.edu, hitenderprakash@gmail.com
#######################################################
CC=g++ -std=c++11
OPTS=
INCS=
LIBS= -pthread

%.o: %.cpp
	$(CC) $(OPTS) $(INCS) -c $<

singelton: singelton.o 
	$(CC) $(OPTS) $(INCS) -o $@ $^  $(LIBS)

run: singelton
	@./singelton

clean:
	rm -f singelton *.o
