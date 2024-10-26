# JavaScriptOwnEducation

## ELECTRON PACKAGING

Использовать Electron Packager или Electron Builder:

- Electron Packager: можно упаковать с помощью electron-packager. Например:

```python
electron-packager . MyApp --platform=win32 --arch=x64 --out=dist --overwrite
```

## How to export DLLs from Visual Studio 2022

1. Open Visual Studio 2022 and create a new project:
- Go to File → New → Project.
- In the Create a new project dialog box, select the `Dynamic-Link Library (DLL)` template for C++ and click Next.
- Name the project MyLibrary, select a path to save it, and click Create.
2. Create a header file:
- In Solution Explorer, right-click the Header Files folder → Add → New Item.
- Select Header File (.h) and name the file `my_library.h`.
3. Add the code to the `my_library.h` header file:
```python
#pragma once

extern "C" {
    __declspec(dllexport) int add(int a, int b);
    __declspec(dllexport) void printMessage(const char* message);
}
```
This file defines the exported add and printMessage functions.

4. Add the implementation to the .cpp file:
- Open the `MyLibrary.cpp` file and replace its contents with the following code:

```python
#include "my_library.h"
#include <iostream>

int add(int a, int b) {
    return a + b;
}

void printMessage(const char* message) {
    std::cout << message << std::endl;
}
```

5. Compile the project:

- Click Build → Build Solution (or Ctrl+Shift+B).

- The DLL will be created in the Debug or Release folder, depending on the configuration.

- The path to the file will be something like this:

```python
<путь_к_проекту>\x64\Debug\MyLibrary.dll
```

Command to test .dll files on export functions `dumpbin /EXPORTS MyLibrary.dll`

Needed output functions name like this:

```python
ordinal hint RVA      name
      1    0 00001000 add
      2    1 00001010 printMessage
```

## Testing JS Plotly and Chart.js libraries

### How to install Plotly.js

Download the Plotly.js library file:

- Go to the official Plotly.js GitHub site: Plotly.js releases.
Find the latest version (or the version you need) and download the plotly-latest.min.js file or another available minified version, such as plotly.min.js.

- Save the file in your project:

- Place the downloaded file in a project folder, such as ./libs/plotly.min.js.

Plug Plotly.js locally into the HTML:

Replace the link to the CDN with the path to the local file, for example:

```html
<script src=“./libs/plotly.min.js”></script>
```
Use the library as usual:

Once the local version is connected, Plotly.js will work the same as when connected via CDN.



### Chart.js line graph test [ *test.html* ]
  
  ```html
  <div>
    <canvas id="myChart"></canvas>
  </div>
  <style>

  </style>

  <script src="https://cdn.jsdelivr.net/npm/chart.js"></script>
  
  <script>
    const ctx = document.getElementById('myChart');
  
    new Chart(ctx, {
      type: 'line',
      data: {
        labels: ['Dogs', 'Cats', 'Birds', 'Whales', 'Ships', 'Pigs'],
        datasets: [{
          label: '# of Votes',
          data: [12, 19, 3, 5, 2, 3],
          borderWidth: 1
        }]
      },
      options: {
        scales: {
          y: {
            beginAtZero: true
          }
        }
      }
    });
  </script>
  ```
[![image.png](https://i.postimg.cc/XNr82gp3/image.png)](https://postimg.cc/QVr1C1Qn)

### Another example of Chart.js usage

Open in folder `src` - **index.html**, **acquisitions**, **acquisitions2**, **acquisitions3**  

[![image.png](https://i.postimg.cc/Gm1L9zZj/image.png)](https://postimg.cc/WhXLHmpD)

## Online & Offline Map

### Online Map

- Making online map on `JavaScript & HTML5` using `OpenStreetMap`. See and open `onlinemap.html` file.
  Required `Leaflet` library
  
``` html
<!DOCTYPE html>
<meta charset="utf-8">

<!-- Load Leaflet -->
<link rel="stylesheet" href="https://unpkg.com/leaflet@1.3.4/dist/leaflet.css" integrity="sha512-puBpdR0798OZvTTbP4A8Ix/l+A4dHDD0DGqYW6RQ+9jxkRFclaxxQb/SJAWZfWAkuyeQUytO7+7N4QKrDh+drA==" crossorigin=""/>
<script src="https://unpkg.com/leaflet@1.3.4/dist/leaflet.js" integrity="sha512-nMMmRyTVoLYqjP9hrbed9S+FzjZHW5gY1TWCHA5ckwXZBadntCNs8kEqAWdrb9O7rxbCaA4lKTIWjDXZxflOcA==" crossorigin=""></script>

<div id="mapid"></div>

<style>
#mapid { height: 1024px; }
</style>

<script>

    var mymap = L
      .map('mapid')
      .setView([50, -0.1], 4);
    
    L.tileLayer(
        'https://{s}.tile.openstreetmap.org/{z}/{x}/{y}.png', {
        attribution: ' ',
        maxZoom: 20,
        }).addTo(mymap);
    </script>
```
Here is what you will see in final result:

[![image.png](https://i.postimg.cc/0j0ZgDBx/image.png)](https://postimg.cc/PvN1YpHF)

### Offline map

Offline map looks the same as online but with downloaded tiles (folder `Tiles`).

[![image.png](https://i.postimg.cc/MGyp1cbF/image.png)](https://postimg.cc/Y4C7HCP6)

## Compile HTML file to .exe

To compile an HTML file into an .exe, I was able to find two working methods.

- Using **Nativefier Tool** [See and Download Nativefier Tool](https://github.com/nativefier/nativefier). 
Follow the instructions for installing Nativefier.

- Using **HTML Compiler**. Download HTML Compiler in folder `HTMLtoEXE`

## Advanced Offline Map / Engineering GUI

In advanced Offline map I have added background, functional buttons and input forms.

[![image.png](https://i.postimg.cc/vT93m6wG/image.png)](https://postimg.cc/q6J8bq7F)

Made a pretty design when hovering the cursor over the button:

[![image.png](https://i.postimg.cc/bJqYN9fk/image.png)](https://postimg.cc/KKsh0Lz8)

Learning how to connect DLL libraries via Node.js

Huge disadvantage of `FFi` library - supported version only **Node.js 11** and lower.

## Electron framework


Electron initialization:

https://habr.com/ru/companies/ruvds/articles/436466/

##How to export .dll DUMB METHOD

Generate .dll from .cpp  `gcc -shared -o myLib.so main.c`

Generate .dll from .cpp  `gcc -shared -o hello.dll hello.cpp`

