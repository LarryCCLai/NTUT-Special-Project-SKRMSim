.PHONY:clean all
CC = g++
#ls -l 
#grep ^d: search dirs
#awk: print name of dirs
SUBDIRS = $(shell ls -l | grep ^d | awk '{if($$9 != "debug") if($$9 != "include") print $$9}')

ROOT_DIR = $(shell pwd)
#executed file name
BIN = simulator
#obj file dir
OBJS_DIR=debug/obj
#bin file dir
BIN_DIR=debug/bin

#get cpp file set in current dir.
CUR_SOURCE=${wildcard *.cpp}
#trans .cpp file to .o 
CUR_OBJS=${patsubst %.cpp, %.o, $(CUR_SOURCE)}
#share variables to makefile of sub dir 
export CC BIN OBJS_DIR BIN_DIR ROOT_DIR

all: $(SUBDIRS) $(CUR_OBJS) DEBUG
#Recursively run makefile of sub dir
$(SUBDIRS): ECHO
	make -C $@
DEBUG: ECHO
	make -C debug
ECHO:
	@echo $(SUBDIRS)
#Compile cpp file
$(CUR_OBJS):%.o:%.cpp
	$(CC) -std=c++11 -c $^ -o $(ROOT_DIR)/$(OBJS_DIR)/$@
clean:
	rm -rf $(OBJS_DIR)/*.o
	rm -rf $(BIN_DIR)/*