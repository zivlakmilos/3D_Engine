#ifndef _ENGINE_CORE_MEMORY_ARRAY_HANDLER_H_
#define _ENGINE_CORE_MEMORY_ARRAY_HANDLER_H_

#include "engine/core/memory/baseresourcehandler.h"

namespace zi
{
    template<typename T>
    class ArrayHandler
    {
    public:
        ArrayHandler(T *pResource) : m_pResource(pResource) {};
        virtual ~ArrayHandler(void) { delete[] this->m_pResource; };
        
    protected:
        T *m_pResource;
    };
}

#endif // _ENGINE_CORE_MEMORY_ARRAY_HANDLER_H_
