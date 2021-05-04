wavproject: main.cpp readwav.cpp wavheader.cpp metadata.cpp checker.cpp mylib.a
	g++ -std=c++11 main.cpp readwav.cpp wavheader.cpp metadata.cpp checker.cpp mylib.a -o wavproject

normalization.o: normalization.cpp normalization.h
	g++ -c -std=c++11 normalization.cpp

echo.o: echo.cpp echo.h
	g++ -c -std=c++11 echo.cpp

noisegate.o: noisegate.cpp noisegate.h
	g++ -c -std=c++11 noisegate.cpp

mylib.a: echo.o noisegate.o normalization.o
	ar suvr mylib.a echo.o noisegate.o normalization.o

clean:
	rm *.o wavproject
