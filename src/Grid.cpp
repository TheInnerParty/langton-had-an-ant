//
//  Grid.cpp
//  langston-had-an-ant
//
//  Created by Leo Dastur on 10/13/16.
//
//

#include "Grid.hpp"

Grid::Grid(int width, int height) {
	this->width = width;
	this->height = height;
	cells.assign(width*height, Cell());
	Ant ant;
	std::get<0>(ant) = UP;
	int y = height / 2;
	int x = width / 2;
	std::get<1>(ant) = cells.begin() + y * width + x;
	std::get<1>(ant)->hasAnt = true;
	std::get<1>(ant)->isColored = true;
	ants.push_back(ant);
	
}

void Grid::goUp(Ant& ant) {
	int index = std::get<1>(ant)- cells.begin();
	if (index < width) {
		throw outofBounds;
	} else {
        std::get<1>(ant)->hasAnt = false;
		std::get<1>(ant) -= width;
        std::get<1>(ant)->hasAnt = true;
	}
	
}

void Grid::goDown(Ant& ant) {
	int index = std::get<1>(ant) - cells.begin();
	if (index > width * (height - 1)) {
		throw outofBounds;
	} else {
        std::get<1>(ant)->hasAnt = false;
		std::get<1>(ant) += width;
        std::get<1>(ant)->hasAnt = true;
		
	}
}

void Grid::goLeft(Ant& ant) {
	int index = std::get<1>(ant)- cells.begin();
	if ((index % width) == 0) {
		throw outofBounds;
	} else {
        std::get<1>(ant)->hasAnt = false;
		std::get<1>(ant)--;
        std::get<1>(ant)->hasAnt = true;
	}
	
}

void Grid::goRight(Ant& ant) {
	int index = std::get<1>(ant)- cells.begin();
	if (((index + 1) % width) == 0) {
		throw outofBounds;
	} else {
        std::get<1>(ant)->hasAnt = false;
		std::get<1>(ant)++;
        std::get<1>(ant)->hasAnt = true;
	}
	
}
void Grid::update(){
    for(auto&& a : ants){
		if (std::get<1>(a)->hasAnt == true) {
			if (std::get<1>(a)->isColored){
				//left
				std::get<0>(a) = turnLeft(std::get<0>(a));
			} else {
				//right
				std::get<0>(a) = turnRight(std::get<0>(a));
			}
			//flip color of square
			std::get<1>(a)->isColored =! std::get<1>(a)->isColored;
			//move in that direction
			try {
				switch(std::get<0>(a)){
					case LEFT:
						goLeft(a);
						break;
					case UP:
						goUp(a);
						break;
					case RIGHT:
						goRight(a);
						break;
					case DOWN:
						goDown(a);
						break;
				}
			} catch (OutofBounds){
				std::get<1>(a)->hasAnt = false;
			}
		}
    }
}

Grid::Direction Grid::turnRight(Direction d){
	switch(d) {
		case LEFT:
			return UP;
			break;
		case UP:
			return RIGHT;
			break;
		case RIGHT:
			return DOWN;
			break;
		case DOWN:
			return LEFT;
			break;
	}
}
Grid::Direction Grid::turnLeft(Direction d){
	return turnRight(turnRight(turnRight(d)));
}
bool Grid::getBoxColored(int x, int y) {
	auto cell = cells.begin() + y * width + x;
	return cell->isColored;
}
