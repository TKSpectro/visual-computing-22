#pragma once
#include <tinyxml2.h>

#include "../core/core_id_manager.h"
#include "../core/core_item_manager.h"
#include "data.metaEntity.h"

namespace Data
{
    class MapSystem
    {
    public:
        static MapSystem& GetInstance()
        {
            static MapSystem instance;
            return instance;
        };

        MapSystem(const MapSystem&) = delete;
        MapSystem& operator = (const MapSystem&) = delete;

    public:


    private:
        MapSystem()
        {};
    };
}