CXX=g++
CXXFLAGS=-Wall -Wextra -Werror -std=c++14
OBJS=Battlefield.o Unit.o main.o
EXEC=ageOfWar

all: $(EXEC)


# header dependecies
-include $(OBJS:.o=.d)

%.d: %.cpp
	$(CXX) $(CXXFLAGS) -MM -MF $(patsubst %.o,%.d,$@) -o $@ $<


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
