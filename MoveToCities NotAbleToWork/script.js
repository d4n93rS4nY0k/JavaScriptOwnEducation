import { getMap } from './map.js'

// получаем контейнер для городов
const $cities = document.getElementById('cities')

;(async () => {
  // получаем объект с городами
  const response = await fetch('./db/cities.json')
  const cities = await response.json()
  // перебираем города
  for (const city in cities) {
    // создаем кнопку
    const $button = document.createElement('button')

    // текстовое содержимое кнопки - название города
    $button.textContent = city

    // получаем широту и долготу
    const { lat, lon } = cities[city]

    // записываем название города, широту и долготу
    // в соответствующие data-атрибуты
    $button.dataset.city = city
    $button.dataset.lat = lat
    $button.dataset.lon = lon

    // добавляем кнопку в контейнер
    $cities.append($button)
  }
})()

// обрабатываем нажатие кнопки
$cities.addEventListener('click', ({ target }) => {
  // нас интересует только нажатие кнопки
  if (target.tagName !== 'BUTTON') return

  // получаем название города, широту и долготу из data-атрибутов
  const { city, lat, lon } = target.dataset
  const position = [lat, lon]
  // вызываем функцию, передавая ей позицию и название города
  getMap(position, city)
})