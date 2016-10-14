//
//  Grid.cpp
//  langston-had-an-ant
//
//  Created by Leo Dastur on 10/13/16.
//
//

#include "Grid.hpp"

Grid::Grid(int width, int height) {
	cells.assign(width*height, Cell());
	Ant ant;
	std::get<0>(ant) = UP;
	int y = height / 2;
	int x = width / 2;
	std::get<1>(ant) = cells.begin() + y * width + x;
	
}

Grid::Ant Grid::goUp(Ant ant) {
	int index = std::get<1>(ant)- cells.begin();
	
	if (index < width) {
		throw outofBounds;
	} else {
		std::get<1>(ant) -= width;
	}
	return ant;
	
}

Grid::Ant Grid::goDown(Ant ant) {
	int index = std::get<1>(ant) - cells.begin();
	if (index > width * (height - 1)) {
		throw outofBounds;
	} else {
		std::get<1>(ant) += width;
		
	}
	return ant;
}

Grid::Ant Grid::goLeft(Ant ant) {
	int index = std::get<1>(ant)- cells.begin();
	if ((index % width) == 0) {
		throw outofBounds;
	} else {
		std::get<1>(ant)--;
	}
	return ant;
	
}

Grid::Ant Grid::goRight(Ant ant) {
	int index = std::get<1>(ant)- cells.begin();
	if (((index + 1) % width) == 0) {
		throw outofBounds;
	} else {
		std::get<1>(ant)++;
	}
	return ant;
	
}
