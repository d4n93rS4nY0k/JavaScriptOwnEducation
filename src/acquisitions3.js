import Chart from 'chart.js/auto'

(async function() {
  const data = {
    labels: [
      'Parameter1',
      'Parameter2',
      'Parameter3',
      'Parameter4',
      'Parameter5',
      'Parameter6',
      'Parameter7'
    ],
    datasets: [{
      label: 'Data',
      data: [65, 59, 90, 81, 56, 55, 40],
      fill: true,
      backgroundColor: 'rgba(255, 99, 132, 0.2)',
      borderColor: 'rgb(255, 99, 132)',
      pointBackgroundColor: 'rgb(255, 99, 132)',
      pointBorderColor: '#fff',
      pointHoverBackgroundColor: '#fff',
      pointHoverBorderColor: 'rgb(255, 99, 132)'
    }, {
      label: 'Data2',
      data: [28, 48, 40, 19, 96, 27, 100],
      fill: true,
      backgroundColor: 'rgba(54, 162, 235, 0.2)',
      borderColor: 'rgb(54, 162, 235)',
      pointBackgroundColor: 'rgb(54, 162, 235)',
      pointBorderColor: '#fff',
      pointHoverBackgroundColor: '#fff',
      pointHoverBorderColor: 'rgb(54, 162, 235)'
    }]
  };
  
  new Chart(
    document.getElementById('acquisitions3'),
    {
      type: 'radar',
      data: data,
      options: {
    elements: {
      line: {
        borderWidth: 3
      }
    }
  },
    }
  );
})();