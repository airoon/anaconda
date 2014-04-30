#ifndef CHOWDREN_INSTANCEMAP_H
#define CHOWDREN_INSTANCEMAP_H

#include "chowconfig.h"
#include "frameobject.h"

class ManagerObjectList : public ObjectList
{
public:
#ifdef CHOWDREN_USE_DYNTREE
    DynamicTree tree;
#endif

    ManagerObjectList()
    : ObjectList()
    {
    }
};

class InstanceMap
{
public:
    ManagerObjectList items[MAX_OBJECT_ID];

    InstanceMap()
    {
    }

    void clear()
    {
        for (unsigned int i = 0; i < MAX_OBJECT_ID; i++) {
            items[i].clear();
        }
    }
};

#endif // CHOWDREN_INSTANCEMAP_H
