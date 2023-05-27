#include <SFML/Graphics.hpp>
#include <iostream>
#include "Map.hpp"
#include "Unit.hpp"
#include "Player.hpp"

int main()
{
    // crétion de la fenêtre de jeu
    sf::RenderWindow window(sf::VideoMode(1200, 800), "SFML Application",sf::Style::Close);
    //window.setVerticalSyncEnabled(true); Pour activer la synchro de la fréquence de rafraichissement avec celle de l'écran

    // Construction de la map
    int const N(10);
    int const M(10);
    int map2D[N][M] = {{0,1,2,3,0,0,0,0,0,0},
                     {2,0,0,0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0,0,0},
                     {1,0,0,0,0,0,0,0,0,0},
                     {0,0,0,2,2,0,0,0,0,0},
                     {0,0,0,2,2,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0,0,1}};

    // conversion de la map en un tableau 1 dimension
    int map1D[N+M];
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            map1D[i*M+j] = map2D[i][j];
        }
    }
    // chargement des textures pour les Map et les unités
    sf::Texture textureMap;
    textureMap.loadFromFile("c:/Users/nolha/Documents/GitHub/Wesnoth_AI_Cpp/idees_map/brouillon.png");
    sf::Texture textureUnit;
    textureUnit.loadFromFile("c:/Users/nolha/Documents/GitHub/Wesnoth_AI_Cpp/idees_map/perso.png");

    // Instanciation de la map
    Map my_map(&textureMap,N,M,map1D);
    // Instanciation des joueurs
    Player player1(&my_map,&textureUnit );


    //Initialisation
    my_map.init();
    player1.init();

    while (window.isOpen()) {
        //position de la souris par rapport à la fenêtre;
        sf::Vector2i localPosition = sf::Mouse::getPosition(window);

        // boucle de gestion des evennements
        sf::Event event;
        while (window.pollEvent(event)) {

            //update
            my_map.update();
            player1.update(localPosition,event);

            if (event.type == sf::Event::Closed)
                window.close();
        }


        //draw
        window.clear();
        my_map.draw(&window);
        player1.draw(&window);
        window.display();
    }
    //std::cout << "dzdzdzd";;
    return 0;
}