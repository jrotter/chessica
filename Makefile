#########################################################################

all: common reset chessica test

common:
	$(MAKE) -C src/common

reset:
	$(MAKE) -C src/reset

chessica:
	$(MAKE) -C src

test:
	$(MAKE) -C test

clean:
	$(MAKE) -C src/common clean
	$(MAKE) -C src/reset clean
	$(MAKE) -C src clean
	$(MAKE) -C test clean
