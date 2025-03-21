#include <iostream>
#include <Windows.h>
#include <thread>


void TrackMousePosition()
{
    POINT p;
    while (true)
    {
        // Get the current mouse position
        if (GetCursorPos(&p))
        {
            // Move the cursor to the top left corner of the console
            std::cout << "Mouse Position: X = " << p.x << ", Y = " << p.y << std::endl;
        }
        else
        {
            std::cout << "Failed to get mouse position" << std::flush;
        }
    }
}

int main()
{
    std::thread mouseThread(TrackMousePosition);

    // Keep the main thread running so the mouse position can be tracked
    std::cin.get();

    // Join the thread before exiting
    mouseThread.join();

    return 0;
}
