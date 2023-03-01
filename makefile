CXX=g++
CXXFLAGS = -std=c++17 -O3

LIBS=  -lm 

CXX_SOURCES= main.cpp
CXX_OBJECTS= main.o
OBJS= $(CXX_OBJECTS)

#targets
all: test

test: $(CXX_OBJECTS) $(C_OBJECTS)
	$(CXX) $^ $(CXXFLAGS) -o $@ $(LIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f $(OBJS)
