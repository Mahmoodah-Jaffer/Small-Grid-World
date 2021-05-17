CC = g++
CCFLAGS=--std=c++11

value: driver.o #making an executable file that can be run
	$(CC) $(CCFLAGS) -o value driver.o value.o state.o

driver.o: value.o driver.cpp 
	$(CC) $(CCFLAGS) -O -c driver.cpp 

value.o: state.o value.h value.cpp 
	$(CC) $(CCFLAGS) -O -c value.cpp 

state.o: state.h state.cpp
	$(CC) $(CCFLAGS) -O -c state.cpp


run: #change command line parameters here
	./value
clean:
	@rm -f *.o #removing object files
	@rm value #removing the executable produced 