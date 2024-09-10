let map = null
let marker = null

export function getMap(position, tooltip) {
  if (map === null) {
    map = L.map('map').setView(position, 15)
  } else {
    // перемещение к следующей позиции
    map.flyTo(position)
  }

  L.tileLayer('https://{s}.tile.openstreetmap.org/{z}/{x}/{y}.png', {
    attribution:
      '© <a href="https://www.openstreetmap.org/copyright">OpenStreetMap</a> contributors'
  }).addTo(map)

  // удаление предыдущего маркера
  if (marker) {
    map.removeLayer(marker)
  }
  marker = new L.Marker(position).addTo(map).bindPopup(tooltip).openPopup()
}