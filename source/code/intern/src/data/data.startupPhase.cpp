#include "data.startupPhase.h"

#include <iostream>
#include <tinyxml2.cpp>
#include <fstream>

#include "data.metaEntitySystem.h"
#include "data.entitySystem.h"

namespace Data
{
    void StartupPhase::OnEnter()
    {}

    void StartupPhase::OnRun(tinyxml2::XMLDocument& doc)
    {
        int metaEntityCount = MetaEntitySystem::GetInstance().Initialize(doc);

        std::cout << "DATA::STARTUP::Run              " << metaEntityCount << " MetaEntities initialized" << std::endl;
    }

    void StartupPhase::OnLeave()
    {}
}
