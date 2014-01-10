COMPILER=gcc
OPTIONS=-Wall -O3
all: randomhex randomtext randomdec add min max mean

randomhex: randomhex.c
	 $(COMPILER) $(OPTIONS) randomhex.c -o randomhex

randomdec: randomdec.c
	 $(COMPILER) $(OPTIONS) randomdec.c -o randomdec

randomtext: randomtext.c
	 $(COMPILER) $(OPTIONS) randomtext.c -o randomtext

add: add.c
	 $(COMPILER) $(OPTIONS) add.c -o add

min: min.c
	 $(COMPILER) $(OPTIONS) min.c -o min

max: max.c
	 $(COMPILER) $(OPTIONS) max.c -o max

mean: mean.c
	 $(COMPILER) $(OPTIONS) mean.c -o mean

clean:
	- rm randomhex randomtext randomdec add min max mean
