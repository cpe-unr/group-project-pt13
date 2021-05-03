test: main.cpp readwav.cpp wavheader.cpp metadata.cpp 
	g++ -std=c++11 main.cpp readwav.cpp wavheader.cpp metadata.cpp -o test
#this worked on my VM, can change when we get everything
