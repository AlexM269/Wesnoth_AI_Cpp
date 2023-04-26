#include <SFML/Graphics.hpp>
#include <iostream>
#include <Map.hpp>
int main()
{
    sf::RenderWindow window(sf::VideoMode(640, 480), "SFML Application",sf::Style::Close);
    //window.setVerticalSyncEnabled(true); Pour activer la synchro de la fréquence de rafraichissement avec celle de l'écran
    sf::CircleShape shape;
    shape.setRadius(40.f);
    shape.setPosition(100.f, 100.f);
    shape.setFillColor(sf::Color::Cyan);
    int map[10][10] = {{1,0,0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0,0,0},
                       {0,0,0,2,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0,0,1}};
    sf::RenderWindow* ptr = &window;
    Map my_map(map,ptr);
    my_map.init();
    while (window.isOpen())
    {
        sf::Event event;
        my_map.update();
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        my_map.draw();
        //window.draw(shape);
        window.display();
    }
    //std::cout << "dzdzdzd";;
    return 0;
}