#include <iostream>
#include <string>
#include <ctime>
#include <windows.h>
#include <mmsystem.h>
#include <cstdlib>
#include <direct.h>
#include <thread>
#include <chrono>

#pragma comment(lib, "winmm.lib")

std::string action;
int Xp;  // XP-Variable
int introCount = 0;  // Zähler für die Anzahl der Einleitungen




//compile with: g++ -O2 -static -std=c++17 -o DevQuest.exe DevQuest.cpp -lwinmm
//for GUI:      g++ -O2 -static -std=c++17 -mwindows -o DevQuest.exe DevQuest.cpp -lwinmm




void input();
void flush();
void exitProgram();

void introduction() {
    PlaySound("Assets/Sounds/BlopGulp.wav", NULL, SND_FILENAME | SND_ASYNC);
    std::cout << "+--------------------------------+\n";
    std::cout << "| [DevQuest] - Made by Xstyler   |\n";
    std::cout << "|    Thank You For Playing!      |\n";
    std::cout << "+--------------------------------+\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    input();
}

void input() {
    if (introCount < 5) {  // Zeigt die Einleitung nur 5 Mal an
        std::cout << std::endl;
        std::cout << "[ Enter the Action you want to perform. Type 'help' for all Commands ]\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(150));
        introCount++;  // Zähler erhöhen
    }

    while (action.empty()) {  // Überprüfen, ob 'action' leer ist
        std::cout << ">> ";
        std::getline(std::cin, action);
        std::cout << std::endl;
    }
}

void help() {
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    std::cout << "+-----------------------------------+\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    std::cout << "|   [DevQuest] - Made by Xstyler    |\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    std::cout << "|                                   |\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    std::cout << "|>1. help - Show this help message <|\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    std::cout << "|>2. exit - Exit the program.      <|\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    std::cout << "|>3. quests - shows your quests    <|\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    std::cout << "|>4. xp - shows your xp            <|\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    std::cout << "+-----------------------------------+\n";
    flush();  // Leeren der 'action'-Variable
}
void exitProgram() {
    std::cout << "===================================================\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(10)); 
    std::cout << "E";
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    std::cout << "x";
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    std::cout << "i";
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    std::cout << "t";
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    std::cout << "i";
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    std::cout << "n";
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    std::cout << "g";
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    std::cout << ".";
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    std::cout << ".";
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    std::cout << "." << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::cout << "===================================================\n";
    std::exit(0);  // Verwendung der System-funktion exit()
}

void flush() {
    action.clear();  // Leeren der 'action'-Variable
    if (!action.empty()) {
        action.clear();  // Sicherstellen, dass 'action' wirklich leer ist
    }
    else {
        input();  // Eingabeaufforderung erneut anzeigen
    }
}
void xp(){
    std::cout << "===================================================\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    std::cout << "You have " << Xp << " XP.\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    std::cout << "===================================================\n";
    flush();  // Leeren der 'action'-Variable
}
void quests(){
    std::cout << "===================================================\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    std::cout << "You have no quests.\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    std::cout << "===================================================\n";
    flush();  // Leeren der 'action'-Variable
}
int main() {
    SetConsoleTitle("DevQuest");
    introduction();
    while (true)
    {
        // Kommandoauswahl basierend auf der Eingabe
        if (action == "help" || action == "Help") {
            help();
        }
        else if (action == "exit" || action == "Exit")
        {
            exitProgram();
        }
        else if (action == "Xp" || action == "xp" || action == "XP")
        {
            xp();
        }
        else if (action == "quests" || action == "Quests")
        {
            quests();
        }
        else {
            std::cout << "Unknown command. Type 'help' for a list of commands." << std::endl;
            flush();  // Leeren der 'action'-Variable
        } 
    }
    return 0;
}