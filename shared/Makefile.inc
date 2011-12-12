CPP = g++
CPPFLAGS = -lstdc++

GTEST_DIR = /Users/leonid/vendor/gtest-1.6.0
GTEST_FLAGS = -I$(GTEST_DIR)/include -L$(GTEST_DIR)/lib/.libs -lgtest
GTEST_DYLD_PATH = $(GTEST_DIR)/lib/.libs
GTEST_ENV = DYLD_LIBRARY_PATH=$(GTEST_DYLD_PATH)


bin/$(APP)$(BINEXT): *.cpp
	mkdir -p bin
	$(CPP) $(CPPFLAGS) *.cpp -o bin/$(APP)$(BINEXT)

bin/$(APP)_test$(BINEXT): *.cpp test/*.cpp
	mkdir -p bin
	$(CPP) $(CPPFLAGS) $(GTEST_FLAGS) *.cpp test/*.cpp bin/$(APP)_test$(BINEXT)
	$(GTEST_ENV) bin/$(APP)_test$(BINEXT)

test: bin/$(APP)_test$(BINEXT)

clean:
	rm bin/*

