# win32

win32 is the Windows Subsystem for win32.
This directory is mostly for miscellaneous config files.
Config files should be hardlinked with where their respective applications expect to find them.
Anything within the win32 stack may depend on the wsl stack via `C:/Windows/System32/wsl.exe`.

