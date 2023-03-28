
#pragma once

#include <assert.h>

namespace Core
{
    template <class T>
    class CSmartPtr
    {
    public:

        using CThis = CSmartPtr<T>;
        using X = T;
        using XPtr = T*;
        using XConstPtr = const T*;
        using XRef = T&;
        using XConstRef = const T&;

    public:

        CSmartPtr()
            : m_pObject(nullptr)
        {}

        explicit CSmartPtr(XPtr _pObject)
            : m_pObject(_pObject)
        {
            AddRef(_pObject);
        }

        CSmartPtr(const CThis& _rPtr)
            : m_pObject(_rPtr.m_pObject)
        {
            AddRef(m_pObject);
        }

        ~CSmartPtr()
        {
            Release(m_pObject);
        }

    public:

        CThis& operator = (const CThis& _rPtr)
        {
            XPtr pObject;

            pObject = m_pObject; m_pObject = _rPtr.m_pObject;

            AddRef(m_pObject); Release(pObject);

            return *this;
        }

        CThis& operator = (XPtr _pObject)
        {
            XPtr pObject;

            pObject = m_pObject; m_pObject = _pObject;

            AddRef(m_pObject); Release(pObject);

            return *this;
        }

    public:

        bool operator < (XConstPtr _pObject) const
        {
            return m_pObject < _pObject;
        }

        bool operator <= (XConstPtr _pObject) const
        {
            return m_pObject <= _pObject;
        }

        bool operator > (XConstPtr _pObject) const
        {
            return m_pObject > _pObject;
        }

        bool operator >= (XConstPtr _pObject) const
        {
            return m_pObject >= _pObject;
        }

        bool operator == (XConstPtr _pObject) const
        {
            return m_pObject == _pObject;
        }

        bool operator != (XConstPtr _pObject) const
        {
            return m_pObject != _pObject;
        }

    public:

        bool operator < (const CThis& _rPtr) const
        {
            return m_pObject < _rPtr.m_pObject;
        }

        bool operator <= (const CThis& _rPtr) const
        {
            return m_pObject <= _rPtr.m_pObject;
        }

        bool operator > (const CThis& _rPtr) const
        {
            return m_pObject > _rPtr.m_pObject;
        }

        bool operator >= (const CThis& _rPtr) const
        {
            return m_pObject >= _rPtr.m_pObject;
        }

        bool operator == (const CThis& _rPtr) const
        {
            return m_pObject == _rPtr.m_pObject;
        }

        bool operator != (const CThis& _rPtr) const
        {
            return m_pObject != _rPtr.m_pObject;
        }

    public:

        XRef operator * ()
        {
            assert(IsValid());

            return *m_pObject;
        }

        XConstRef operator * () const
        {
            assert(IsValid());

            return *m_pObject;
        }

        XPtr operator -> ()
        {
            return m_pObject;
        }

        XConstPtr operator -> () const
        {
            return m_pObject;
        }

    public:

        bool IsValid() const
        {
            return m_pObject != nullptr;
        }

    public:

        XPtr GetPtr()
        {
            return m_pObject;
        }

        XConstPtr GetPtr() const
        {
            return m_pObject;
        }

    public:

        int AddRef()
        {
            return AddRef(m_pObject);
        }

        int Release()
        {
            return Release(m_pObject);
        }

    private:

        XPtr m_pObject;

    private:

        static int AddRef(XPtr _pObject)
        {
            return (_pObject != nullptr) ? _pObject->AddRef() : 0;
        }

        static int Release(XPtr _pObject)
        {
            return (_pObject != nullptr) ? _pObject->Release() : 0;
        }
    };



    // Implementation from lecture
    template<typename T>
    class SmartPointer
    {
    public:

        using This = SmartPointer<T>;
        using X = T;
        using XPtr = T*;
        using XRef = T&;

    public:

        SmartPointer()
            : object(nullptr)
        {}

        SmartPointer(const This& _other)
            : object(_other.object)
        {
            AddRef(object);
        }

        SmartPointer(XPtr _object)
            : object(_object)
        {
            AddRef(object);
        }

        ~SmartPointer()
        {
            Release(object)
        }

    public:

        SmartPointer& operator=(const This& _other)
        {
            XPtr tempObject = object;

            object = _other.object;

            AddRef(object);

            Release(tempObject);

            return *this;
        }

        SmartPointer& operator=(XPtr _object)
        {
            XPtr tempObject = object;

            object = _object;

            AddRef(object);

            Release(tempObject);

            return *this;
        }

        bool operator == (const This& _other) const
        {
            return object == _other.object;
        }

        bool operator == (XPtr _other) const
        {
            return object == _other;
        }

        bool operator != (const This& _other) const
        {
            return object != _other.object;
        }

        bool operator != (XPtr _other) const
        {
            return object != _other;
        }

    public:

        XPtr operator -> ()
        {
            assert(object != nullptr);

            return object;
        }

        XPtr operator * ()
        {
            assert(*object != nullptr);

            return *object;
        }

    private:

        XPtr object;

    private:

        static void AddRef(XPtr object)
        {
            if (object != nullptr)
            {
                X::AddRef(object);
            }
        }

        static void Release(XPtr object)
        {
            if (object != nullptr)
            {
                X::Release(object);
            }
        }
    };
} // namespace Core

// Example usage
//#include "core_smart_pointee.h"
//namespace Core
//{
//    class Foo : public SmartPointee
//    {};
//
//    using FooPtr = SmartPointer<Foo>;
//
//    int mainTest()
//    {
//        FooPtr fooPtr1 = new Foo();
//        FooPtr fooPtr2 = fooPtr1;
//        FooPtr fooPtr3(fooPtr1);
//
//        Foo* pFoo = new Foo();
//
//        fooPtr2 = pFoo;
//        fooPtr2 = fooPtr1;
//
//        FooPtr fooPtr4;
//
//        return 0;
//    }
//}