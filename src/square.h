#ifndef SQUARE_H
#define SQUARE_H
class Square
{
public:

    Square(int _x, int _y):x(_x),y(_y)
    {

    }
    int getX() const {return x;}
    int getY() const {return y;}
private:
    int x;
    int y;
};
#endif // SQUARE_H
