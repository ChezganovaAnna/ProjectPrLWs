/*workshop1_3*/

#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(640, 480), "Lesson 3. kychka-pc.ru"); //увеличили для удобства размер окна

    sf::Texture catTexture;
    if (!catTexture.loadFromFile("C:/Users/tchez/Downloads/sfml4/workshop1_3/image/cat.png"))
    {
        std::cout << "Could not load enemy texture ";
        return 0;
    }

    sf::Sprite catSprite;
    catSprite.setTexture(catTexture);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(catSprite);
        window.display();
    }

    return 0;
}