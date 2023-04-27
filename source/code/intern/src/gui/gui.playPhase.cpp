#include "gui.playPhase.h"

namespace Gui
{
    void PlayPhase::OnEnter()
    {}

    void PlayPhase::OnRun()
    {
        // Handle all Events we saved in the Event Queue

        // if for example the event is a mouseclick which hits a gui element
        // i.e. user clicked menu button we will handle it here
        // if its not directly for gui we convert it to a LogicCommand
    }

    void PlayPhase::OnLeave()
    {}
}
