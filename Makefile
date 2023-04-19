all:
	gcc ./src/main.c ./src/mat.c ./src/mat.h -lm -o  ./build/executavel

clean:
	rm -rf ./build/executavel

run:
	./build/executavel