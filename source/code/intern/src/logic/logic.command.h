#pragma once

#include "../data/data.commandAction.h"

namespace Logic
{
    class Command
    {
    public:
        Command() :
            type(Data::CommandAction::CommandActionEnum::Undefined)
        {};
        ~Command() = default;

    private:
        Data::CommandAction::CommandActionEnum type;

    public:
        void SetType(Data::CommandAction::CommandActionEnum _type)
        {
            type = _type;
        };

        Data::CommandAction::CommandActionEnum GetType()
        {
            return type;
        };
    };
}