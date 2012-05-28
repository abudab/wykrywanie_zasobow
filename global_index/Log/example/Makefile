
# Target binaries
PROG=test

# Compiler
GCC=g++

# C++ compile flags
#CFLAGS+=-DFTLOG
#CFLAGS+=-DFTLOG="${PROG}"
CFLAGS+=-DETLOG
#CFLAGS+=-DTLOG
#CFLAGS+=-DCLEANTLOG

CC=${GCC} -c ${INCLUDE} ${CFLAGS} ${GFLAGS}
LINK=${GCC} ${GFLAGS} ${LFLAGS}

.PHONY: program
program: ${PROG}

all: ${PROG}

${PROG}: foo.o main.o tri_logger.o
	@ echo "LINK ->" $@.debug
	@ ${LINK} foo.o main.o tri_logger.o -o $@.debug
	@ echo "STRIP ->" $@
	@ strip -R .comment -R .note -R .note.ABI-tag -s $@.debug -o $@

foo.o: foo.cpp
	@ echo COMPILE $<
	@ ${CC} $<

main.o: main.cpp
	@ echo COMPILE $<
	@ ${CC} $<

tri_logger.o: tri_logger.cpp
	@ echo COMPILE $<
	@ ${CC} $<

clean:
	@ echo CLEAN *.o
	@ rm -f -v *.o
	@ echo CLEAN ${PROG}
	@ rm -f -v ${PROG}
	@ rm -f -v ${PROG}.debug

