#include "engine.h"
#include <Windows.h>



#define 	SFML_DEFINE_DISCRETE_GPU_PREFERENCE





int main()
{
    HWND hWnd = GetConsoleWindow();     // Hide console
    ShowWindow(hWnd, SW_HIDE);



    try
    {
        Engine engine;


        while (engine.getUserMainMenuInput())
        {
            switch (engine.getUserMainMenuInput())
            {
				case static_cast<int>(GameWindows::Exit) :     // Turn off the game completely
					break;
				case static_cast<int>(GameWindows::MainMenu) :     // Open main menu
					engine.mainMenu();
					break;
				case static_cast<int>(GameWindows::Settings) :      // Open settings
					engine.settings();
					break;
				case static_cast<int>(GameWindows::LevelSelectionMenu) :    // Open the level selection menu
					engine.levelSelectionMenu();
					break;
				case static_cast<int>(GameWindows::StartLevel) :        // Start selected level
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
        Window window(VideoMode(600, 1), str);
        while (window.isOpen())
        {
            Event event;
            while (window.pollEvent(event))
            {
                if (event.type == Event::Closed)
                    window.close();
            }
        }
    }



    return 0;
}




