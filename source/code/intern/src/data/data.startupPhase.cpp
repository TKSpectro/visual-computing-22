#include <iostream>
#include <tinyxml2.h>
#include <fstream>

#include "data.startupPhase.h"
#include "data.metaEntitySystem.h"
#include "data.entitySystem.h"

namespace Data
{
    void StartupPhase::OnEnter()
    {}

    void StartupPhase::OnRun(tinyxml2::XMLDocument& doc)
    {
        std::cout << "DATA::STARTUP::Run" << std::endl;

        int metaEntityCount = MetaEntitySystem::GetInstance().Initialize(doc);

        std::cout << "DATA::STARTUP::Run " << metaEntityCount << " MetaEntities initialized" << std::endl;
    }

    void StartupPhase::OnLeave()
    {}
}
