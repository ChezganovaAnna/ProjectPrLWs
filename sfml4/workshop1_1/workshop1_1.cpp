#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

constexpr unsigned WINDOW_WIDTH = 800;
constexpr unsigned WINDOW_HEIGHT = 600;

void initArrow(sf::ConvexShape &arrow)
{
    arrow.setFillColor(sf::Color::Yellow);
    arrow.setPosition(400, 300);
    arrow.setPointCount(7);
    arrow.setPoint(0, {-50, -30});
    arrow.setPoint(1, {20, -30});
    arrow.setPoint(2, {20, -80});
    arrow.setPoint(3, {100, 0});
    arrow.setPoint(4, {20, 80});
    arrow.setPoint(5, {20, 30});
    arrow.setPoint(6, {-50, 30});

    arrow.setOutlineThickness(5);
    arrow.setOutlineColor(sf::Color(0, 0, 0));
    arrow.setRotation(-83);
}

void pollEvents(sf::RenderWindow &window, sf::Vector2f &mousePosition)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            window.close();
            break;
        default:
            break;
        }
    }
}

void redrawFrame(sf::RenderWindow &window, sf::ConvexShape &arrow)
{
    window.clear(sf::Color::White);
    window.draw(arrow);
    window.display();
}

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(
        sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}),
        "Arrow follows mouse", sf::Style::Default, settings);

    sf::ConvexShape arrow;
    sf::Vector2f mousePosition;

    initArrow(arrow);
    while (window.isOpen())
    {
        pollEvents(window, mousePosition);
        redrawFrame(window, arrow);
    }
}