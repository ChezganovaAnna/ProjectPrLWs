#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

constexpr unsigned WINDOW_WIDTH = 800;
constexpr unsigned WINDOW_HEIGHT = 600;

struct Cat
{
    sf::Texture catTexture;
    sf::Sprite catSprite;
    sf::Vector2f position;
};

struct Pointer
{
    sf::Texture pointerTexture;
    sf::Sprite pointerSprite;
    sf::Vector2f position;
};

float toDegrees(float radians)
{
    return float(double(radians) * 180.0 / M_PI);
}

sf::Vector2f toEuclidean(float radius, float angle)
{
    return sf::Vector2f(radius * cos(angle), radius * sin(angle));
}

void initCat(Cat &cat)
{
    if (!cat.catTexture.loadFromFile("C:/Users/tchez/Downloads/sfml4/workshop1_4/image/cat.png"))
    {
        std::cout << "Could not load enemy texture ";
        return;
    }
    cat.catSprite.setTexture(cat.catTexture);
    cat.catSprite.scale(sf::Vector2f(1, 1));
    cat.catSprite.setPosition(sf::Vector2f(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2));
    cat.catSprite.setOrigin(cat.catSprite.getLocalBounds().width / 2.f, cat.catSprite.getLocalBounds().height / 2.f);
}

void initPointer(Pointer &pointer)
{
    if (!pointer.pointerTexture.loadFromFile("C:/Users/tchez/Downloads/sfml4/workshop1_4/image/pointer.png"))
    {
        std::cout << "Could not load enemy texture ";
        return;
    }

    pointer.pointerSprite.setTexture(pointer.pointerTexture);
    pointer.pointerSprite.scale(sf::Vector2f(1, 1));
    pointer.pointerSprite.setPosition(sf::Vector2f(50, 50));
    pointer.pointerSprite.setOrigin(pointer.pointerSprite.getLocalBounds().width / 2.f, pointer.pointerSprite.getLocalBounds().height / 2.f);
}

void initSprites(Cat &cat, Pointer &pointer)
{
    initCat(cat);
    initPointer(pointer);
}

void redrawFrame(sf::RenderWindow &window, Cat &cat, Pointer &pointer)
{
    window.clear();
    window.draw(cat.catSprite);
    window.draw(pointer.pointerSprite);
    window.display();
}

void onMouseMove(const sf::Event::MouseMoveEvent &event, sf::Vector2f &mousePosition)
{
    mousePosition = {float(event.x), float(event.y)};
}

void pollEvents(sf::RenderWindow &window, sf::Vector2f &mousePosition, Pointer &pointer)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::MouseButtonPressed:
            pointer.pointerSprite.setPosition(sf::Vector2f(event.mouseButton.x, event.mouseButton.y));
            break;
        default:
            break;
        }
    }
}

void update(Cat &cat, Pointer &pointer, const float dt, const sf::Vector2f &mousePosition)
{
    const float speed = 250.f;
    sf::Vector2f direction = pointer.pointerSprite.getPosition() - cat.catSprite.getPosition();
    float angle = toDegrees(std::atan2(direction.y, direction.x));
    cat.catSprite.setRotation(angle);
    direction /= std::sqrt(direction.x * direction.x + direction.y * direction.y);
    sf::Vector2f movement = direction * speed * dt;
    cat.catSprite.setPosition(cat.catSprite.getPosition() + movement);
    if (direction.x < 0)
    {
        cat.catSprite.setScale(1, -1);
    }
    else
    {
        cat.catSprite.setScale(1, 1);
    }
}

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(
        sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}),
        "Котик следует за лазером", sf::Style::Default, settings);

    Cat cat;
    Pointer pointer;
    initSprites(cat, pointer);

    sf::Vector2f mousePosition;
    sf::Clock clock;

    while (window.isOpen())
    {
        float dt = clock.restart().asSeconds();
        pollEvents(window, mousePosition, pointer);
        update(cat, pointer, dt, mousePosition);
        redrawFrame(window, cat, pointer);
    }
    return 0;
}