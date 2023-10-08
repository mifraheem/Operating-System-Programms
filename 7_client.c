#include <stdio.h>
#include <windows.h>

#define MSG_LEN 64

int main()
{
    HANDLE hPipe;
    char message[MSG_LEN];
    char recvd_msg[MSG_LEN];
    DWORD bytesRead;

    // Connect to the named pipe (client side)
    hPipe = CreateFile(
        "\\\\.\\pipe\\MyPipe", // Pipe name
        GENERIC_READ | GENERIC_WRITE,
        0,
        NULL,
        OPEN_EXISTING,
        0,
        NULL);

    if (hPipe == INVALID_HANDLE_VALUE)
    {
        perror("CreateFile");
        return 1;
    }

    printf("Connected to the server!\n");

    // Send a message to the server
    strncpy(message, "Hello from the client!", MSG_LEN);
    if (WriteFile(hPipe, message, strlen(message) + 1, &bytesRead, NULL))
    {
        printf("Sent: %s\n", message);
    }
    else
    {
        perror("WriteFile");
    }

    // Read the server's response
    if (ReadFile(hPipe, recvd_msg, MSG_LEN, &bytesRead, NULL))
    {
        printf("Received: %s\n", recvd_msg);
    }
    else
    {
        perror("ReadFile");
    }

    // Close the pipe
    CloseHandle(hPipe);

    return 0;
}
