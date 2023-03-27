#include "game.playPhase.h"

#include <iostream>

#include "core/core_time.h"
#include "game/game.application.h"

#include "graphics/gfx.playPhase.h"
#include "gui/gui.playPhase.h"

#include "data/data.entitySystem.h"
#include "data/data.playerSystem.h"

namespace Game
{
    int PlayPhase::InternOnEnter()
    {
        std::cout << "GAME::PLAY::Enter" << std::endl;

        Core::Time::Reset();

        Gui::PlayPhase::GetInstance().OnEnter();
        Gfx::PlayPhase::GetInstance().OnEnter();


        return 0;
    }

    int PlayPhase::InternOnRun()
    {
        Core::Time::OnFrame();
        // Now we can call getTime(), getFrameDuration()

        if (counter % 100 == 0)
        {
            std::cout << "GAME::PLAY::Run::" << counter << std::endl;
        }

        Gui::PlayPhase::GetInstance().OnRun();
        Gfx::PlayPhase::GetInstance().OnRun();

        // TODO: Remove this. Just simulating player movement
        Data::PlayerSystem& playerSystem = Data::PlayerSystem::GetInstance();
        Data::Entity* player = playerSystem.GetPlayer();
        player->position = Core::Float3(player->position[0] + 0.5f, player->position[1], player->position[2]);

        counter++;
        if (counter > 2000)
        {
            return Type::UNLOAD_MAP;
        }

        return Type::PLAY;
    }

    int PlayPhase::InternOnLeave()
    {
        std::cout << "GAME::PLAY::Leave" << std::endl;

        Gui::PlayPhase::GetInstance().OnLeave();
        Gfx::PlayPhase::GetInstance().OnLeave();

        return 0;
    }
}
