test: main.cpp readwav.cpp wavheader.cpp metadata.cpp echo.cpp noisegate.cpp normalization.cpp audioProcessing.cpp
	g++ -std=c++11 main.cpp readwav.cpp wavheader.cpp metadata.cpp echo.cpp noisegate.cpp normalization.cpp audioProcessing.cpp -o test
#this worked on my VM, can change when we get everything
