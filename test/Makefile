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


SRC = $(SRC1)
SRC1 = testCSVReader.cpp

OBJ = $(addsuffix .o, $(basename $(SRC)))
OBJ1 = $(addsuffix .o, $(basename $(SRC1)))


all: testCSVReader

debug: CXXFLAGS += -DDEBUG -g
debug: testCSVReader  

testCSVReader: $(OBJ1)
	$(CXX) $(CXXFLAGS) $(INCLUDE) $(TLIB) -o $@ $(OBJ1)

#-----Other stuff----------------------------
depend:
	makedepend -Y. $(SRC)

clean:
	rm -f $(OBJ)

# DO NOT DELETE
csvReader.o: csvReader.h
