#include "logic.commandSystem.h"

#include <iostream>
#include <assert.h>

namespace Logic
{
    Command& Logic::CommandSystem::CreateCommand()
    {
        return *(new Command());
    }

    void CommandSystem::AddCommand(Command& command)
    {
        commandQueue.push(&command);
    }

    Command& CommandSystem::GetNextCommand()
    {
        assert(!commandQueue.empty());

        return *commandQueue.front();
    }

    void CommandSystem::RemoveNextCommand()
    {
        assert(!commandQueue.empty());

        Command* command = commandQueue.front();
        delete command;
        commandQueue.pop();
    }

    bool CommandSystem::HasCommands() const
    {
        return !commandQueue.empty();
    }
}

