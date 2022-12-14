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
        std::cout << "Register:" << type << std::endl;
        eventListeners.push_back(&listener);
    }

    void EventSystem::Unregister(Event::BTypeID type, EventListener listener)
    {
        std::cout << "Unregister:" << type << std::endl;

        std::list<EventListener*>::iterator it;
        const std::list<EventListener*>::iterator endIterator = eventListeners.end();

        for (it = eventListeners.begin(); it != eventListeners.end(); ++it)
        {
            EventListener* currentListener = *it;

            assert(currentListener != nullptr);

            if (currentListener == &listener)
            {
                eventListeners.erase(it);

                break;
            }
        }

    }

    Event& EventSystem::MakeEvent()
    {
        Event* event = new Event();
        return *event;
    }

    void EventSystem::FireEvent(Event& event)
    {
        for (EventListener* listener : eventListeners)
        {
            assert(listener != nullptr);

            (*listener)(event);
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
