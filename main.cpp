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
    int map2D[N][M] = {{4,4,4,4,4,4,4,4,4,4},
                       {4,4,4,4,4,4,1,4,4,4},
                       {1,4,4,4,4,4,4,4,1,4},
                       {4,4,4,4,4,4,4,4,4,4},
                       {4,4,4,0,4,4,4,4,4,4},
                       {4,4,4,4,4,4,1,4,4,4},
                       {4,4,4,4,4,4,4,4,4,4},
                       {4,4,4,4,4,4,4,4,4,4},
                       {4,4,4,4,4,4,4,4,4,4},
                       {4,4,4,4,4,4,4,4,4,4},};

    // conversion de la map en un tableau 1 dimension
    int map1D[N*M];
    int mapPositions[N*M];
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            map1D[i*M+j] = map2D[i][j];
            mapPositions[i*M+j] =0;
        }
    }
    // Chargement de la police
    sf::Font font;
    font.loadFromFile("c:/Users/nolha/Documents/GitHub/Wesnoth_AI_Cpp/Font/arial.ttf");

    // chargement des textures pour les Map et les unités
    sf::Texture textureMap;
    textureMap.loadFromFile("c:/Users/nolha/Documents/GitHub/Wesnoth_AI_Cpp/idees_map/brouillon.png");
    sf::Texture textureUnit1;
    textureUnit1.loadFromFile("c:/Users/nolha/Documents/GitHub/Wesnoth_AI_Cpp/idees_map/perso.png");
    sf::Texture textureUnit2;
    textureUnit2.loadFromFile("c:/Users/nolha/Documents/GitHub/Wesnoth_AI_Cpp/idees_map/perso2.png");

    // Instanciation de la map
    Map my_map(&textureMap,N,M,map1D,mapPositions);
    // Instanciation des joueurs
    Player player0(&my_map,&textureUnit1,&font, 0);
    Player player1(&my_map,&textureUnit2,&font, 1);

    player0.setAdversary(&player1);
    player1.setAdversary(&player0);

    // id du player dont c'est le tour
    int actualPlayer = 0;

    //Initialisation
    my_map.init();
    player0.init();
    player1.init();


    while (window.isOpen()) {
        //position de la souris par rapport à la fenêtre;
        sf::Vector2i localPosition = sf::Mouse::getPosition(window);

        // boucle de gestion des evennements
        // alors ici faut faire gaffe parce que les updates ne sont faites que si un evennement apparait
        // (deplacement souris, appui clavier) pour le moment osef mais faudrait ptet la déplacer dans les updates des classes
        sf::Event event;
        while (window.pollEvent(event)) {

            //update
            player0.update(localPosition,event);
            player1.update(localPosition,event);
            my_map.update();

            if (event.type == sf::Event::Closed)
                window.close();
        }
        //draw
        window.clear();
        my_map.draw(&window);
        player0.draw(&window);
        player1.draw(&window);
        window.display();
        if(actualPlayer==0){
            if(!player0.is_turn()){
                player1.setTurn();
                actualPlayer=1;
            }
        }
        if(actualPlayer==1){
            if(!player1.is_turn()){
                player0.setTurn();
                actualPlayer=0;
            }
        }

    }
    //std::cout << "dzdzdzd";;
    return 0;
}