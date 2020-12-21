#include "engine.h"
#include <Windows.h>


#define 	SFML_DEFINE_DISCRETE_GPU_PREFERENCE





int main()
{
    HWND hWnd = GetConsoleWindow();		// чтобы не было консоли
    ShowWindow(hWnd, SW_HIDE);


    Engine engine;


    while (engine.getUserMainMenuInput())
    {
        switch (engine.getUserMainMenuInput())
        {
        case Exit:     // Полностью выключить игру
            break;
        case MainMenu:     // Открыть главное меню
            engine.mainMenu();
            break;
        case Settings:      // Открыть настройки
            engine.settings();
            break;
        case LevelSelectionMenu:
            engine.levelSelectionMenu();
            break;
        default:
            break;
        }
    }





    return 0;
}




