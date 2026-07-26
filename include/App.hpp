#pragma once 

#include "CommandHandler.hpp"

class App {
    public:
        void run();
    private:
        void showBanner();
        void handleInput();

        // Create a object of the CommandHandler Class
        CommandHandler handler;
};