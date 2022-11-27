#pragma once
#include <tinyxml2.h>

#include "../core/core_id_manager.h"
#include "../core/core_item_manager.h"
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
        MetaEntity& CreateMetaEntity(std::string name);
        void DestroyMetaEntity(MetaEntity& metaEntity);
        void DestoryAllMetaEntities();
        MetaEntity& SearchMetaEntity(std::string name);
        //MetaEntity& GetMetaEntity(CMetaEntityID _ID);
        //bool ContainsMetaEntity(const char* _pName);
        //CMetaEntityID GetMetaEntityID(const char* _pName);
        //CMetaEntityIterator BeginMetaEntities();
        //CMetaEntityIterator EndMetaEntities();

    private:
        MetaEntitySystem()
        {};

    private:
        Core::CIDManager idManager;
        Core::CItemManager<MetaEntity> itemManager;
    };
}