.PHONY: all clean clean_lib clean_src make_src make_lib

all: make_lib make_src

make_src:
	$(MAKE) -C ./src

make_lib:
	$(MAKE) -C ./lib

clean: clean_lib clean_src

clean_lib:
	$(MAKE) -C ./lib clean

clean_src:
	$(MAKE) -C ./src clean
