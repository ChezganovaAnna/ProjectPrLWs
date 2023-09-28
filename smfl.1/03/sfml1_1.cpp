#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Rectangles and circle");

    window.clear();

    sf::RectangleShape shape1;
    shape1.setSize({120, 290});
    shape1.setRotation(0);
    shape1.setPosition({240, 110});
    shape1.setFillColor(sf::Color(95, 158, 160));
    window.draw(shape1);

    sf::CircleShape shape4(40);
    shape4.setPosition({260, 300});
    shape4.setFillColor(sf::Color(0, 255, 0));
    window.draw(shape4);

    sf::CircleShape shape3(40);
    shape3.setPosition({260, 210});
    shape3.setFillColor(sf::Color(255, 255, 0));
    window.draw(shape3);

    sf::CircleShape shape2(40);
    shape2.setPosition({260, 120});
    shape2.setFillColor(sf::Color(255, 0, 0));
    window.draw(shape2);

    window.display();

    sf::sleep(sf::seconds(5));
}