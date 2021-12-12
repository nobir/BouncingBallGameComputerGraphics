# Computer Graphics [Bouncing Ball Game]
## Group Information

1. Nobir Hossain Samuel ([Github](https://github.com/nobir))
2. Md Mohibor Rahman Rahat ([Github](https://github.com/mohibor))
3. Nahian Sajjad ([Github](https://github.com/nahiansajjad))
4. Khuko Moni ([Github](https://github.com/khukomoni))

---

## Resource

1. `Freeglut` [Docs](http://freeglut.sourceforge.net/docs/api.php)

---

## Requirements

1. `MSYS2` ([Link](https://www.msys2.org/#installation))
2. `Freeglut` OpenGL library ([Link](https://packages.msys2.org/package/mingw-w64-x86_64-freeglut?repo=mingw64))
3. Visual Studio Code ([Link](https://code.visualstudio.com/))

---

## Procedure

1. Turn off windowns defender during installation
2. Install properly [MSYS2](https://www.msys2.org/#installation)
   1. After install `MSYS2` open `MSYS2 MSYS` application.
   2. Then update `MSYS2` using below command
      ```bat
      pacman -Syu
      ```
      ```bat
      pacman -Su
      ```
      ```bat
      pacman -Syuu
      ```
    
    **NB:** If it closes itself during the update, restart it and repeat the same command to finish the update.
3. Set the Enviroment Path. default location `C:\msys64\mingw64\bin`
4. After installing `MSYS2` properly then install `mingw` using below command
   ```bat
   pacman -S mingw-w64-x86_64-toolchain
   ```
5. Install `Freeglut` OpenGL using below command
   ```bat
   pacman -S mingw-w64-x86_64-freeglut
   ```
6. Install [C/C++ extension](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools) in Visual Studio Code. Now we can compile C/C++ code in using `F5` for debugging or `Ctrl+F5` for without debugging
7. Add this piece of configuration in `.vscode` folder after removing/replace the original `args` configuration in `task.json` file
    ```json
    "args": [
        "-o",
        "${fileBasenameNoExtension}",
        "${file}",
        "-mwindows",
        "-lwinmm",
        "-lfreeglut",
        "-lopengl32",
        "-lglu32",
        "-Wl,--subsystem,windows",
    ]
    ```

## **N.B:**

1. If any error occurs in any command just restart the application and try again the command which was giving errors
2. If error occurs again and again then try a good vpn. sometimes **MSYS2** server doesn't work 