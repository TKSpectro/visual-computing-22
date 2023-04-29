#include "data.eventSystem.h"

#include <iostream>
#include <cassert>

namespace Data
{
    EventSystem::EventSystem()
    {}

    EventSystem::~EventSystem()
    {}

    void EventSystem::Register(EventType::Enum type, EventListener listener)
    {
        std::cout << "DATA::EVENTSYSTEM::Register     Event - Type:" << type << std::endl;
        eventListeners.push_back(std::make_pair(type, listener));
    }

    void EventSystem::Unregister(EventType::Enum type, EventListener listener)
    {
        std::cout << "DATA::EVENTSYSTEM::Unregister   Event - Type:" << type << std::endl;

        EventListenerList::iterator it;

        for (it = eventListeners.begin(); it != eventListeners.end(); ++it)
        {
            assert(it->second != nullptr);

            if (it->second == listener)
            {
                eventListeners.erase(it);

                break;
            }
        }

    }

    void EventSystem::FireEvent(EventType::Enum type)
    {
        Event* event = nullptr;
        try
        {
            event = new Event();
            event->SetType(type);
            FireEvent(*event);
        } catch (...)
        {
            delete event;
        }
    }

    void EventSystem::FireEvent(EventType::Enum type, int data)
    {
        Event* event = nullptr;
        try
        {
            event = new Event();
            event->SetType(type);
            event->SetData(data);
            FireEvent(*event);
        } catch (...)
        {
            delete event;
        }
    }

    void EventSystem::FireEvent(Event& event)
    {
        for (EventListenerPair listener : eventListeners)
        {
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
