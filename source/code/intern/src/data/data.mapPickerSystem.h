#pragma once

#include <string>

namespace Data
{
    class MapPickerSystem
    {
    public:
        static MapPickerSystem& GetInstance()
        {
            static MapPickerSystem instance;
            return instance;
        };

        MapPickerSystem(const MapPickerSystem&) = delete;
        MapPickerSystem& operator = (const MapPickerSystem&) = delete;

    public:
        int GetMapIndex();
        void SetMapIndex(int index);

        const char* GetCurrentMapFileName() const;

    private:
        MapPickerSystem() :
            mapIndex(0)
        {};

    private:
        int mapIndex;

        const char* const mapFileNames[2] = { "data.map-1.xml", "data.map-2.xml" };
    };
}