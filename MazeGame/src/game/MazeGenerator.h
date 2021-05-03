#pragma once
#include <vector>
#include "Engine/global/Shorts.h"

rect generateMaze(std::vector<std::vector<int>>& out, rect size);
void smoothMaze(std::vector<std::vector<int>>& out);