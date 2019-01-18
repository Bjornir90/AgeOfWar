EXEC=ageOfWar
CXX=g++
CXXFLAGS=-Wall -Wextra -std=c++14

SRCS := $(wildcard *.cpp)
OBJS := $(SRCS:.cpp=.o)
DEPS := $(SRCS:.cpp=.d)

all: $(EXEC)

# compiler rules
$(EXEC): $(OBJS)
	$(CXX) $^ -o $@

%.o: %.cpp
	$(CXX) -MM -MF $(patsubst %.o,%.d,$@) $<
	$(CXX) $(CXXFLAGS) $< -c -o $@

-include $(DEPS)

# extra rules
.PHONY: run clean cleanall

clean:
	rm -f *.d *.o *~

clean_all: clean
	rm -f $(EXEC)
