#include "MazeGenerator.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

rect generateMaze(std::vector<std::vector<int>>& out, rect size){
	out = std::vector<std::vector<int>>();
	std::srand(std::time(nullptr));
	for (int i = 0; i < size.x; i++) {
		out.push_back(std::vector<int>());
		for (int j = 0; j < size.x; j++) {
			if (i < 3 || j < 3 || i >= size.x - 3 || j >= size.y - 3) {
				out[i].push_back(1);
			}
			else {
				out[i].push_back(std::rand() % 2);
			}
		}
	} //Generate random noise

	for (int i = 0; i < 4; i++) {
		smoothMaze(out);
	} //Add big gaps

	for (int i = 0; i < size.x; i++) {
		for (int j = 0; j < size.x; j++) {
			if (std::rand() % 3 == 1) {
				out[i][j] = 1;
			}
		}
	} //Add sparse noise

	for (int i = size.x / 2 - 1; i < size.x / 2 + 2; i++) {
		for (int j = size.y / 2 - 1; j < size.y / 2 + 2; j++) {
			out[i][j] = 0;
		}
	} //Add safe space for player

	int location = std::rand() % 4;
	rect exitLocation = { 10,10 };
	if (location >= 2) {
		exitLocation.x = size.x - 10;
	}
	if (location % 2 == 0) {
		exitLocation.y = size.y - 10;
	} //Select exit position


	//Carve a path to exit

	return exitLocation;
}

void smoothMaze(std::vector<std::vector<int>>& out){
	for (int i = 2; i < out.size() -2; i++) {
		for (int j = 2; j < out[i].size() - 2; j++) {
			int count = 0;
			for (int x = -1; x < 2; x++) {
				for (int y = -1; y < 2; y++) {
					//std::cout << i << "," << j << " : " << x << ", " << y << std::endl;
					count += out[i + x][j + y] == 1;
				}
			}
			if (count > 7) {
				out[i][j] = 1;
			}
			if (count < 4) {
				out[i][j] = 0;
			}
		}
	}
}
