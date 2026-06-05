#include <windows.h>
#include <xinput.h>
#include <stdio.h>

int main() {
    DWORD controllerIndex = -1;
    XINPUT_STATE state;

    for (DWORD i = 0; i < 4; i++) {
        ZeroMemory(&state, sizeof(XINPUT_STATE));
        if (XInputGetState(i, &state) == ERROR_SUCCESS) {
            controllerIndex = i;
            break;
        }
    }
    
    if (controllerIndex != -1) {
        int seconds = 0;
        printf("Connected on index %lu. Enter duration (in seconds): ", controllerIndex);
        if (scanf("%d", &seconds) != 1 || seconds <= 0) {
            printf("Invalid input.\n");
            system("pause");
            return 1;
        }

        printf("Vibrating...\n");

        XINPUT_VIBRATION vibration;
        ZeroMemory(&vibration, sizeof(XINPUT_VIBRATION));
        
        vibration.wLeftMotorSpeed = 40000;  
        vibration.wRightMotorSpeed = 25000; 

        XInputSetState(controllerIndex, &vibration);

        Sleep(seconds * 1000);

        vibration.wLeftMotorSpeed = 0;
        vibration.wRightMotorSpeed = 0;
        XInputSetState(controllerIndex, &vibration);
        
        printf("Stopped.\n");
    } else {
        printf("No gamepads found in slots 0-3. Check connection!\n");
    }

    // Вот эта строчка не даст окну закрыться самой:
    system("pause");
    return 0;
}
