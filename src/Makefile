CXX = g++
OPT = -O2 -std=c++11
INCLUDE = -I ../util/
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
SRC1 = position.cpp object.cpp wall.cpp car.cpp park.cpp map.cpp testMap.cpp 
SRC2 = position.cpp object.cpp wall.cpp car.cpp park.cpp map.cpp agent.cpp randomAgent.cpp game.cpp testGame.cpp

OBJ = $(addsuffix .o, $(basename $(SRC)))
OBJ1 = $(addsuffix .o, $(basename $(SRC1)))
OBJ2 = $(addsuffix .o, $(basename $(SRC2)))


all: testMap testGame

debug: CXXFLAGS += -DDEBUG -g
debug: testCSVReader  testMap

testMap: $(OBJ1)
	$(CXX) $(CXXFLAGS) $(INCLUDE) $(TLIB) -o $@ $(OBJ1)

testGame: $(OBJ2)
	$(CXX) $(CXXFLAGS) $(INCLUDE) $(TLIB) -o $@ $(OBJ2)

#-----Other stuff----------------------------
depend:
	makedepend -Y. $(SRC)

clean:
	rm -f $(OBJ)

# DO NOT DELETE
csvReader.o: csvReader.h

position.o: position.h
object.o: object.h
wall.o: wall.h
car.o: car.h
park.o: park.h
map.o: map.h

agent.o: agent.h
randomAgent.o: randomAgent.h
game.o: game.h
