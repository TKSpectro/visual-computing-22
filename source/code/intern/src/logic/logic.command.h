#pragma once

namespace Logic
{
    struct CommandType
    {
        enum CommandAction
        {
            MoveUp,
            MoveDown,
            MoveLeft,
            MoveRight,
            NumberOfTypes,
            Undefined = -1,
        };
    };

    class Command
    {
    public:
        Command()
            : type(CommandType::CommandAction::Undefined)
        {};
        ~Command() = default;

    private:
        CommandType::CommandAction type;

    public:
        void SetType(CommandType::CommandAction _type)
        {
            type = _type;
        };

        CommandType::CommandAction GetType()
        {
            return type;
        };
    };
}