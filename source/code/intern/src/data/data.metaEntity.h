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
        MetaEntity() :
            id(-1),
            name(""),
            size(0.0f),
            facetes{ nullptr, nullptr }
        {}

        MetaEntity(int _id, std::string _name, float _size) :
            id(_id),
            name(_name),
            size(_size),
            facetes{ nullptr, nullptr }
        {}

        friend std::ostream& operator << (std::ostream& os, const MetaEntity& metaEntity)
        {
            return (os << "Id: " << metaEntity.id
                << "\n Name: " << metaEntity.name
                << "\n Size: " << metaEntity.size
                << "\n AABB-min: " << metaEntity.aabb.GetMin()[0] << ", " << metaEntity.aabb.GetMin()[1] << ", " << metaEntity.aabb.GetMin()[2]
                << "\n AABB-max: " << metaEntity.aabb.GetMax()[0] << ", " << metaEntity.aabb.GetMax()[1] << ", " << metaEntity.aabb.GetMax()[2]
                << std::endl);
        }

    public:
        int id;
        std::string name;
        float size;
        Core::AABB3Float aabb;

        void* facetes[2];

    public:

        struct FacetType
        {
            enum Facet
            {
                GraphicsFacet,
                LogicFacet,
                NumberOfFacets
            };
        };

    public:
        std::string toString()
        {
            std::stringstream ss;
            ss << (*this);
            return ss.str();
        }
    };
}