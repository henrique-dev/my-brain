## VSCode e C++
### Windows (MSVC)
#### Pré requisitos
- Instalar o [Visual Studio Code](https://code.visualstudio.com/download)
- Instalar o [C/C++ extension for VS Code](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools)
- Instalar o Microsoft Visual C++ (MSVC) compiler toolset
![teste](/ambiente/imagens/1.png)

#### Integração
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
      "name": "Compile C++ using MSVC",
      "type": "cppvsdbg",
      "request": "launch",
      "program": "${workspaceFolder}\\build\\${fileBasenameNoExtension}.exe",
      "args": [],
      "stopAtEntry": false,
      "cwd": "${workspaceFolder}\\build",
      "environment": [],
      "console": "externalTerminal",
      "preLaunchTask": "Compile C++ using MSVC"
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
			"label": "Clear the folder that contain build files",
			"type": "shell",
			"options": {
				"cwd": "${workspaceFolder}"
			},
			"windows": {
				"command": "cmd /C if exist .\\build del /q .\\build\\*"
			}
		},
		{
      "dependsOn": "Clear the folder that contain build files",
			"label": "Create a folder to contain build files",
			"type": "shell",
			"options": {
				"cwd": "${workspaceFolder}"
			},
			"windows": {
				"command": "cmd /C if not exist .\\build mkdir .\\build"
			}
		},
		{
			"dependsOn": "Create a folder to contain build files",
			"type": "cppbuild",
			"label": "Compile C++ using MSVC",
			"command": "cl.exe",
			"args": [
				"/Zi",
				"/EHsc",
				"/nologo",
				"/Fe:",
				"${workspaceFolder}\\build\\${fileBasenameNoExtension}.exe",
				"${fileDirname}\\*.cpp",
				"-Wall"
			],
			"options": {
				"cwd": "${workspaceFolder}\\build"
			},
			"problemMatcher": [
				"$msCompile"
			],
			"group": {
				"kind": "build",
				"isDefault": true
			},
			"detail": "compiler: cl.exe"
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

## VSCode e Unreal
### Windows (MSVC)
#### Pré requisitos
- Unreal Engine 4

#### Integração
No Unreal Engine vá em **Edit** > **Editor Preferences**. Depois, no lado esquerdo vá em **Source Code**.

Depois selecione o **Visual Studio Code** no dropdown.
![teste](/ambiente/imagens/2.png)

Quando fizer isso, vai aparecer uma mensagem que será necessário reiniciar o Unreal Engine. Clique em reiniciar.

Depois pode se ir em **File** > **Generate Visual Studio Code Project**.

E finalmente em **File** > **Open Visual Studio Code**.

Para corrigir problemas associados ao intellisence que podem aparecer dependendo da versão Unreal usada, é necessário instalar uma extensão ao VSCode. Ela pode ser obtida no seguinte [link](https://gist.github.com/boocs/f63a4878156295b6e854cac68672f305#installation).

Depois vá em **File** > **Preferences** > **Settings**. No campo de busca digite **ue intellisence**, e então marque as duas caixas relacionadas a esta configuração. Finalmente feche o VSCode e abra ele novamente.
