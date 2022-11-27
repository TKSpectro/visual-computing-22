#include "game.shutdownPhase.h"
#include <iostream>
#include "game.application.h"

namespace Game
{
    int ShutdownPhase::InternOnEnter()
    {
        std::cout << "GAME::SHUTDOWN::Enter" << std::endl;

        return 0;
    }

    int ShutdownPhase::InternOnRun()
    {
        std::cout << "GAME::SHUTDOWN::Run" << std::endl;

        counter++;
        if (counter > 4)
        {
            return Type::Undefined;
        }

        return Type::SHUTDOWN;
    }

    int ShutdownPhase::InternOnLeave()
    {
        std::cout << "GAME::SHUTDOWN::Leave" << std::endl;


        Application::GetInstance().window.close();

        return 0;
    }
}
