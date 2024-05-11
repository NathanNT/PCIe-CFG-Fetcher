#include <ntddk.h>
#include <wdm.h>

NTSTATUS CustomDriverEntry(
    _In_ PDRIVER_OBJECT  kdmapperParam1,
    _In_ PUNICODE_STRING kdmapperParam2
)
{
    UNREFERENCED_PARAMETER(kdmapperParam1);
    UNREFERENCED_PARAMETER(kdmapperParam2);

    DbgPrintEx(0, 0, "Custom Driver Loaded\n");

    ULONG bus = 0;
    ULONG device = 2;
    ULONG function = 0;
    PCI_SLOT_NUMBER slotNumber = {};
    slotNumber.u.bits.DeviceNumber = device;
    slotNumber.u.bits.FunctionNumber = function;

    ULONG bytesRead = 0;
    UCHAR buffer[256] = { 0 }; // Buffer to store PCI config data

    // Reading 256 bytes from PCI configuration space
    bytesRead = HalGetBusDataByOffset(
        PCIConfiguration,         // Type of data to read
        bus,                      // Bus number
        slotNumber.u.AsULONG,     // Encoded device and function number
        buffer,                   // Buffer to store the data
        0,                        // Offset into the PCI configuration space
        256                       // Amount of data to read
    );

    if (bytesRead != 256) {
        DbgPrintEx(0, 0, "Failed to read PCI config\n");
    }
    else {
        for (int i = 0; i < 256; i += 4) {
            ULONG data = *(ULONG*)(buffer + i);
            DbgPrintEx(0, 0, "Data at %d = %08X\n", i, data);
        }
    }

    return STATUS_SUCCESS;
}
