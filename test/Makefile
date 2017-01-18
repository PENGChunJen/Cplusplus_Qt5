CXX = g++
OPT = -O2 -std=c++11
INCLUDE = -I 
TLIB = -lm

CXXFLAGS = $(INCLUDE) $(OPT)

#-----Suffix Rules---------------------------
# set up C++ suffixes and relationship between .cc and .o files

.SUFFIXES: .cpp

.o :
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $<

.cpp :
	$(CXX) $(CXXFLAGS) $(INCLUDE) $< -o $@ -lm $(TLIB) 

#-----File Dependencies----------------------


SRC = $(SRC1) $(SRC2)
SRC1 = testCSVReader.cpp
SRC2 = map.cpp testMap.cpp

OBJ = $(addsuffix .o, $(basename $(SRC)))
OBJ1 = $(addsuffix .o, $(basename $(SRC1)))
OBJ2 = $(addsuffix .o, $(basename $(SRC2)))


all: testCSVReader testMap

debug: CXXFLAGS += -DDEBUG -g
debug: testCSVReader  testMap

testCSVReader: $(OBJ1)
	$(CXX) $(CXXFLAGS) $(INCLUDE) $(TLIB) -o $@ $(OBJ1)
testMap: $(OBJ2)
	$(CXX) $(CXXFLAGS) $(INCLUDE) $(TLIB) -o $@ $(OBJ2)

#-----Other stuff----------------------------
depend:
	makedepend -Y. $(SRC)

clean:
	rm -f $(OBJ)

# DO NOT DELETE
csvReader.o: csvReader.h
map.o: map.h
