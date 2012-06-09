CXX=g++
CXXFLAGS=-Wall -pedantic -c -g
LDFLAGS=-lpqxx -lcurlpp

DB_SRC=db/DatabaseStorage.cpp db/GlobalCache.cpp db/QueryDispatcher.cpp
SRC=$(DB_SRC) Net/*.cpp pugi/*.cpp XML/*.cpp

LIST_SRC=$(SRC) List.cpp  
MAIN_SRC=$(SRC) main.cpp 
REGISTER_SRC=$(SRC) Registration_main.cpp 
LOCAL_LIST_SRC=$(SRC) LocalIndexList.cpp


OBJ:= $(patsubst %.cpp, %.o, $(wildcard $(SRC)))

INC=*.hpp db/*.hxx Net/*.h pugi/*.h XML/*.h

LIST=bin/List
MAIN=bin/GlobalIndex
REGISTER=bin/Registration
LOCAL_LIST=bin/LocalIndexList

all : list main register local_list

list : List.o $(OBJ) 
	@echo "Linking $(LIST)"
	@$(CXX) $(LDFLAGS) -o $(LIST) $(OBJ) List.o

main : $(OBJ) main.o
	@echo "Linking $(MAIN)"
	@$(CXX) $(LDFLAGS) -o $(MAIN) $(OBJ) main.o

register : Registration_main.o $(OBJ)
	@echo "Linking $(REGISTER)"
	@$(CXX) $(LDFLAGS) -o $(REGISTER) $(OBJ) Registration_main.o

local_list :  LocalIndexList.o $(OBJ)
	@echo "Linking $(LOCAL_LIST)"
	@$(CXX) $(LDFLAGS) -o $(LOCAL_LIST) $(OBJ) LocalIndexList.o


$(OBJ) : %.o : %.cpp
	@echo "Compile $<"
	@$(CXX) $(CXXFLAGS) -o $@ $< 




main.o :
	@echo "Compile main.cpp"
	@$(CXX) $(CXXFLAGS) -o main.o main.cpp

List.o :
	@echo "Compile List.cpp"
	@$(CXX) $(CXXFLAGS) -o List.o List.cpp

Registration_main.o :
	@echo "Compile Registration_main.cpp"
	@$(CXX) $(CXXFLAGS) -o Registration_main.o Registration_main.cpp

LocalIndexList.o :
	@echo "Compile LocalIndexList.cpp"
	@$(CXX) $(CXXFLAGS) -o LocalIndexList.o LocalIndexList.cpp

clean : 
	rm -f $(MAIN)
	rm -f $(LIST)
	rm -f $(REGISTER)
	rm -f $(LOCAL_LIST)
	rm -f $(OBJ)
	rm -f main.o List.o
