#include "gui.inputSystem.h"

#include <iostream>
#include <assert.h>

#include "data/data.eventSystem.h"
#include "data/data.commandAction.h"

namespace Gui
{
    void InputSystem::DispatchEventToInput(Data::Event& event)
    {
        Input& input = *(new Input());

        input.key.code = sf::Keyboard::Key(event.GetData());

        InputSystem::GetInstance().inputQueue.push(&input);
    }

    Input& InputSystem::GetNextInput()
    {
        assert(!inputQueue.empty());

        return *inputQueue.front();
    }

    void InputSystem::RemoveNextInput()
    {
        assert(!inputQueue.empty());

        Input* input = inputQueue.front();
        delete input;
        inputQueue.pop();
    }

    bool InputSystem::HasInputs() const
    {
        return !inputQueue.empty();
    }

    void InputSystem::OnRun()
    {
        Input currentInput;

        while (HasInputs())
        {
            currentInput = GetNextInput();

            switch (currentInput.key.code)
            {
                case sf::Keyboard::Key::Escape:
                    Data::EventSystem::GetInstance().FireEvent(Data::EventType::PRESSED_ESCAPE);
                    break;

                case sf::Keyboard::Key::Enter:
                    Data::EventSystem::GetInstance().FireEvent(Data::EventType::PRESSED_ENTER);
                    break;

                case sf::Keyboard::Key::Num0:
                case sf::Keyboard::Key::Num1:
                case sf::Keyboard::Key::Numpad0:
                case sf::Keyboard::Key::Numpad1:
                    Data::EventSystem::GetInstance().FireEvent(Data::EventType::PRESSED_NUMBER, 1);
                    break;

                case sf::Keyboard::Key::Num2:
                case sf::Keyboard::Key::Numpad2:
                    Data::EventSystem::GetInstance().FireEvent(Data::EventType::PRESSED_NUMBER, 2);
                    break;

                case sf::Keyboard::Key::Up:
                case sf::Keyboard::Key::W:
                    Data::EventSystem::GetInstance().FireEvent(Data::EventType::DISPATCH_INPUT_TO_COMMAND, Data::CommandAction::MoveUp);
                    break;

                case sf::Keyboard::Key::Down:
                case sf::Keyboard::Key::S:
                    Data::EventSystem::GetInstance().FireEvent(Data::EventType::DISPATCH_INPUT_TO_COMMAND, Data::CommandAction::MoveDown);
                    break;

                case sf::Keyboard::Key::Left:
                case sf::Keyboard::Key::A:
                    Data::EventSystem::GetInstance().FireEvent(Data::EventType::DISPATCH_INPUT_TO_COMMAND, Data::CommandAction::MoveLeft);
                    break;

                case sf::Keyboard::Key::Right:
                case sf::Keyboard::Key::D:
                    Data::EventSystem::GetInstance().FireEvent(Data::EventType::DISPATCH_INPUT_TO_COMMAND, Data::CommandAction::MoveRight);
                    break;

                default:
                    std::cout << "GUI::INPUTSYSTEM::OnRun         Unbound key pressed" << std::endl;
                    break;
            }

            RemoveNextInput();
        }
    }
}

