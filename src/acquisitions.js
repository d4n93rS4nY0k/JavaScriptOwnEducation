import Chart from 'chart.js/auto'

(async function() {
  const data = [
    { year: 2030, count: 50 },
    { year: 2031, count: 20 },
    { year: 2032, count: 69 },
    { year: 2033, count: 25 },
    { year: 2034, count: 22 },
    { year: 2035, count: 30 },
    { year: 2036, count: 97 },
  ];

  new Chart(
    document.getElementById('acquisitions'),
    {
      type: 'bar',
      data: {
        labels: data.map(row => row.year),
        datasets: [
          {
            label: 'Column',
            data: data.map(row => row.count)
          }
        ]
      }
    }
  );
})();
