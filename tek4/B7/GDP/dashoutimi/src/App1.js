import React, { useState } from 'react';
import axios from 'axios';

const WeatherApp = () => {
  const [weatherData, setWeatherData] = useState(null);

  const apiKey = '5c6c50a2128640b6bfb194857232111';

  const fetchWeather = async () => {
    try {
      const response = await axios.get(`https://api.weatherapi.com/v1/current.json?key=${apiKey}&q=chicoutimi&lang=fr`);
      setWeatherData(response.data);
      console.log(response.data);
    } catch (error) {
      console.error("Erreur lors de la récupération des données météo", error);
    }
  };

  React.useEffect(() => {
    fetchWeather();
  }, []);

  return (
    <div style={{
      width: '100%',
      height: '100%'
    }}>
      {weatherData && (
        <div style={{
          display: 'flex',
          flexDirection: 'column',
          alignItems: 'center',
          height: '100%',
          justifyContent: 'center'
        }}>
          <img
            style={{
              maxHeight: '100%',
              width: '100%',
              maxHeight: '100vh',
              overflow: 'hidden'
            }}
            src="https://images.unsplash.com/photo-1483921020237-2ff51e8e4b22?q=80&w=2970&auto=format&fit=crop&ixlib=rb-4.0.3&ixid=M3wxMjA3fDB8MHxwaG90by1wYWdlfHx8fGVufDB8fHx8fA%3D%3D" />
          <div style={{
            position: 'absolute',
            height: '250px',
            width: '250px',
            display: 'flex',
            flexDirection: 'column',
            justifyContent: 'center',
            alignItems: 'center',
            borderRadius: '10%',
            backgroundColor: '#825ec4',
            color: 'white',
            zIndex: '10'
          }}>
            <h3>Météo à {weatherData.location.name}</h3>
            <p>Température: {weatherData.current.temp_c} °C</p>
            <p>Condition: {weatherData.current.condition.text}</p>
          </div>
        </div>
      )}
    </div>
  );
};

export default WeatherApp;
