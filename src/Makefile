CFLAGS = -Wall -std=c++11 $(shell pkg-config --cflags sfml-all)
CLIBS = $(shell pkg-config --libs sfml-all) -lm
PROG = gol

all: $(PROG)

OBJS = main.o matrix.o

main.o: main.cpp matrix.hpp
matrix.o: matrix.cpp matrix.hpp


# There shouldn't be a need to touch the rules below.
$(PROG): $(OBJS)
	$(CXX) $(CFLAGS) $^ -o $@ $(CLIBS)
%.o: %.cpp
	$(CXX) $(CFLAGS) $< -c -o $@  $(CLIBS)

.PHONY: clean, all, run

run: $(PROG)
	./$(PROG)

clean:
	rm -rf $(OBJS) $(PROG)
