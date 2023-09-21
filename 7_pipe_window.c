#include <windows.h>
#include <stdio.h>
#define MSG_LEN 64

int main()
{
HANDLE hPipe;
DWORD bytesWritten, bytesRead;
char message[MSG_LEN];
char recvd_msg[MSG_LEN];
// Open the named pipe
hPipe = CreateFile("\\\\.\\pipe\\my_pipe", GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);
if (hPipe == INVALID_HANDLE_VALUE)
{
 perror("CreateFile");


}
strncpy(message, "Windows World!! ", MSG_LEN);
WriteFile(hPipe, message, strlen(message) + 1, &bytesWritten, NULL);
strncpy(message, "Understanding ", MSG_LEN);
WriteFile(hPipe, message, strlen(message) + 1, &bytesWritten, NULL);
strncpy(message, "Concepts of ", MSG_LEN);
WriteFile(hPipe, message, strlen(message) + 1, &bytesWritten, NULL);
strncpy(message, "Piping ", MSG_LEN);
WriteFile(hPipe, message, strlen(message) + 1, &bytesWritten, NULL);
// Read the response from the pipe with a timeout of 1 second
bytesRead = 0;
DWORD dwWaitResult = WaitForSingleObject(hPipe, 1000); // Wait for 1 second
if (dwWaitResult == WAIT_OBJECT_0) // If the pipe is readable, read the data
{
 ReadFile(hPipe, &recvd_msg[bytesRead], 1, &bytesRead, NULL);

}
printf("%s\n", recvd_msg);
CloseHandle(hPipe);
return 0;
}
