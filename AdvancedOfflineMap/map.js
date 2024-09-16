          // Создание карты
          var map = L.map('map').setView([51.710298, 46.748233], 11); 

          // Загрузка карты
          L.tileLayer('Tiles/{z}/{x}/{y}.png', {
              maxZoom: 17,
              tileSize: 256,
              zoomOffset: 0,
          }).addTo(map);

          // Зеленый круговой маркер
          L.circleMarker(L.latLng(51.52, -0.109), {
              radius: 10,
              fillColor: '#27ae60',
              fillOpacity: 1,
              color: '#fff',
              weight: 3,
          }).addTo(map);

          // Маркер галочки и пунктирная линия
          var marker2 = L.marker([55.431150, 37.544978]).addTo(map)
          marker2.bindPopup("Best city")
          var marker3 = L.marker([60.368, 70.38]).addTo(map)
          
          var line = L.polyline([marker2.getLatLng(), marker3.getLatLng()], {color: 'red', weight: 1, dashArray: '5, 5', dashOffset: '0'}).addTo(map);
