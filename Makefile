EXEC=ageOfWar
CXX=g++
CXXFLAGS=-Wall -Wextra -Werror -std=c++14
SRCS := $(shell ls *.cpp)
OBJS := $(SRCS:.cpp=.o)
DEPS := $(SRCS:.cpp=.d)

all: $(EXEC)


# dependency graph of included header files
%.d: %.cpp
	$(CXX) $(CXXFLAGS) -MM -MF $(patsubst %.o,%.d,$@) -o $@ $<

-include $(DEPS)


# compiler rules
%.o: %.cpp %.d
	$(CXX) $(CXXFLAGS) $< -c -o $@

$(EXEC): $(OBJS)
	$(CXX) $^ -o $@


# extra rules
.PHONY: run clean cleanall

run: ex8
	./$< $(PARAM)

clean:
	rm -f *.d *.o *~

clean_all: clean
	rm -f $(EXEC)
