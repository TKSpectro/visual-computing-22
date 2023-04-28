#pragma once

#include <queue>

#include <SFML/Window/Event.hpp>

#include "data/data.event.h"

#include "gui.input.h"

namespace Gui
{
    class InputSystem
    {
        using InputQueue = std::queue<Input*>;

    public:
        static InputSystem& GetInstance()
        {
            static InputSystem instance;
            return instance;
        };

        InputSystem(const InputSystem&) = delete;
        InputSystem& operator = (const InputSystem&) = delete;

    private:
        InputSystem()
        {};

    public:
        Input& GetNextInput();
        void RemoveNextInput();
        bool HasInputs() const;

        // Call this method in every onRun() in every phase where you want to process inputs.
        void OnRun();

        // Callbacks
        static void DispatchEventToInput(Data::Event& event);

    private:
        InputQueue inputQueue;

    };

}