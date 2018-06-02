CC      := gcc
OBJS    := main.o ardrone2.o
EXEC    := drone

.SUFFIXES: .c.o
.c.o:
	$(CC) -c $<

$(EXEC): $(OBJS)
	$(CC) -o $@ $^

.PHONY: run
run: $(EXEC)
	./$^

.PHONY: clean
clean:
	rm -rf $(OBJS) $(EXEC)
