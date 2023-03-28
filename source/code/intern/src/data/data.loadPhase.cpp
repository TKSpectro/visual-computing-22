#include "data.loadPhase.h"

#include <iostream>

#include "data.entitySystem.h"

namespace Data
{
    void LoadPhase::OnEnter()
    {}

    void LoadPhase::OnRun(tinyxml2::XMLDocument& doc)
    {
        std::cout << "DATA::LOAD::Run" << std::endl;

        int entityCount = EntitySystem::GetInstance().Initialize(doc);

        std::cout << "DATA::LOAD::Run " << entityCount << " Entities initialized" << std::endl;
    }

    void LoadPhase::OnLeave()
    {}
}