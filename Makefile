CC=g++
CFLAGS=-g -Wall
OBJS=main.o Account.o ATM.o Bank.o
TARGET=atm.out

all: $(TARGET)

clean:
	rm -f *.o
	rm -f $(TARGET)

$(TARGET): $(OBJS)
	$(CC)  -o $@ $(OBJS)

Account.o: Account.h Account.cpp
ATM.o: UI.h ATM.h Bank.h ATM.cpp
Bank.o: Bank.h Account.h Bank.cpp
main.o: ATM.h Bank.h Account.h main.cpp
