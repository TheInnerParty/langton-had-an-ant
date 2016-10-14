//
//  cell.hpp
//  langston-had-an-ant
//
//  Created by dorsalstream on 10/13/16.
//
//

#pragma once

enum Color {
    WHITE,
    RED
};


class Cell{
public:
    Cell();
    Color color;
    bool hasAnt;
};
