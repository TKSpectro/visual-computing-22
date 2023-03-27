#include "data.eventSystem.h"

#include <iostream>
#include <cassert>

namespace Data
{
    EventSystem::EventSystem()
    {}

    EventSystem::~EventSystem()
    {}

    void EventSystem::Register(Event::BTypeID type, EventListener listener)
    {
        std::cout << "Register Event - Type:" << type << std::endl;
        eventListeners.push_back(std::make_pair(type, &listener));
    }

    void EventSystem::Unregister(Event::BTypeID type, EventListener listener)
    {
        std::cout << "Unregister Event - Type:" << type << std::endl;

        EventListenerList::iterator it;

        for (it = eventListeners.begin(); it != eventListeners.end(); ++it)
        {
            assert(it->second != nullptr);

            if (it->second == &listener)
            {
                eventListeners.erase(it);

                break;
            }
        }

    }

    Event& EventSystem::MakeEvent()
    {
        return *(new Event());
    }

    void EventSystem::FireEvent(Event& event)
    {
        for (EventListenerPair listener : eventListeners)
        {
            assert(listener.second != nullptr);

            if (listener.first == event.GetType())
            {
                (*listener.second)(event);
            }

        }
    }

    void EventSystem::AddEvent(Event& event)
    {
        queuedEvents.push_back(event);
    }

    void EventSystem::ProcessEvents()
    {
        for (Event& event : queuedEvents)
        {
            FireEvent(event);
        }
    }
}
