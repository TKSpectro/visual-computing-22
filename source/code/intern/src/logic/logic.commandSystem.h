#pragma once

#include <queue>

#include "../data/data.event.h"
#include "logic.command.h"

namespace Logic
{
    class CommandSystem
    {
        using CommandQueue = std::queue<Command*>;

    public:
        static CommandSystem& GetInstance()
        {
            static CommandSystem instance;
            return instance;
        };

        CommandSystem(const CommandSystem&) = delete;
        CommandSystem& operator = (const CommandSystem&) = delete;

    private:
        CommandSystem()
        {};

    public:
        void AddCommand(Command& command);
        Command& GetNextCommand();
        void RemoveNextCommand();
        bool HasCommands() const;

    public:
        // Callbacks
        static void DispatchInputToLogic(Data::Event& event);

    private:
        CommandQueue commandQueue;

    };

}