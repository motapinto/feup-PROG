CC=g++ -std=c++11
CFLAGS=-I. -Wall -Wextra -Werror
DEPS = UtilityFunctions.h date.h address.h travelpack.h agency.h client.h files.h menu.h
OBJ = main.o UtilityFunctions.o date.o address.o travelpack.o agency.o client.o files.o menu.o

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: all clean

clean:
	rm -f $(TARGETS) *.o *.d *.i *.s