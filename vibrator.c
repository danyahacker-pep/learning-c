#include <windows.h>
#include <xinput.h>
#include <stdio.h>

int main() {
    DWORD controllerIndex = 0;    
    XINPUT_STATE state;

    ZeroMemory(&state, sizeof(XINPUT_STATE));
    DWORD result = XInputGetState(controllerIndex, &state);
    
    if (result == ERROR_SUCCESS) {
        int seconds = 0;
        printf("Enter vibration duration (in seconds): ");
        if (scanf("%d", &seconds) != 1 || seconds <= 0) {
            printf("Invalid input.\n");
            return 1;
        }

        printf("Vibrating for %d seconds...\n", seconds);

        XINPUT_VIBRATION vibration;
        ZeroMemory(&vibration, sizeof(XINPUT_VIBRATION));
        
        vibration.wLeftMotorSpeed = 32000;  
        vibration.wRightMotorSpeed = 16000; 

        XInputSetState(controllerIndex, &vibration);

        Sleep(seconds * 1000);

        vibration.wLeftMotorSpeed = 0;
        vibration.wRightMotorSpeed = 0;
        XInputSetState(controllerIndex, &vibration);
        
        printf("Stopped.\n");
    } else {
        printf("Not found.\n");
    }

    return 0;
}
