TARGET:= siasl
TEST :=test

ALLPROGS= $(TARGET) $(TEST)

.PHONY:	all clean

all: $(ALLPROGS)
progs: $(PROGRAMS)

test: 
	$(MAKE) -C src/ ../test

$(TARGET): 
	$(MAKE) -C src/ ../siasl


clean:
	$(MAKE) -C src/ clean
	rm -f $(ALLPROGS)

.PHONY: clean
