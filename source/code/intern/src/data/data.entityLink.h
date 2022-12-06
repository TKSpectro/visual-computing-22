#pragma once

namespace Data
{
    class Entity;
}

namespace Data
{
    class EntityLink
    {
    public:

        static Entity& GetEntity(EntityLink& link, const EntityLink Entity::* mtr);
        static const Entity& GetEntity(const EntityLink& link, const EntityLink Entity::* mtr);

    public:

        EntityLink();

    public:

        void Link(EntityLink& nextLink);
        void Unlink();

        bool IsLinked() const;

    public:

        Entity& GetEntity();
        const Entity& GetEntity() const;

    public:

        void SetNext(EntityLink* link);
        EntityLink* GetNext();

        void SetPrevious(EntityLink* link);
        EntityLink* GetPrevious();

    private:

        EntityLink* next;
        EntityLink* previous;
    };
}
