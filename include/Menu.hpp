#pragma once

#include <string>

class Menu{
    public:
        void showMenu();
        int loadBanner();
        void showBanner();
    private:
        std::string banner_content;

};