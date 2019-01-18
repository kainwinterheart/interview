TARGET = interview-logs

CXX ?= clang++

MAKEFILE_DIR := $(shell dirname $(realpath $(lastword $(MAKEFILE_LIST))))

ROOT_DIR := $(MAKEFILE_DIR)/..
COMMON_DIR := $(ROOT_DIR)/../common
CONTRIB_DIR := $(ROOT_DIR)/../contrib
AC_COMMON_DIR := $(ROOT_DIR)/../ac-common
AC_LIBRARY_DIR := $(ROOT_DIR)/../ac-library

HTTP_DIR := $(AC_LIBRARY_DIR)/http
HTTPLIKE_DIR := $(AC_LIBRARY_DIR)/httplike
NET_DIR := $(AC_LIBRARY_DIR)/net
HTTP_SERVER_DIR := $(HTTP_DIR)/server
HTTPLIKE_SERVER_DIR := $(HTTPLIKE_DIR)/server
NET_SERVER_DIR := $(NET_DIR)/server
NET_CLIENT_DIR := $(NET_DIR)/client
APP_DIR := $(MAKEFILE_DIR)

OBJS = $(AC_COMMON_DIR)/round_robin_vector.o $(AC_COMMON_DIR)/utils/string.o $(AC_COMMON_DIR)/utils/socket.o $(AC_COMMON_DIR)/muhev.o $(AC_COMMON_DIR)/worker_lite.o $(AC_COMMON_DIR)/spin_lock.o $(AC_COMMON_DIR)/str.o $(HTTPLIKE_DIR)/parser/parser.o $(NET_SERVER_DIR)/server.o $(NET_SERVER_DIR)/client_thread.o $(NET_SERVER_DIR)/client.o $(NET_SERVER_DIR)/add_client.o $(NET_CLIENT_DIR)/connect.o $(HTTPLIKE_SERVER_DIR)/client.o $(HTTP_SERVER_DIR)/server.o $(HTTP_SERVER_DIR)/client.o $(HTTP_SERVER_DIR)/responder.o $(HTTP_DIR)/handler/handler.o $(HTTP_DIR)/request.o $(HTTP_DIR)/cookies.o $(HTTP_DIR)/urlescape.o $(HTTP_DIR)/response.o $(APP_DIR)/main.o

INCLUDE_FLAGS := $(INCLUDE_FLAGS) -I$(COMMON_DIR) -I$(AC_COMMON_DIR) -I$(AC_LIBRARY_DIR) -I$(CONTRIB_DIR)

CXXFLAGS := $(CXXFLAGS) $(INCLUDE_FLAGS) -O3 -std=c++17 -Wno-expansion-to-defined

LIBRARY_FLAGS := $(LIBRARY_FLAGS)

LIBS := $(LIBS) -lpthread

LDFLAGS := $(LIBRARY_FLAGS) #-fsanitize=address -g -Wl,-no_pie

$(TARGET): $(OBJS)
	$(CXX) $(LDFLAGS) $(OBJS) -o $(MAKEFILE_DIR)/$(TARGET) $(LIBS)
