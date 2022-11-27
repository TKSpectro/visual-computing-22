#include "game.unloadPhase.h"
#include <iostream>

namespace Game
{
    int UnloadPhase::InternOnEnter()
    {
        std::cout << "GAME::UNLOAD::Enter" << std::endl;

        return 0;
    }

    int UnloadPhase::InternOnRun()
    {
        std::cout << "GAME::UNLOAD::Run" << std::endl;

        counter++;
        if (counter > 4)
        {
            return Type::SHUTDOWN;
        }

        return Type::UNLOAD_MAP;
    }

    int UnloadPhase::InternOnLeave()
    {
        std::cout << "GAME::UNLOAD::Leave" << std::endl;

        return 0;
    }
}
