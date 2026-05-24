#include <iostream>
#include "Library/clsLogin.h"

int main()

{
    while (true)
    {
        if (!clsLoginScreen::ShowLoginScreen())
        {
            break;
        }
        
    }
    
    return 0;
}