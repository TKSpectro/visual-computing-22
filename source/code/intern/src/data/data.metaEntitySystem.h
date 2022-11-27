#pragma once
#include <tinyxml2.h>

#include "data.metaEntity.h"

namespace Data
{
    class MetaEntitySystem
    {
    public:
        static MetaEntitySystem& GetInstance()
        {
            static MetaEntitySystem instance;
            return instance;
        };

        MetaEntitySystem(const MetaEntitySystem&) = delete;
        MetaEntitySystem& operator = (const MetaEntitySystem&) = delete;

    public:
        int Initialize(tinyxml2::XMLDocument& doc);
        MetaEntity& CreateMetaEntity(const char* _pName);
        void DestroyMetaEntity(MetaEntity& _rMetaEntity);
        void DestoryAllMetaEntities();
        MetaEntity& SearchMetaEntity(const char* _pName);
        //MetaEntity& GetMetaEntity(CMetaEntityID _ID);
        //bool ContainsMetaEntity(const char* _pName);
        //CMetaEntityID GetMetaEntityID(const char* _pName);
        //CMetaEntityIterator BeginMetaEntities();
        //CMetaEntityIterator EndMetaEntities();

    private:
        MetaEntitySystem()
        {};
    };
}