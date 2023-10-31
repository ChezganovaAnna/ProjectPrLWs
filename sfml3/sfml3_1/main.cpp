#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

float toDegrees(float radians)
{
    return float(radians * 180.0 / M_PI);
}

void onMouseMove(const sf::Event::MouseMoveEvent &event, sf::Vector2f &mousePosition)
{
    mousePosition = {float(event.x), float(event.y)};
}

void init(sf::ConvexShape &pointer)
{
    pointer.setPointCount(3);
    pointer.setPoint(0, {40, 0});
    pointer.setPoint(1, {-20, -20});
    pointer.setPoint(2, {-20, 20});
    pointer.setPosition({400, 300});
    pointer.setFillColor(sf::Color(255, 10, 180));
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
        case sf::Event::MouseMoved:
            onMouseMove(event.mouseMove, mousePosition);
            break;
        default:
            break;
        }
    }
}

void update(sf::ConvexShape &pointer, const float dt, const sf::Vector2f &mousePosition, float rotationSpeed)
{
    const sf::Vector2f delta = mousePosition - pointer.getPosition();
    float angle = toDegrees(std::atan2(delta.y, delta.x));
    float nowRotation = pointer.getRotation();
    float rotation = angle - nowRotation;
    if (rotation > 180)
    {
        rotation -= 360;
    }
    else if (rotation < -180)
    {
        rotation += 360;
    }
    float rotatePath = rotationSpeed * dt;
    if (rotation > rotatePath)
    {
        angle = nowRotation + rotatePath;
    }
    else if (rotation < -rotatePath)
    {
        angle = nowRotation - rotatePath;
    }
    else
    {
        angle = nowRotation + rotation;
    }
    pointer.setRotation(angle);
}

void redrawFrame(sf::RenderWindow &window, sf::ConvexShape &pointer)
{
    window.clear();
    window.draw(pointer);
    window.display();
}

int main()
{
    constexpr unsigned WINDOW_WIDTH = 800;
    constexpr unsigned WINDOW_HEIGHT = 600;
    float rotationSpeed = 20;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(
        sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}),
        "Треугольник поворачивается за мышкой", sf::Style::Default, settings);

    sf::Clock clock;
    sf::ConvexShape pointer;
    sf::Vector2f mousePosition;

    init(pointer);
    while (window.isOpen())
    {
        float dt = clock.restart().asSeconds();
        pollEvents(window, mousePosition);
        update(pointer, dt, mousePosition, rotationSpeed);
        redrawFrame(window, pointer);
    }
}
