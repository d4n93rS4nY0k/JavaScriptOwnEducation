# JavaScriptOwnEducation

## Testing JS Plotly and Chart.js libraries

- Chart.js line graph test [ *test.html* ]
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

## Offline Map Proj

Making offline map on JavaScript 
