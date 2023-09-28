#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Rectangles and circle");

    window.clear();

    sf::RectangleShape shape1;
    shape1.setSize({50, 290});
    shape1.setRotation(0);
    shape1.setPosition({100, 110});
    shape1.setFillColor(sf::Color(95, 158, 160));
    window.draw(shape1);

    sf::RectangleShape shape2;
    shape2.setSize({150, 40});
    shape2.setRotation(0);
    shape2.setPosition({100, 110});
    shape2.setFillColor(sf::Color(95, 158, 160));
    window.draw(shape2);

    sf::RectangleShape shape3;
    shape3.setSize({150, 40});
    shape3.setRotation(0);
    shape3.setPosition({100, 400});
    shape3.setFillColor(sf::Color(95, 158, 160));
    window.draw(shape3);

    //c
    //а рисуем с 390
    //большая
    sf::RectangleShape shape4;
    shape4.setSize({50, 330});
    shape4.setRotation(0);
    shape4.setPosition({310, 110});
    shape4.setFillColor(sf::Color(95, 158, 160));
    window.draw(shape4);
    //маленькая
    sf::RectangleShape shape5;
    shape5.setSize({150, 50});
    shape5.setRotation(0);
    shape5.setPosition({310, 110});
    shape5.setFillColor(sf::Color(95, 158, 160));
    window.draw(shape5);
    //маленькая
    sf::RectangleShape shape6;
    shape6.setSize({150, 40});
    shape6.setRotation(0);
    shape6.setPosition({310, 290});
    shape6.setFillColor(sf::Color(95, 158, 160));
    window.draw(shape6);

    sf::RectangleShape shape7;
    shape7.setSize({50, 330});
    shape7.setRotation(0);
    shape7.setPosition({420, 110});
    shape7.setFillColor(sf::Color(95, 158, 160));
    window.draw(shape7);

    //п

    sf::RectangleShape shape8;
    shape8.setSize({50, 330});
    shape8.setRotation(0);
    shape8.setPosition({540, 110});
    shape8.setFillColor(sf::Color(95, 158, 160));
    window.draw(shape8);

    sf::RectangleShape shape9;
    shape9.setSize({150, 40});
    shape9.setRotation(0);
    shape9.setPosition({540, 110});
    shape9.setFillColor(sf::Color(95, 158, 160));
    window.draw(shape9);

    sf::RectangleShape shape10;
    shape10.setSize({150, 40});
    shape10.setRotation(0);
    shape10.setPosition({540, 250});
    shape10.setFillColor(sf::Color(95, 158, 160));
    window.draw(shape10);

    sf::RectangleShape shape11;
    shape11.setSize({40, 180});
    shape11.setRotation(0);
    shape11.setPosition({690, 110});
    shape11.setFillColor(sf::Color(255, 0, 0));
    window.draw(shape11);

    window.display();

    sf::sleep(sf::seconds(5));
}