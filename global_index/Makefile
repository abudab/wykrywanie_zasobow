CXX=g++
CXXFLAGS=-Wall -pedantic -c -g
LDFLAGS=-lpqxx -lcurlpp

DB_SRC=db/DatabaseStorage.cpp db/GlobalCache.cpp db/QueryDispatcher.cpp
SRC=$(DB_SRC) Net/*.cpp pugi/*.cpp XML/*.cpp

LIST_SRC=$(SRC) List.cpp  
MAIN_SRC=$(SRC) main.cpp  

OBJ:= $(patsubst %.cpp, %.o, $(wildcard $(SRC)))

INC=*.hpp db/*.hxx Net/*.h pugi/*.h XML/*.h

LIST=bin/List
MAIN=bin/GlobalIndex

all : list main

list : List.o $(OBJ) 
	@echo "Linking $(LIST)"
	@$(CXX) $(LDFLAGS) -o $(LIST) $(OBJ) List.o

main : $(OBJ) main.o
	@echo "Linking $(MAIN)"
	@$(CXX) $(LDFLAGS) -o $(MAIN) $(OBJ) main.o

$(OBJ) : %.o : %.cpp
	@echo "Compile $<"
	@$(CXX) $(CXXFLAGS) -o $@ $< 

main.o :
	@echo "Compile main.cpp"
	@$(CXX) $(CXXFLAGS) -o main.o main.cpp

List.o :
	@echo "Compile List.cpp"
	@$(CXX) $(CXXFLAGS) -o List.o List.cpp

clean : 
	rm -f $(MAIN)
	rm -f $(LIST)
	rm -f $(OBJ)
	rm -f main.o List.o
