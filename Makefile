CC = g++
CPPFLAGS = -lstdc++

GTEST_DIR = /Users/leonid/vendor/gtest-1.6.0
GTEST_FLAGS = -I$(GTEST_DIR)/include -L$(GTEST_DIR)/lib/.libs -lgtest
GTEST_DYLD_PATH = $(GTEST_DIR)/lib/.libs

all: lab1 lab2

test: lab1_test lab2_test

lab1: lab1.cpp lab1_functions.cpp
	$(CC) $(CPPFLAGS) lab1.cpp lab1_functions.cpp -o bin/lab1

lab2: lab2.cpp lab2_functions.cpp lab1_functions.cpp
	$(CC) $(CPPFLAGS) lab2.cpp lab2_functions.cpp lab1_functions.cpp -o bin/lab2

lab1_test: lab1_test.cpp lab1_functions.cpp test_harness.cpp
	$(CC) $(CPPFLAGS) $(GTEST_FLAGS) lab1_test.cpp lab1_functions.cpp test_harness.cpp -o bin/lab1_test
	DYLD_LIBRARY_PATH=$(GTEST_DYLD_PATH) bin/lab1_test

lab2_test: lab2_test.cpp lab2_functions.cpp test_harness.cpp
	$(CC) $(CPPFLAGS) $(GTEST_FLAGS) lab2_test.cpp lab2_functions.cpp test_harness.cpp -o bin/lab2_test
	DYLD_LIBRARY_PATH=$(GTEST_DYLD_PATH) bin/lab2_test


clean:
	rm bin/*
