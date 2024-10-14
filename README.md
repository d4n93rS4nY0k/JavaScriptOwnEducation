# JavaScriptOwnEducation

- GUI design - task completed in 5 days

- https://www.npmjs.com/package/@jellybrick/ffi-napi

## Testing JS Plotly and Chart.js libraries

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
