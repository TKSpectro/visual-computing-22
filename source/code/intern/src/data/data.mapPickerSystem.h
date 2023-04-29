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

        const char* GetCurrentMapFilePath() const;

    private:
        MapPickerSystem() :
            mapIndex(0)
        {};

    private:
        int mapIndex;
        const char* const mapFilePaths[2] = { "maps/data.map-1.xml", "maps/data.map-2.xml" };
    };
}