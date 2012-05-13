APP = kr_may_2012

all: bin/quick_sort$(BINEXT) bin/random_quick_sort$(BINEXT) bin/intro_sort$(BINEXT) bin/speedtest$(BINEXT)

include ../shared/Makefile.inc

SOURCES = main.cpp input_output.cpp custom_qsort.cpp randomized_qsort.cpp intro_sort.cpp heap_sort.cpp
SPEEDTEST_SOURCES = speedtest.cpp generators.cpp custom_qsort.cpp randomized_qsort.cpp intro_sort.cpp heap_sort.cpp

bin/quick_sort$(BINEXT): $(SOURCES)
	mkdir -p bin
	$(CPP) $(CPPFLAGS) $(SOURCES) -DSORT_FUNCTION=customQsort -o bin/quick_sort$(BINEXT)

bin/random_quick_sort$(BINEXT): $(SOURCES)
	mkdir -p bin
	$(CPP) $(CPPFLAGS) $(SOURCES) -DSORT_FUNCTION=randomizedQsort -o bin/random_quick_sort$(BINEXT)

bin/intro_sort$(BINEXT): $(SOURCES)
	mkdir -p bin
	$(CPP) $(CPPFLAGS) $(SOURCES) -DSORT_FUNCTION=introSort -o bin/intro_sort$(BINEXT)

bin/speedtest$(BINEXT): $(SPEEDTEST_SOURCES)
	mkdir -p bin
	$(CPP) $(CPPFLAGS) $(SPEEDTEST_SOURCES) -o bin/speedtest$(BINEXT)
