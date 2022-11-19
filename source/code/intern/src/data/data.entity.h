#pragma once

namespace Data
{
    // Lightweight class with only member variables and getter and setters

    class Entity
    {
    private:
        int m_id;
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
    };
}