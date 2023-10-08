#include <windows.h>
#include <stdio.h>

void main() {
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    if (!CreateProcess(NULL, "whoami", NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
        printf("CreateProcess failed (%d).\n", GetLastError());
        return;
    }

    printf("Process id is: %d\n", pi.dwProcessId);

    WaitForSingleObject(pi.hProcess, INFINITE); // wait to kill child process.

    CloseHandle(pi.hProcess); //close opened processes
    CloseHandle(pi.hThread); // close opened thread.
}


// The parameters to CreateProcess are:

// NULL: The application name (in this case, we're not specifying one).
// "whoami": The command to be executed. In this case, it's "whoami", which is a command that tells you the username of the current user.
// NULL: Process security attributes (not used in this case).
// NULL: Thread security attributes (not used in this case).
// FALSE: Inherit handles (child process does not inherit handles).
// 0: Creation flags (no special flags specified).
// NULL: Environment block (inherits environment variables from parent process).
// NULL: Current directory (uses the same as parent process).
// &si: Pointer to the STARTUPINFO structure.
// &pi: Pointer to the PROCESS_INFORMATION structure.