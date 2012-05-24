
    #################################################################
    # 								    #
    # ⌬ NAME:		DEFAULT MAKEFILE FOR C++ PROJECTS 	    #
    # ⌬ AUTHOR:	A. JANUSZ				    #
    #								    #
    #   ⌬      FACULTY OF PHYSICS AND COMPUTER SCIENCE       ⌬     #
    #   ⌬  UNIVERSITY OF SCIENCE AND TECHNOLOGY AGH, CRACOW  ⌬     #
    # 								    #
    #################################################################

CXX=g++
CXXFLAGS=
LFLAGS=-lm -l pqxx -lpq
#DEFINES=-DDEBUG_MED
CXXFLAGS=-Wall $(DEFINES) -g -gstabs+ -pg
OBJS=DatabaseStorage.o QueryDispatcher.o GlobalCache.o
MAIN=GlobalCacheTest
RUN_PARAM=

all: $(OBJS)
	@echo "\n[+] LINKING FILES:"
	@echo "$(OBJS)"
	@$(CXX) $(LFLAGS) $(MAIN).cpp -o $(MAIN) $(OBJS)
	@echo ""

obj: $(OBJS)
	@$(CXX) $(CXXFLAGS) $^ -o $@ -c $(DEFINES)

$(OBJS): %.o: %.cpp
	@echo "[+] Compiling $@ ..."
	@$(CXX) $(LFLAGS) $< -o $@ -c

clean: 
	@rm -rf *.o *~

run: all
	@./$(MAIN) $(RUN_PARAM)

.PHONY: clean all run obj
