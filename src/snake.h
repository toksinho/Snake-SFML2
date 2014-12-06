#ifndef SNAKE_H
#define SNAKE_H

#include <SFML/Graphics.hpp>
#include <list>
#include "square.h"

class Snake
{
public:
    Snake();
    void moveSnake(sf::RenderWindow &App);
    std::list<Square> snake;
    int getX();
    int getY();
    void reset();
    void bigger();
    std::list<Square> getSnake();
    void drawSnake(sf::RenderWindow &App);


private:
    enum Direction{UP,DOWN,LEFT,RIGHT};
    Direction direction;
    enum _Direction{up,down,left,right};
    _Direction _direction;
    void handleInput();

    void shrink();
};
#endif // SNAKE_H
