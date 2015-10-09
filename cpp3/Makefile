
TARGETS = Lab3
CXXFLAGS += -std=c++11
LOADLIBES += -lstdc++

.PHONY: all
all: $(TARGETS)

.PHONY: clean
clean:
	$(RM) $(TARGETS) *.o

Lab3: Lab3.o life.o

Lab3.o: Lab3.cpp life.h

life.o: life.cpp life.h

