//
//  main.cpp
//  Class this
//
//  Created by Владислав Легков on 24/04/2020.
//  Copyright © 2020 Владислав Легков. All rights reserved.
//

#include <iostream>

using std::cout;

class Point
{
public:
    Point (int x, int y)
    {
        this -> x = x;
        this -> y = y;
    }
    void ShowCoords ();
    
    Point &move (int, int)  //метод возвращает ссылку на объект
    {
        this -> x += x;
        this -> y += y;
        return *this;
    }
private:
    int x;
    int y;
};

void Point::ShowCoords()
{
    cout << "x: " << this -> x << " y: " << this -> y << "\n";
}

int main(int argc, const char * argv[])
{
    Point one (15,30);
    one.move(10, 15).move(30, 20);
    one.ShowCoords();

    return 0;
}
