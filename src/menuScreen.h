#ifndef MENUSCREEN_H
#define MENUSCREEN_H
#include "screen.h"
#include <SFML/Graphics.hpp>
class Menu : public Screen
{
public:
    Menu();
    virtual int Run(sf::RenderWindow &App);

private:
    sf::RectangleShape border;
    sf::Font font;
    sf::Text text1, text2, text3, text4;
    bool playing;
};
#endif // MENUSCREEN_H
