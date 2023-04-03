all:
	gcc ./filesc/main.c ./filesc/mat.c ./filesh/mat.h -o executavel

clean:
	rm -rf executavel

run:
	./executavel