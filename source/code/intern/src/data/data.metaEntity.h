#pragma once
#include <string>
#include <sstream>
#include <ostream>

#include "../core/core_aabb.h"

namespace Data
{
    // Lightweight class with only member variables and getter and setters

    class MetaEntity
    {
    public:
        MetaEntity()
        {}
        MetaEntity(int _id, std::string _name, float _size)
            :id(_id), name(_name), size(_size)
        {}

        friend std::ostream& operator << (std::ostream& os, const MetaEntity& s)
        {
            return (os << "Id: " << s.id << "\n Name: " << s.name << "\n Size: " << s.size << std::endl);
        }

    public:
        int id;
        std::string name;
        float size;
        Core::AABB2Float aabb;

        void* facetes[2];

    public:
        std::string toString()
        {
            std::stringstream ss;
            ss << (*this);
            return ss.str();
        }
    };
}