## VSCode e C++
### Windows (MSVC)
Primeiramente é necessário instalar o Visual Studio com as ferramentas de desenvolvimento pra C++.

Depois deve se iniciar o VSCode pela ferramenta 'Developer Command Prompt for VS 20XX', digitando:
```
code
```

Na raiz do projeto deve ser criada uma pasta chamada```.vscode``` com os seguintes arquivos: ```c_cpp_properties.json```; ```launch.json```; ```settings.json```; ```tasks.json```.

Cole o seguinte conteúdo em cada arquivo:
> c_cpp_properties.json
```json
{
    "configurations": [
        {
            "name": "Win32",
            "includePath": [
                "${workspaceFolder}/**"
            ],
            "defines": [
                "_DEBUG",
                "UNICODE",
                "_UNICODE"
            ],
            "windowsSdkVersion": "10.0.19041.0",
            "compilerPath": "C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Tools\\MSVC\\14.30.30705\\bin\\Hostx64\\x64\\cl.exe",
            "cStandard": "c17",
            "cppStandard": "c++17",
            "intelliSenseMode": "windows-msvc-x64"
        }
    ],
    "version": 4
}
```
> launch.json
```json
{
    // Use IntelliSense to learn about possible attributes.
    // Hover to view descriptions of existing attributes.
    // For more information, visit: https://go.microsoft.com/fwlink/?linkid=830387
    "version": "0.2.0",
    "configurations": [
        {
            "name": "Compilar C++ usando o MSVC",
            "type": "cppvsdbg",
            "request": "launch",
            "program": "${fileDirname}\\build\\${fileBasenameNoExtension}.exe",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${fileDirname}\\build",
            "environment": [],
            "console": "externalTerminal",
            "preLaunchTask": "C/C++: cl.exe arquivo de build ativo"
        }
    ]
}
```
> settings.json
```json
{
    "files.associations": {
        "atomic": "cpp",
        "bit": "cpp",
        "cctype": "cpp",
        "clocale": "cpp",
        "cmath": "cpp",
        "compare": "cpp",
        "concepts": "cpp",
        "cstddef": "cpp",
        "cstdint": "cpp",
        "cstdio": "cpp",
        "cstdlib": "cpp",
        "cstring": "cpp",
        "ctime": "cpp",
        "cwchar": "cpp",
        "exception": "cpp",
        "initializer_list": "cpp",
        "iomanip": "cpp",
        "ios": "cpp",
        "iosfwd": "cpp",
        "iostream": "cpp",
        "istream": "cpp",
        "iterator": "cpp",
        "limits": "cpp",
        "memory": "cpp",
        "new": "cpp",
        "ostream": "cpp",
        "stdexcept": "cpp",
        "streambuf": "cpp",
        "string": "cpp",
        "system_error": "cpp",
        "tuple": "cpp",
        "type_traits": "cpp",
        "typeinfo": "cpp",
        "utility": "cpp",
        "vector": "cpp",
        "xfacet": "cpp",
        "xiosbase": "cpp",
        "xlocale": "cpp",
        "xlocinfo": "cpp",
        "xlocmon": "cpp",
        "xlocnum": "cpp",
        "xloctime": "cpp",
        "xmemory": "cpp",
        "xstddef": "cpp",
        "xstring": "cpp",
        "xtr1common": "cpp",
        "xutility": "cpp"
    }
}
```
> tasks.json
```json
{
	"version": "2.0.0",
	"tasks": [
		{
			"label": "Create a folder to contain build files",
			"type": "shell",
			"options": {
				"cwd": "${fileDirname}"
			},
			"windows": {
				"command": "cmd /C if not exist .\\build mkdir .\\build"
			}
		},
		{
			"dependsOn": "Create a folder to contain build files",
			"type": "cppbuild",
			"label": "Compilar C++ usando o MSVC",
			"command": "cl.exe",
			"args": [
				"/Zi",
				"/EHsc",
				"/nologo",
				"/Fe:",
				"${fileDirname}\\build\\${fileBasenameNoExtension}.exe",
				"${fileDirname}\\*.cpp",
				"-Wall",
				"-std=c++17"
			],
			"options": {
				"cwd": "${fileDirname}\\build"
			},
			"problemMatcher": [
				"$msCompile"
			],
			"group": {
				"kind": "build",
				"isDefault": true
			},
			"detail": "compilador: cl.exe"
		}
	]
}
```
Após, no VSCode vá em **Terminal** > **Configure Default Build Task** e selecione **Compilar C++ usando o MSVC**.
Obs.: É sempre necessário iniciar o VSCode pelo ferramenta do Visual Studio.

#### Testando
Pelo VSCode crie uma pasta com o nome do seu projeto e em seguida crie um arquivo chamado ```main.cpp``` e cole o seguinte conteúdo:
```c++
#include <iostream>

int main() {
    std::cout << "Hello World!" << std::endl;
    return 0;
}
```
Após, no VSCode vá em **Terminal** > **Run Build Task**. Verifique se foi criada uma pasta build dentro da pasta do projeto e se ela contem arquivos.

Finalmente vá no arquivo ```main.cpp``` e então em **Run** > **Start Debugging**, e você devera ver a seguinte saída:
```
Hello World!
```
