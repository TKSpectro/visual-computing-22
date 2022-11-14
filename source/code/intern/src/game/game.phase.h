#pragma once

namespace Game
{
    class Phase
    {
    public:
        enum Type
        {
            STARTUP,
            MAIN_MENU,
            LOAD_MAP,
            PLAY,
            UNLOAD_MAP,
            SHUTDOWN,
            NumberOfTypes,
            Undefined = -1,
        };

    public:
        int OnEnter();
        int OnRun();
        int OnLeave();

    protected:
        //virtual ~Phase();

    private:
        virtual int InternOnEnter() = 0;
        virtual int InternOnRun() = 0;
        virtual int InternOnLeave() = 0;
    };
}