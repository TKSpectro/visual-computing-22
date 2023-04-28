#pragma once

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>

namespace Gui
{
    class Input
    {
    public:
        struct KeyInput
        {
            sf::Keyboard::Key code;
        };

        struct MouseButtonInput
        {
            sf::Mouse::Button button;
            int x;
            int y;
        };

        enum InputType
        {
            KeyPressed,
            KeyReleased,
            MouseButtonPressed,
            MouseButtonReleased,
            NumberOfTypes,
        };

        InputType type;

        union
        {
            KeyInput key;
            MouseButtonInput mouseButton;
        };
    };
}
