
#include "data.eventListener.h"
#include "data.eventSystem.h"

class Listener
{
public:

    static Listener& GetInstance()
    {
        static Listener instance;

        return instance;
    }

public:

    void Initialize()
    {
        Data::EventSystem::GetInstance().Register(0, Listener::OnEventA);
        Data::EventSystem::GetInstance().Register(1, Listener::OnEventB);
    }

    void Finalize()
    {
        Data::EventSystem::GetInstance().Unregister(0, Listener::OnEventA);
        Data::EventSystem::GetInstance().Unregister(1, Listener::OnEventB);
    }

private:

    static void OnEventA(Data::Event& event)
    {
        Listener::GetInstance().DoSomethingA(event);
    }

    static void OnEventB(Data::Event& event)
    {
        Listener::GetInstance().DoSomethingB(event);
    }

private:

    Listener() = default;
    ~Listener() = default;

private:

    void DoSomethingA(Data::Event& event)
    {}

    void DoSomethingB(Data::Event& event)
    {}

private:

    Listener(const Listener&) = delete;
    Listener& operator = (const Listener&) = delete;
};

int main()
{
    Listener::GetInstance().Initialize();

    Listener::GetInstance().Finalize();

    return 0;
}

