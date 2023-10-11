#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cmath>

int main()
{
    sf::Vector2f circleOffset = {400, 300};

    const float angleSpeed = 1;

    float angle = 15;
    constexpr int pointCount = 200;
    sf::Clock clock;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode({800, 600}), "Rosie", sf::Style::Default, settings);

    sf::ConvexShape rose;
    rose.setPosition({400, 300});
    rose.setFillColor(sf::Color(255, 15, 192));

    rose.setPointCount(pointCount);
    for (int pointNo = 0; pointNo < pointCount; pointNo++)
    {
        float angle = float(2 * M_PI * pointNo) / float(pointCount);
        sf::Vector2f roseRadius = {200 * std::sin(6 * angle), 200 * std::sin(6 * angle)};
        sf::Vector2f point = {
            roseRadius.x * std::sin(angle),
            roseRadius.y * std::cos(angle)};
        rose.setPoint(pointNo, point);
    }

    float circleRadius = 100;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        const float deltaTime = clock.restart().asSeconds();

        angle -= deltaTime * angleSpeed;

        sf::Vector2f position = {
            circleRadius * std::sin(angle) + circleOffset.x,
            circleRadius * std::cos(angle) + circleOffset.y};
        rose.setPosition(position);

        window.clear();
        window.draw(rose);
        window.display();
    }
}