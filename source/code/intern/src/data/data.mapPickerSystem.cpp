#include "data.mapPickerSystem.h"

#include <iostream>

namespace Data
{
    int MapPickerSystem::GetMapIndex()
    {
        return mapIndex;
    }

    void MapPickerSystem::SetMapIndex(int _mapIndex)
    {
        if (_mapIndex >= 0 && _mapIndex < std::size(mapFilePaths))
        {
            mapIndex = _mapIndex;
        } else
        {
            std::cout << "MapPickerSystem::SetMapIndex() NOT SET-> " << mapIndex << std::endl;
        }
    }

    const char* MapPickerSystem::GetCurrentMapFilePath() const
    {
        return mapFilePaths[mapIndex];
    }
}