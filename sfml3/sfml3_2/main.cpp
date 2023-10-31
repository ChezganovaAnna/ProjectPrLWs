
#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

struct Eye
{
    sf::CircleShape big;
    sf::CircleShape small;
    sf::Vector2f position;
};

float toDegrees(float radians)
{
    return float(double(radians) * 180.0 / M_PI);
}

sf::Vector2f toEuclidean(float radius, float angle)
{
    return sf::Vector2f(float(radius * cos(angle)), float(radius * sin(angle)));
}

void updateEyeElements(Eye &eye, const sf::Vector2f &mousePosition)
{
    const sf::Vector2f delta = mousePosition - eye.position;
    float angle = atan2(delta.y, delta.x);
    float distance = std::min(std::hypot(delta.x, delta.y), eye.big.getRadius() - eye.small.getRadius());
    sf::Vector2f smallOffset = {distance * cos(angle), distance * sin(angle)};
    eye.small.setPosition(eye.position + smallOffset);
}

// Initializes the eye shape
void initEye(Eye &eye)
{
    eye.position = {400, 300};

    eye.big.setRadius(80);
    eye.big.setOrigin({80, 80});
    eye.big.setPosition(eye.position);
    eye.big.setFillColor(sf::Color::White);
    eye.big.setOutlineThickness(10);
    eye.big.setOutlineColor(sf::Color::Black);

    eye.small.setRadius(40);
    eye.small.setOrigin({40, 40});
    eye.small.setPosition(eye.position);
    eye.small.setFillColor(sf::Color::Black);

    updateEyeElements(eye, eye.position);
}

void onMouseMove(const sf::Event::MouseMoveEvent &event, sf::Vector2f &mousePosition)
{
    mousePosition = {float(event.x), float(event.y)};
}

// Polls and processes available events in a loop.
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

// Updates the eye shape to follow the mouse cursor
void update(const sf::Vector2f &mousePosition, Eye &eye)
{
    updateEyeElements(eye, mousePosition);
}

// Draws and displays one frame
void redrawFrame(sf::RenderWindow &window, Eye &eye)
{
    window.clear();
    window.draw(eye.big);
    window.draw(eye.small);
    window.display();
}

// The program draws an eye consisting of two ellipses - a large and a small one - where the small ellipse moves along with the mouse cursor within the bounds of the large ellipse.
int main()
{
    constexpr unsigned WINDOW_WIDTH = 800;
    constexpr unsigned WINDOW_HEIGHT = 600;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(
        sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}),
        "Eye follows mouse", sf::Style::Default, settings);

    Eye eye;
    sf::Vector2f mousePosition;

    initEye(eye);
    while (window.isOpen())
    {
        pollEvents(window, mousePosition);
        update(mousePosition, eye);
        redrawFrame(window, eye);
    }
}
