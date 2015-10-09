CC = g++
CXX = g++
CXXFLAGS = -pedantic -Wall -Werror -std=c++11

TARGETS	= Lab2_ex2 ex1

.PHONY: all
all: $(TARGETS)

.PHONY: clean
clean:
	$(RM) $(TARGETS) *.o

Lab2_ex2: Lab2_ex2.o Shop.o Item.o Book.o Cd.o Dvd.o

Lab2_ex2.o: Lab2_ex2.cpp

Shop.o: Shop.cpp Shop.h

Item.o: Item.cpp Item.h

Book.o: Book.cpp Book.h

Cd.o: Cd.cpp Cd.h

Dvd.o: Dvd.cpp Dvd.h

ex1: ex1.o Creature.o

ex1.o: ex1.cpp

Creature.o: Creature.h Creature.cpp