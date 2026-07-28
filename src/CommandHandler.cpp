#include "CommandHandler.hpp"

#include <iostream>

void CommandHandler::handleCommand(const std::string& command){
    if (command == "exit") {
        exit(0);
    }
    else if (command == "help") {
        std::cout << "This is not very helpful.";    
    }
    std::cout << std::endl;
}