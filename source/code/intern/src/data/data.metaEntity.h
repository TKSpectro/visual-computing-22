#pragma once
#include <string>
#include <sstream>
#include <ostream>

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
        // Data      -        - Name/Id
        // Data      -        - Type
        // Data      -        - Position
        // Data      -        - Stats (HP, Attack, Defense) -> Base Stats are global, Buffs and Debuffs are specific
        // Data      -        - Orientation
        // Data      -        - AABB (World) - Axis Aligned Bounding Box (World Coordinates)
        // Data      -        - Size
        // Data      - global - AABB (Local) - Axis Aligned Bounding Box (Local Coordinates)
        // Logic     -        - (Animation-)State (Walking, Running, Sleep)
        // Gfx       - global - Model
        // Gfx       - global - Textures
        // Gfx/Logic - global - Animations
        // Besitz
    public:
        std::string toString()
        {
            std::stringstream ss;
            ss << (*this);
            return ss.str();
        }
    };
}