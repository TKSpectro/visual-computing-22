#pragma once

#include "../data/data.commandAction.h"

namespace Logic
{
    class Command
    {
    public:
        Command() :
            type(Data::CommandType::CommandAction::Undefined)
        {};
        ~Command() = default;

    private:
        Data::CommandType::CommandAction type;

    public:
        void SetType(Data::CommandType::CommandAction _type)
        {
            type = _type;
        };

        Data::CommandType::CommandAction GetType()
        {
            return type;
        };
    };
}