#include <iostream>

void BSP_blinkHwLight(int button)
{
    // Blinks the HW button with the given number
    std::cout << "Blinking light " << button << std::endl;
}

int BSP_readHwButton()
{
    // Blocks untill the user pushed a button and returns the button that was pushed
    int button = 0;
    std::cout << "Enter button: ";
    std::cin >> button;
    return button;
}