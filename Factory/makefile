#######################################################
# makefile for Design Pattern example code - factory
# hprakash@iu.edu, hitenderprakash@gmail.com
#######################################################
CC=g++ -std=c++11
OPTS=
INCS=
LIBS= 

%.o: %.cpp
	$(CC) $(OPTS) $(INCS) -c $<

factory: factory.o
	$(CC) $(OPTS) $(INCS) -o $@ $^  $(LIBS)

run: factory
	@./factory

clean:
	rm -f factory *.o
