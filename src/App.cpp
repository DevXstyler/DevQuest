#include "App.hpp"
#include "CommandHandler.hpp"

#include <iostream>


void App::run(){
    std::cout << "Hello World!";
    showBanner();
    handleInput();
}
void App::showBanner(){
    std::cout << R"(
                                                ______  _______ _    _  _____  _     _ _______ _______ _______
                                                |     \ |______  \  /  |   __| |     | |______ |______    |   
                                                |_____/ |______   \/   |____\| |_____| |______ ______|    |   
                                            V. 0.0.1 - Created by DevXstyler - https://github.com/devxstyler/devquest
    )";
}

void App::handleInput(){
    std::string user_input = ""; 
    std::cout << "What are your Orders, master?: ";
    std::getline(std::cin, user_input); // Use this, instead of: `std::cin >> user_input` | cin only reads the 1st word, it ends after a space
    
    user_input = user_input.tolower();
    // Create a .. of the CommandHandler Class and pass the user_input to it.
    CommandHandler handler;
    handler.handleCommand(user_input);

}