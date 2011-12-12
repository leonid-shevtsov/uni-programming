DIRS = $(filter-out ./shared ./.git, $(shell find . -d 1 -type d))

all:
	$(foreach dir, $(DIRS), cd $(dir); make;cd ..;)

test:
	$(foreach dir, $(DIRS), cd $(dir); make test;cd ..;)

clean:
	$(foreach dir, $(DIRS), cd $(dir); make clean;cd ..;)
