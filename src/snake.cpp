#include "snake.h"
Snake::Snake()
    {

    }

void Snake:: moveSnake(sf::RenderWindow &App)
{
    shrink();
    handleInput();



     	if(direction == UP)
	{
		if(_direction != down)
		{
			snake.push_front(Square(snake.front().getX(), snake.front().getY() - 25));
			_direction = up;
		}
		else
		{
			snake.push_front(Square(snake.front().getX(), snake.front().getY() + 25));
		}
	}

	else if(direction == RIGHT)
	{
		if(_direction != left)
		{
			snake.push_front(Square(snake.front().getX() + 25, snake.front().getY()));
			_direction = right;
		}
		else
		{
			snake.push_front(Square(snake.front().getX() - 25, snake.front().getY()));
		}
	}

	else if(direction == DOWN)
	{
		if(_direction != up)
		{
			snake.push_front(Square(snake.front().getX(), snake.front().getY() + 25));
			_direction = down;
		}
		else
		{
			snake.push_front(Square(snake.front().getX(), snake.front().getY() - 25));
		}

	}

	else if(direction == LEFT)
	{
		if(_direction != right)
		{
			snake.push_front(Square(snake.front().getX() - 25, snake.front().getY()));
			_direction = left;
		}
		else
		{
			snake.push_front(Square(snake.front().getX() + 25, snake.front().getY()));
		}
	}
}
void Snake::drawSnake(sf::RenderWindow& App)
{

    for(std::list<Square>::iterator it = snake.begin(); it != snake.end(); it++)
	{

		float x = it->getX();
		float y = it->getY();
        sf::RectangleShape block;
		block.setSize(sf::Vector2f(20, 20));
		block.setFillColor(sf::Color::Green);
		block.move(x, y);

		App.draw(block);
	}
}
void Snake::handleInput()
{

			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				direction=RIGHT;
			}
			else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				direction=LEFT;
			}
			else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				direction=UP;
			}
			else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				direction=DOWN;
			}

}
void Snake::shrink()
{
    snake.pop_back();
}
void Snake::reset()
{
        direction = RIGHT;
        snake.push_front(Square(50,25));
        snake.push_front(Square(25,25));

}
void Snake::bigger()
{
    snake.push_back(Square(snake.back().getX(),snake.back().getY()));

}

int Snake::getX()
{
    return snake.front().getX();
}

int Snake::getY()
{
    return snake.front().getY();
}

std::list<Square> Snake::getSnake()
{
    return snake;
}
