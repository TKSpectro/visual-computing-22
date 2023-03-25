#include "data.shutdownPhase.h"

#include <iostream>

#include "data.metaEntitySystem.h"

namespace Data
{
    void ShutdownPhase::OnEnter()
    {}

    void ShutdownPhase::OnRun()
    {
        std::cout << "DATA::SHUTDOWN::Run::Clearing MetaEntity System" << std::endl;

        MetaEntitySystem::GetInstance().DestoryAllMetaEntities();
    }

    void ShutdownPhase::OnLeave()
    {}
}
