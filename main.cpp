#include <SFML/Graphics.hpp>
#include <iostream>
#include <Map.hpp>
#include "Unit.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1200, 800), "SFML Application",sf::Style::Close);
    //window.setVerticalSyncEnabled(true); Pour activer la synchro de la fréquence de rafraichissement avec celle de l'écran
    int const N(10);
    int const M(10);
    int map[N][M] = {{3,1,2,3,0,0,0,0,0,0},
                     {2,0,0,0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0,0,0},
                     {1,0,0,0,0,0,0,0,0,0},
                     {0,0,0,2,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0,0,1}};

    int tab[N+M];
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            tab[i*M+j] = map[i][j];
        }
    }

    sf::Texture textureMap;
    textureMap.loadFromFile("c:/Users/nolha/Documents/GitHub/Wesnoth_AI_Cpp/idees_map/brouillon.png");
    sf::Texture textureUnit;
    textureUnit.loadFromFile("c:/Users/nolha/Documents/GitHub/Wesnoth_AI_Cpp/idees_map/perso.png");


    sf::RenderWindow* win = &window;
    sf::Texture* tmap = &textureMap;
    sf::Texture* tunit = &textureUnit;
    Map my_map(win,tmap,N,M,tab);
    Unit my_unit(win,tunit,5,8);

    my_map.init();
    my_unit.init();



    while (window.isOpen())
    {
        sf::Event event;
        sf::Vector2i localPosition = sf::Mouse::getPosition(window);
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            std::vector<int> res = hitbox(localPosition.x,localPosition.y,N,M);
            my_unit.move(res[0],res[1]);
        }
        my_map.update();
        my_unit.update();
        window.clear();
        //window.draw(sprite);
        my_map.draw();
        my_unit.draw();
        window.display();
    }
    //std::cout << "dzdzdzd";;
    return 0;
}