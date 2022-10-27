#pragma once
#include <iostream>

class Application {
    public:
    static Application& instance() {
        static Application s;
        return s;
    }

    Application(const Application&) = delete;
    Application& operator = (const Application&) = delete;

    public:
    void Run();

    private:
    Application() {
    }
    ~Application() {
    }

};