CXX = g++
CXXFLAG =	-std=c++11 -pthread -Wall -Wconversion -Werror -Wextra -Wno-unused-parameter \
						-Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow \
						-Wwrite-strings -march=native -rdynamic

SOURCE	= $(shell find . -maxdepth 1 -name '*.cc')
TEST = $(SOURCE:.cc=.out)

all: $(TEST)

.cc.out:
	$(CXX) $(CXXFLAG) -o $@ $<

clean:
	rm -f $(TEST) *~
