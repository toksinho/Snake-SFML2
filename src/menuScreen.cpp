#include "menuScreen.h"

Menu::Menu()
{
playing=false;
}

int Menu::Run(sf::RenderWindow& App)
{


    sf::Event Event;
    bool Running = true;

    font.loadFromFile("arial.ttf");
    text1.setFont(font);
    text2.setFont(font);
    text3.setFont(font);
    text4.setFont(font);

    border.setSize(sf::Vector2f(350,100));
    border.setFillColor(sf::Color::Black);
    border.setOutlineColor(sf::Color::Green);
    border.setOutlineThickness(20);
    border.setPosition(190,200);


    text1.setString("SNAKE GAME");
    text1.setCharacterSize(50);
    text1.setPosition(200,220);


    text2.setString("Pritisni Space za pokretanje igre!");
    text2.setCharacterSize(30);
    text2.setPosition(150,360);


    text3.setString("Promjena brzine s tipkama 1, 2, 3");
    text3.setCharacterSize(26);
    text3.setPosition(170,400);


    text4.setString("P - pauza");
    text4.setCharacterSize(26);
    text4.setPosition(300,435);


      while (Running)
    {

        //Verifying events
        while (App.pollEvent(Event))
        {
            // Window closed
            if (Event.type == sf::Event::Closed)
            {
                return (-1);
            }

            //Key pressed
            if (Event.type == sf::Event::KeyPressed)
            {
                switch (Event.key.code)
                {
                case sf::Keyboard::Space:
                    playing=true;
                    return(1);
                    break;
                case sf::Keyboard::Escape:
                    return(-1);
                    break;
                default:
                    break;
                }
            }
        }
        App.clear();
        App.draw(border);
        App.draw(text1);
        App.draw(text2);
        App.draw(text3);
        App.draw(text4);
        App.display();
    }
}
