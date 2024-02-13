import logo from './logo.svg';
import './App4.css';
import { populationStats } from './population_stats.js';

function App4() {
  return (
    <div className="population-info-container">
      <h2>Population: {populationStats.totalPopulation} personnes</h2>
      <h2>Population par age:</h2>
      <ul>
        {populationStats.agePopulation.map(ageGroup => (
          <li key={ageGroup.age}>
            {ageGroup.age}: {ageGroup.count} habitants
          </li>
        ))}
      </ul>
      <h2>Distribution par sexe:</h2>
      <p>Male: {populationStats.menPopulation} ({(populationStats.menPopulation * 100 / populationStats.totalPopulation).toPrecision(2)}%)</p>
      <p>Female: {populationStats.womenPopulation} ({(populationStats.womenPopulation * 100 / populationStats.totalPopulation).toPrecision(2)}%)</p>
      <h2>Area: {populationStats.area} kilomètres carrés</h2>
      <h2>Density: {populationStats.density} habitants par kilomètre carré</h2>
    </div>
  );
}

export default App4;
