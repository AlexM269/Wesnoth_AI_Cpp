#include <SFML/Graphics.hpp>
#include <iostream>
#include <Map.hpp>
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

    sf::RenderWindow* ptr = &window;
    Map my_map(ptr,N,M,tab);
    my_map.init();

    sf::Texture texture;
    texture.loadFromFile("c:/Users/nolha/Documents/GitHub/Wesnoth_AI_Cpp/idees_map/map.png");
    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(96,0,32,32));
    sprite.setPosition(100,100);

    while (window.isOpen())
    {
        sf::Event event;
        //my_map.update();
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        //window.draw(sprite);
        my_map.draw();
        window.display();
    }
    //std::cout << "dzdzdzd";;
    return 0;
}