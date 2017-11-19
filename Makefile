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


