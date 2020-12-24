#include "engine.h"
#include <Windows.h>


#define 	SFML_DEFINE_DISCRETE_GPU_PREFERENCE





int main()
{
    HWND hWnd = GetConsoleWindow();		// чтобы не было консоли
    ShowWindow(hWnd, SW_HIDE);



    try
    {
        Engine engine;


        while (engine.getUserMainMenuInput())
        {
            switch (engine.getUserMainMenuInput())
            {
				case static_cast<int>(GameWindows::Exit) :     // Полностью выключить игру
					break;
				case static_cast<int>(GameWindows::MainMenu) :     // Открыть главное меню
					engine.mainMenu();
					break;
				case static_cast<int>(GameWindows::Settings) :      // Открыть настройки
					engine.settings();
					break;
				case static_cast<int>(GameWindows::LevelSelectionMenu) :    // Открыть меню выбора уровня
					engine.levelSelectionMenu();
					break;
				case static_cast<int>(GameWindows::StartLevel) :
					engine.startLevel();
					break;
				default:
					break;
            }
        }

    }
    catch (const char* exception)
    {
        std::string str(exception);
        sf::Window window(sf::VideoMode(600, 1), str);
        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }
        }
    }



    return 0;
}




