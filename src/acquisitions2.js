import Chart from 'chart.js/auto'

(async function() {
    const data = [
        { year: 2024, count: 10 },
        { year: 2025, count: 20 },
        { year: 2026, count: 15 },
        { year: 2027, count: 25 },
        { year: 2028, count: 22 },
        { year: 2029, count: 30 },
        { year: 2030, count: 28 },
      ];
  
  new Chart(
    document.getElementById('acquisitions2'),
    {
      type: 'line',
      data: {
        labels: data.map(row => row.year),
        datasets: [
          {
            label: 'Linear',
            data: data.map(row => row.count)
          }
        ]
      }
      
    }
  );
})();