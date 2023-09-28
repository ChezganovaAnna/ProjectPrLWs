#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Convex Shapes");
    window.clear();

    sf::RectangleShape home;
    home.setSize({420, 300});
    home.setRotation(0);
    home.setPosition({90, 240});
    home.setFillColor(sf::Color(160, 82, 45));
    window.draw(home);

    sf::ConvexShape trapeze;
    trapeze.setFillColor(sf::Color(128, 0, 0));
    trapeze.setPosition(300, 170);
    trapeze.setPointCount(4);
    trapeze.setPoint(0, {-180, 0});
    trapeze.setPoint(1, {+180, 0});
    trapeze.setPoint(2, {+280, 90});
    trapeze.setPoint(3, {-280, 90});
    window.draw(trapeze);

    sf::RectangleShape door;
    door.setSize({80, 200});
    door.setRotation(0);
    door.setPosition({120, 340});
    door.setFillColor(sf::Color(105, 105, 105));
    window.draw(door);

    sf::RectangleShape pipe;
    pipe.setSize({40, 60});
    pipe.setRotation(0);
    pipe.setPosition({360, 160});
    pipe.setFillColor(sf::Color(112, 128, 144));
    window.draw(pipe);

    sf::CircleShape smoke1(20);
    smoke1.setPosition({360, 120});
    smoke1.setFillColor(sf::Color(169, 169, 169));
    window.draw(smoke1);

    sf::CircleShape smoke2(20);
    smoke2.setPosition({380, 95});
    smoke2.setFillColor(sf::Color(169, 169, 169));
    window.draw(smoke2);

    sf::CircleShape smoke3(25);
    smoke3.setPosition({376, 60});
    smoke3.setFillColor(sf::Color(169, 169, 169));
    window.draw(smoke3);

    sf::CircleShape smoke4(30);
    smoke4.setPosition({360, 30});
    smoke4.setFillColor(sf::Color(169, 169, 169));
    window.draw(smoke4);

    sf::RectangleShape lid;
    lid.setSize({60, 50});
    lid.setRotation(0);
    lid.setPosition({350, 140});
    lid.setFillColor(sf::Color(112, 128, 144));
    window.draw(lid);

    window.display();
    sf::sleep(sf::seconds(5));
}