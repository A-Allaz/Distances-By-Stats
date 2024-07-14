REAL = ./core/vectors.cpp ./core/utils.cpp ./front/main.cpp
INT = ./core/vectors.h ./core/utils.h
OBJ = vectors.o utils.o main.o 

exe: $(OBJ)
	g++ -o main $(OBJ)

clear:
	rm $(OBJ) main

vectors.o: ./core/vectors.cpp $(INT)
	g++ -c ./core/vectors.cpp

utils.o: ./core/utils.cpp $(INT)
	g++ -c ./core/utils.cpp

main.o: ./front/main.cpp $(INT)
	g++ -c ./front/main.cpp