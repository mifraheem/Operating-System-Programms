#include <stdio.h>
#include <windows.h>

#define MSG_LEN 64

int main() {
    HANDLE hPipe;
    char message[MSG_LEN];
    char recvd_msg[MSG_LEN];
    DWORD bytesRead;

    // Create a named pipe (server side)
    hPipe = CreateNamedPipe(
        "\\\\.\\pipe\\MyPipe",   // Pipe name
        PIPE_ACCESS_DUPLEX,      // Bidirectional pipe
        PIPE_TYPE_MESSAGE | PIPE_READMODE_MESSAGE | PIPE_WAIT,
        1,                        // Max instances
        MSG_LEN,
        MSG_LEN,
        0,
        NULL
    );

    if (hPipe == INVALID_HANDLE_VALUE) {
        perror("CreateNamedPipe");
        return 1;
    }

    printf("Waiting for client to connect...\n");

    // Wait for a client to connect
    if (ConnectNamedPipe(hPipe, NULL)) {
        printf("Client connected!\n");

        // Read from the pipe
        if (ReadFile(hPipe, recvd_msg, MSG_LEN, &bytesRead, NULL)) {
            printf("Received: %s\n", recvd_msg);
        } else {
            perror("ReadFile");
        }

        // Write to the pipe
        strncpy(message, "Hello from Windows!", MSG_LEN);
        if (WriteFile(hPipe, message, strlen(message) + 1, &bytesRead, NULL)) {
            printf("Sent: %s\n", message);
        } else {
            perror("WriteFile");
        }

        // Close the pipe
        CloseHandle(hPipe);
    } else {
        perror("ConnectNamedPipe");
    }

    return 0;
}
