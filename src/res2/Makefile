TARGET = interview-res2

CXX ?= clang++

MAKEFILE_DIR := $(shell dirname $(realpath $(lastword $(MAKEFILE_LIST))))

ROOT_DIR := $(MAKEFILE_DIR)/..
COMMON_DIR := $(ROOT_DIR)/../common
CONTRIB_DIR := $(ROOT_DIR)/../contrib
AC_COMMON_DIR := $(ROOT_DIR)/../ac-common
AC_LIBRARY_DIR := $(ROOT_DIR)/../ac-library

APP_DIR := $(MAKEFILE_DIR)

OBJS = $(APP_DIR)/main.o

INCLUDE_FLAGS := $(INCLUDE_FLAGS) -I$(COMMON_DIR) -I$(AC_COMMON_DIR) -I$(AC_LIBRARY_DIR) -I$(CONTRIB_DIR)

CXXFLAGS := $(CXXFLAGS) $(INCLUDE_FLAGS) -O3 -std=c++17 -Wno-expansion-to-defined

LIBRARY_FLAGS := $(LIBRARY_FLAGS)

LIBS := $(LIBS)

LDFLAGS := $(LIBRARY_FLAGS) #-fsanitize=address -g -Wl,-no_pie

$(TARGET): $(OBJS)
	$(CXX) $(LDFLAGS) $(OBJS) -o $(MAKEFILE_DIR)/$(TARGET) $(LIBS)
