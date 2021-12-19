.PHONY: all
all: cassiope

.PHONY: tarball
tarball: cassiope.tar.gz

cassiope.tar.gz:
	git archive -o $(@) --prefix=cassiope/ HEAD .

cassiope: cassiope.o

%.o : %.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@
