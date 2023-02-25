
#pragma once

#include "core_uncopyable.h"

#include <assert.h>

template <typename T>
class SmartPointer;

namespace Core
{
    class CSmartPointee : private CUncopyable
    {
    public:

        CSmartPointee()
            : m_NumberOfReferences(0)
        {}

        virtual ~CSmartPointee()
        {
            assert(m_NumberOfReferences == 0);
        }

    public:

        int GetNumberOfReferences() const
        {
            return m_NumberOfReferences;
        }

        int AddRef()
        {
            ++m_NumberOfReferences;

            return m_NumberOfReferences;
        }

        int Release()
        {
            assert(m_NumberOfReferences > 0);

            --m_NumberOfReferences;

            if (m_NumberOfReferences == 0)
            {
                FreeResource();
            }

            return m_NumberOfReferences;
        }

    private:

        int m_NumberOfReferences;

    private:

        virtual void FreeResource() = 0;
    };


    // Implementation from lecture
    class SmartPointee : private CUncopyable
    {
    public:

        SmartPointee()
            : numberOfReferences(0)
        {}

        virtual ~SmartPointee() = default;

    private:

        int numberOfReferences;

    private:

        static int RefCount(SmartPointee& object)
        {
            return object.numberOfReferences;
        }

        static int AddRef(SmartPointee& object)
        {
            ++object.numberOfReferences;

            return object.numberOfReferences;
        }

        static int Release(SmartPointee& object)
        {
            --object.numberOfReferences;

            int refCount = object.numberOfReferences;

            if (object.numberOfReferences == 0)
            {
                delete& object;
            }

            return refCount;
        }

    private:

        template <typename T>
        friend class SmartPointer;
    };
} // namespace Core