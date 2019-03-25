#include "MazeGenerator.h"
#include <cstdlib>
#include <ctime>

void generateMaze(std::vector<std::vector<int>>& out, rect size){
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
	}
}
