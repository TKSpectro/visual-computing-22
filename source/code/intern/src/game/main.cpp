#include <SFML/Graphics.hpp>

int main() {
    // Enable fancy anitaliasing
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 450), "vc22", sf::Style::Default, settings);

    // run the program as long as the window is open
    while (window.isOpen()) {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        sf::CircleShape shape(50.0f, 5);
        shape.setFillColor(sf::Color::White);
        shape.setPosition(120.0f, 10.0f);
        window.draw(shape);

        // create an array of 3 vertices that define a triangle primitive
        sf::VertexArray triangle(sf::Triangles, 3);

        // define the position of the triangle's points
        triangle[0].position = sf::Vector2f(10.0f, 10.0f);
        triangle[1].position = sf::Vector2f(100.0f, 10.0f);
        triangle[2].position = sf::Vector2f(10.0f, 100.0f);

        // define the color of the triangle's points
        triangle[0].color = sf::Color::Red;
        triangle[1].color = sf::Color::Blue;
        triangle[2].color = sf::Color::Green;
        window.draw(triangle);

        // end the current frame
        window.display();
    }

    return 0;
}