#pragma once
#include <string>
#include <sstream>
#include <ostream>

#include "../core/core_aabb.h"

namespace Data
{
    class MetaEntity
    {
    public:
        MetaEntity()
        {}
        MetaEntity(int _id, std::string _name, float _size)
            :id(_id), name(_name), size(_size)
        {}

        friend std::ostream& operator << (std::ostream& os, const MetaEntity& metaEntity)
        {
            return (os << "Id: " << metaEntity.id << "\n Name: " << metaEntity.name << "\n Size: " << metaEntity.size << std::endl);
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