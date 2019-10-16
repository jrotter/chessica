#########################################################################

all: common timer reset chessica test

common:
	$(MAKE) -C src/common

timer:
	$(MAKE) -C src/timer

reset:
	$(MAKE) -C src/reset

chessica:
	$(MAKE) -C src

test:
	$(MAKE) -C test

clean:
	$(MAKE) -C src/common clean
	$(MAKE) -C src/timer clean
	$(MAKE) -C src/reset clean
	$(MAKE) -C src clean
	$(MAKE) -C test clean

doc:
	doxygen doxygen.cfg
