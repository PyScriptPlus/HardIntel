#include "operating.h"

int main() {

    PRINT("Coded By MamaD");

    printf("==========================================================\n");

    operating();

    // Graphic: 
    DISPLAY_DEVICE displayDevice;
    ZeroMemory(&displayDevice, sizeof(displayDevice));
    displayDevice.cb = sizeof(displayDevice);
    EnumDisplayDevices(NULL, 0, &displayDevice, 0);
    printf("%s\n", displayDevice.DeviceString);

    // CPU: 
    int cpuInfo[4] = {0};
    char cpuBrandString[0x40] = {0};

    __cpuid(cpuInfo, 0x80000002);
    memcpy(cpuBrandString, cpuInfo, sizeof(cpuInfo));

    __cpuid(cpuInfo, 0x80000003);
    memcpy(cpuBrandString + 16, cpuInfo, sizeof(cpuInfo));

    __cpuid(cpuInfo, 0x80000004);
    memcpy(cpuBrandString + 32, cpuInfo, sizeof(cpuInfo));

    printf("CPU Model: %s\n", cpuBrandString);

    // Number of Core:
    SYSTEM_INFO core;
    GetSystemInfo(&core);
    printf("The number of cores in your CPU: %d\n", core.dwNumberOfProcessors);
    

    // RAM:
    MEMORYSTATUSEX memInfo;
    memInfo.dwLength = sizeof(MEMORYSTATUSEX);

    if (GlobalMemoryStatusEx(&memInfo)) {
        DWORDLONG totalPhysMem = memInfo.ullTotalPhys;
        printf("Total RAM: %.2f GB\n", (double)totalPhysMem / (1024 * 1024 * 1024));
    } else {
        printf("Failed to get memory info.\n");
    }


    system("pause");

    return 0;
}
