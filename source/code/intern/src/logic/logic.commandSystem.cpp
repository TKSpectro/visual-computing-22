#include "logic.commandSystem.h"

#include <iostream>
#include <assert.h>

#include "../data/data.event.h"

namespace Logic
{
    void CommandSystem::DispatchInputToLogic(Data::Event& event)
    {
        Command& command = *(new Command());

        command.SetType(Data::CommandAction::Enum(event.GetData()));

        CommandSystem::GetInstance().AddCommand(command);
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

