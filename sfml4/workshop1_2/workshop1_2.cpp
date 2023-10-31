#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

constexpr unsigned WINDOW_WIDTH = 800;
constexpr unsigned WINDOW_HEIGHT = 600;

struct Arrow
{
    sf::ConvexShape arrow;
    sf::Vector2f position;
    float rotation = 0;
    float rotationSpeed = 90;
};

float toDegrees(float radians)
{
    return float(double(radians) * 180.0 / M_PI);
}

sf::Vector2f toEuclidean(float radius, float angle)
{
    return sf::Vector2f(radius * cos(angle), radius * sin(angle));
}

void initArrow(Arrow &arrow)
{
    arrow.arrow.setFillColor(sf::Color::Yellow);
    arrow.arrow.setPosition({400, 300});
    arrow.arrow.setPointCount(7);
    arrow.arrow.setPoint(0, {-50, -30});
    arrow.arrow.setPoint(1, {20, -30});
    arrow.arrow.setPoint(2, {20, -80});
    arrow.arrow.setPoint(3, {100, 0});
    arrow.arrow.setPoint(4, {20, 80});
    arrow.arrow.setPoint(5, {20, 30});
    arrow.arrow.setPoint(6, {-50, 30});

    arrow.arrow.setOutlineThickness(5);
    arrow.arrow.setOutlineColor(sf::Color(0, 0, 0));
}

void onMouseMove(const sf::Event::MouseMoveEvent &event, sf::Vector2f &mousePosition)
{
    std::cout << "mouse x=" << event.x << " , y=" << event.y << std::endl;
    mousePosition = {float(event.x), float(event.y)};
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
    const sf::Vector2f velocity = 50.0f * delta / std::sqrt(delta.x * delta.x + delta.y * delta.y);
    const sf::Vector2f newPosition = pointer.getPosition() + velocity * dt;

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
    pointer.setPosition(newPosition);
}

void redrawFrame(sf::RenderWindow &window, Arrow &arrow)
{
    window.clear(sf::Color::White);
    window.draw(arrow.arrow);
    window.display();
}

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(
        sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}),
        "Arrow follows mouse", sf::Style::Default, settings);

    sf::Vector2f mousePosition;
    sf::Clock clock;
    Arrow arrow;

    initArrow(arrow);
    while (window.isOpen())
    {
        float dt = clock.restart().asSeconds();
        pollEvents(window, mousePosition);
        update(arrow.arrow, dt, mousePosition, arrow.rotationSpeed);
        redrawFrame(window, arrow);
    }
}
