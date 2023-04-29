#include "data.shutdownPhase.h"

#include <iostream>

#include "data.metaEntitySystem.h"
#include "data.entitySystem.h"

namespace Data
{
    void ShutdownPhase::OnEnter()
    {}

    void ShutdownPhase::OnRun()
    {
        std::cout << "DATA::SHUTDOWN::Run                         Clearing Entity and MetaEntity System" << std::endl;

        EntitySystem::GetInstance().DestroyAllEntities();
        MetaEntitySystem::GetInstance().DestroyAllMetaEntities();
    }

    void ShutdownPhase::OnLeave()
    {}
}
