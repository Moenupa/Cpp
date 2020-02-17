WM's C++ folder to sync C++ programs

Aiming to help code development between multiple devices
some env-settings of the launch.json in vscode:
    mingw-w64
    x86_64
    8.1.0
    win32
    seh
.cpp files will be compiled into a folder for formatting and keeping the cpp dir clean
the exe output dir is directly under cpp, namely dir cpp\exe

launch.json and tasks.json are specially adjusted to output .exe files in this way.