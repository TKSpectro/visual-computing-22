#include "data.unloadPhase.h"

#include <iostream>

#include "data.entitySystem.h"

namespace Data
{
    void UnloadPhase::OnEnter()
    {}

    void UnloadPhase::OnRun()
    {
        std::cout << "DATA::UNLOAD::Run" << std::endl;

        EntitySystem::GetInstance().DestroyAllEntities();
    }

    void UnloadPhase::OnLeave()
    {}
}