#include "game.mainMenuPhase.h"
#include <iostream>

namespace Game
{
    int MainMenuPhase::InternOnEnter()
    {
        std::cout << "MAINMENU::Enter" << std::endl;

        return 0;
    }

    int MainMenuPhase::InternOnRun()
    {
        std::cout << "MAINMENU::Run" << std::endl;

        counter++;
        if (counter > 4)
        {
            counter = 0;
            return Type::LOAD_MAP;
        }

        return Type::MAIN_MENU;
    }

    int MainMenuPhase::InternOnLeave()
    {
        std::cout << "MAINMENU::Leave" << std::endl;

        return 0;
    }
}
