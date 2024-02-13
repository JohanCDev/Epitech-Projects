import './App.css';
import data from './data.json'

function App() {
  const listItem = data.map(info => {
      return (
        <div style={{
          backgroundColor: "#9AB057",
          alignItems: 'center',
          justifyContent: 'center',
          textAlign: 'center',
          borderRadius: 20,
          margin: 20,
          padding: 5
        }}>
          <b>{info.date + ' ' +info.hour}</b>
          <p>{info.description}</p>
          <p>{info.location}</p>
        </div>
      )
  })

  return (
    <div style={{
      backgroundImage: './heures-ouvertures.jpg',
      width: '100%',
      height: '100%',
      overflow: 'scroll'
    }}>
      {listItem}
    </div>
  );
}

export default App;
