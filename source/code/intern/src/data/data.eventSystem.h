#pragma once
#include <list>

#include "data.event.h"
#include "data.eventListener.h"
#include "data.eventType.h"

namespace Data
{
    using EventListenerPair = std::pair<EventType, EventListener>;
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
        void Register(EventType type, EventListener listener);
        void Unregister(EventType type, EventListener listener);

        void FireEvent(EventType type);
        void FireEvent(EventType type, int data);

    public:
        void AddEvent(Event& event);
        void ProcessEvents();

    private:
        void FireEvent(Event& event);
        void FireEvent(Event& event, int data);

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
