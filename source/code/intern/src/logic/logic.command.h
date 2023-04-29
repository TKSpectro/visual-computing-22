#pragma once

#include "../data/data.commandAction.h"

namespace Logic
{
    class Command
    {
    public:
        Command() :
            type(Data::CommandAction::Enum::Undefined)
        {};
        ~Command() = default;

    private:
        Data::CommandAction::Enum type;

    public:
        void SetType(Data::CommandAction::Enum _type)
        {
            type = _type;
        };

        Data::CommandAction::Enum GetType()
        {
            return type;
        };
    };
}