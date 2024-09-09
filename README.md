# JavaScriptOwnEducation

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

## Online Map 

Making online map on `JavaScript & HTML5` using `OpenStreetMap`. See and open `onlinemap.html` file.

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
