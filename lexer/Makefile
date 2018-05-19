SUFFIX = .c

SOURCES = $(wildcard *$(SUFFIX))
OBJECTS = $(notdir $(SOURCES:$(SUFFIX)=.o))
TARGETS = $(notdir $(basename $(SOURCES)))

.PHONY: all
all: $(TARGETS)

.PHONY: clean
clean:
	$(RM) -r $(TARGETS)
