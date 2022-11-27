#include <iostream>
#include <tinyxml2.h>

#include "game.startupPhase.h"
#include "../data/data.startupPhase.h"

using namespace tinyxml2;

namespace Game
{
    int StartupPhase::InternOnEnter()
    {
        std::cout << "STARTUP::Enter" << std::endl;
        return 0;
    }

    int StartupPhase::InternOnRun()
    {
        std::cout << "STARTUP::Run" << std::endl;

        // This code is not valid as of now (PseudoCode)
        //XMLDocument& rXMLDocument = TinyXML::Open("data.meta-entity.xml");
        //Data::StartupPhase::OnRun(rXMLDocument)
        //Data::StartupPhase::OnRun(rXMLDocument) ->
            //Called MetaEntitySystem::Initialize(rXMLDocument) ->
                // Runs over the xml file and creates the metaEntities with the data part

        XMLDocument doc;
        doc.LoadFile("../code/intern/src/data/data.meta-entity.xml");

        Data::StartupPhase::GetInstance().OnRun(doc);

        //data::StartupPhase::OnRun()
        //logic::StartupPhase::OnRun()
        //gfx::StartupPhase::OnRun()
        //gui::StartupPhase::OnRun()

        // Normally we will load a resource-, file-, buffer-, model-managers here

        /*counter++;

        if (counter > 4)
        {
            counter = 0;
            return Type::MAIN_MENU;
        }

        return Type::STARTUP;*/
        return Type::MAIN_MENU;
    }

    int StartupPhase::InternOnLeave()
    {
        std::cout << "STARTUP::Leave" << std::endl;
        return 0;
    }
}
