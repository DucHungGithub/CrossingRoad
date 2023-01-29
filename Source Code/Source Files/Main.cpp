#include "../Header Files/GameUI.h"


int main() {
    srand(time(0));
    GameUI gameUI;
    Max_Set setting = Max_Set::getmaxset();
    bool active=true;
    do
    {
        gameUI.mainMenuWindow(active,setting);
    } while (active);
    

    return 0;
}