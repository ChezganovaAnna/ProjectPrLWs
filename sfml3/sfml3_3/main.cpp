#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

using namespace std;

constexpr unsigned WINDOW_WIDTH = 800;
constexpr unsigned WINDOW_HEIGHT = 600;

struct Eye
{
    sf::CircleShape orbitale;
    sf::CircleShape pupil;
};

void initEyes(Eye &leftEye, Eye &rightEye)
{
    leftEye.orbitale.setFillColor(sf::Color(sf::Color::White));
    rightEye.orbitale.setFillColor(sf::Color(sf::Color::White));

    leftEye.pupil.setFillColor(sf::Color(sf::Color::Black));
    rightEye.pupil.setFillColor(sf::Color(sf::Color::Black));

    leftEye.orbitale.setPosition({WINDOW_WIDTH / 2 - 100, WINDOW_HEIGHT / 2});
    leftEye.orbitale.setRadius(70);
    leftEye.orbitale.setScale(1, 2);
    leftEye.orbitale.setOrigin(35, 70);

    leftEye.pupil.setPosition({WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2});
    leftEye.pupil.setRadius(25);
    leftEye.pupil.setOrigin(-10, 10);

    rightEye.orbitale.setPosition({WINDOW_WIDTH / 2 + 100, WINDOW_HEIGHT / 2});
    rightEye.orbitale.setRadius(70);
    rightEye.orbitale.setScale(1, 2);
    rightEye.orbitale.setOrigin(35, 70);

    rightEye.pupil.setPosition({WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2});
    rightEye.pupil.setRadius(25);
    rightEye.pupil.setOrigin(-10, 10);
}

float onMouseMove(const sf::Event::MouseMoveEvent &event, sf::Vector2f &mousePosition)
{
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

void update(const sf::Vector2f &mousePosition, Eye &leftEye, Eye &rightEye)
{
    const sf::Vector2f leftEyePos = leftEye.orbitale.getPosition();
    sf::Vector2f leftDelta = mousePosition - leftEyePos;
    float leftRadius = leftEye.orbitale.getRadius() - leftEye.pupil.getRadius();
    float leftAngle = atan2(leftDelta.y, leftDelta.x);
    float leftDistance = min(hypot(leftDelta.x, leftDelta.y), leftRadius);
    sf::Vector2f leftPupilOffset = {leftDistance * cos(leftAngle), leftDistance * sin(leftAngle)};
    leftEye.pupil.setPosition(leftEyePos + leftPupilOffset);

    const sf::Vector2f rightEyePos = rightEye.orbitale.getPosition();
    sf::Vector2f rightDelta = mousePosition - rightEyePos;
    float rightRadius = rightEye.orbitale.getRadius() - rightEye.pupil.getRadius();
    float rightAngle = atan2(rightDelta.y, rightDelta.x);
    float rightDistance = min(hypot(rightDelta.x, rightDelta.y), rightRadius);
    sf::Vector2f rightPupilOffset = {rightDistance * cos(rightAngle), rightDistance * sin(rightAngle)};
    rightEye.pupil.setPosition(rightEyePos + rightPupilOffset);
}

void redrawFrame(sf::RenderWindow &window, Eye &leftEye, Eye &rightEye)
{
    window.clear();
    window.draw(leftEye.orbitale);
    window.draw(leftEye.pupil);
    window.draw(rightEye.orbitale);
    window.draw(rightEye.pupil);
    window.display();
}

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(
        sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}),
        "Eyes follows mouse", sf::Style::Default, settings);

    Eye leftEye;
    Eye rightEye;
    sf::Vector2f mousePosition;

    initEyes(leftEye, rightEye);
    while (window.isOpen())
    {
        pollEvents(window, mousePosition);
        update(mousePosition, leftEye, rightEye);
        redrawFrame(window, leftEye, rightEye);
    }
    return 0;
}