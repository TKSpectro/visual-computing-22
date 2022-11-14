#include "game.shutdownPhase.h"
#include <iostream>
#include "game.application.h"

namespace Game
{
    int ShutdownPhase::InternOnEnter()
    {
        std::cout << "SHUTDOWN::Enter" << std::endl;

        return 0;
    }

    int ShutdownPhase::InternOnRun()
    {
        std::cout << "SHUTDOWN::Run" << std::endl;

        counter++;
        if (counter > 4)
        {
            return Type::Undefined;
        }

        return Type::SHUTDOWN;
    }

    int ShutdownPhase::InternOnLeave()
    {
        std::cout << "SHUTDOWN::Leave" << std::endl;


        Application& app = Application::GetInstance();
        std::cout << "Window open: " << app.m_window.isOpen() << std::endl;
        app.m_window.close();
        std::cout << "Window open: " << app.m_window.isOpen() << std::endl;

        return 0;
    }
}
