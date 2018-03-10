#######################################################
# makefile for Design Pattern example code - abstractFactory
# hprakash@iu.edu, hitenderprakash@gmail.com
#######################################################
CC=g++ -std=c++11
OPTS=
INCS=
LIBS= 

%.o: %.cpp
	$(CC) $(OPTS) $(INCS) -c $<

abstractFactory: abstractFactory.o
	$(CC) $(OPTS) $(INCS) -o $@ $^  $(LIBS)

run: abstractFactory
	@./abstractFactory

clean:
	rm -f abstractFactory *.o
