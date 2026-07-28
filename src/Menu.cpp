#include "Menu.hpp"

#include <fstream>
#include <iostream>

void Menu::showMenu(){
    showBanner();
}

int Menu::loadBanner(){
    std::ifstream banner_file("assets/banner.txt"); //banner_file = the name we give the file we open | Can be anything

    if (!banner_file.is_open()){
        std::cerr << "Error opening banner.txt\n";
        return 1;
    }
    banner_content.clear();
    std::string line;
    //std::string banner_content;
    while (std::getline(banner_file, line)){ // Var 1.: from what file | Var 2. Into what variable
        banner_content += line + "\n";
    }

    banner_file.close();
    return 0;
}

void Menu::showBanner(){
    loadBanner();
    std::cout << banner_content;
}