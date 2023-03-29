#pragma once

#include <queue>

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
        Command& CreateCommand();
        void AddCommand(Command& command);
        Command& GetNextCommand();
        void RemoveNextCommand();
        bool HasCommands() const;

    private:
        CommandQueue commandQueue;

    };

}