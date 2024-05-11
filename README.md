# PCIe-CFG-Fetcher

## Overview
This project demonstrates a manually mapped kernel-mode driver for Windows that reads PCI configuration space, specifically targeting a PCI device to read 256 bytes of configuration data.

## Prerequisites
- Windows 10 or higher
- Visual Studio 2019 or later with Windows Driver Kit (WDK)

## Building the Project
1. **Setup Environment**: Install Visual Studio and the Windows Driver Kit.
2. **Open Project**: Open the solution file in Visual Studio.
3. **Build Solution**: From the 'Build' menu, select 'Build Solution'.

## Loading the Driver
Use a custom loader such as `kdmapper` to inject this driver into the kernel:
```bash
kdmapper.exe custom_driver.sys
```

