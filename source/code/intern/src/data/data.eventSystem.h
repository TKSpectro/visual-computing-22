#pragma once
#include <list>

#include "data.event.h"
#include "data.eventListener.h"

namespace Data
{
    using EventListenerPair = std::pair<Event::BTypeID, EventListener*>;
    using EventListenerList = std::list<EventListenerPair>;

    class EventSystem
    {
    public:
        static EventSystem& GetInstance()
        {
            static EventSystem instance;
            return instance;
        };

    public:
        void Register(Event::BTypeID type, EventListener listener);
        void Unregister(Event::BTypeID type, EventListener listener);

    public:
        Event& MakeEvent();
        void FireEvent(Event& event);
        void AddEvent(Event& event);
        void ProcessEvents();

    private:
        EventSystem();
        ~EventSystem();

    private:
        EventSystem(const EventSystem&) = delete;
        EventSystem& operator = (const EventSystem&) = delete;

    private:
        std::list<Event> queuedEvents;
        EventListenerList eventListeners;
    };
}
