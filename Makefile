CC = g++
CPPFLAGS = -lstdc++

SOURCES = lab1.cpp lab1_functions.cpp

TEST_SOURCES = lab1_test.cpp lab1_functions.cpp test_harness.cpp
GTEST_DIR = /Users/leonid/vendor/gtest-1.6.0
GTEST_FLAGS = -I$(GTEST_DIR)/include -L$(GTEST_DIR)/lib/.libs -lgtest
GTEST_DYLD_PATH = $(GTEST_DIR)/lib/.libs

all: lab1

test: lab1_test

lab1: $(SOURCES)
	$(CC) $(CPPFLAGS) $(SOURCES) -o bin/lab1

lab1_test: $(TEST_SOURCES)
	$(CC) $(CPPFLAGS) $(GTEST_FLAGS) $(TEST_SOURCES)  -o bin/lab1_test
	DYLD_LIBRARY_PATH=$(GTEST_DYLD_PATH) bin/lab1_test


clean:
	rm bin/*
