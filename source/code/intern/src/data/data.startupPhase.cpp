#include <iostream>
#include <tinyxml2.h>
#include <fstream>

#include "data.startupPhase.h"
#include "data.metaEntitySystem.h"

void Data::StartupPhase::OnEnter()
{}

void Data::StartupPhase::OnRun(tinyxml2::XMLDocument& doc)
{
    std::cout << "DATA::STARTUP::Run" << std::endl;

    int metaEntityCount = MetaEntitySystem::GetInstance().Initialize(doc);

    std::cout << "DATA::STARTUP::Run " << metaEntityCount << " MetaEntities initialized" << std::endl;
}

void Data::StartupPhase::OnLeave()
{}
