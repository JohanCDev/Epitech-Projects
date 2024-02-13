import React from 'react';
import ReactDOM from 'react-dom/client';
import './index.css';
import App0 from './App0';
import App1 from './App1';
import App2 from './App2';
import App3 from './App3';
import App4 from './App4';
import reportWebVitals from './reportWebVitals';
import { HashRouter, Route, Routes } from "react-router-dom";

const root = ReactDOM.createRoot(document.getElementById('root'));
root.render(
  <HashRouter>
    <Routes>
      <Route path="/" element={<App0 />} />
      <Route path="/1" element={<App1 />} />
      <Route path="/2" element={<App2 />} />
      <Route path="/3" element={<App3 />} />
      <Route path="/4" element={<App4 />} />
    </Routes>
  </HashRouter>
);

// If you want to start measuring performance in your app, pass a function
// to log results (for example: reportWebVitals(console.log))
// or send to an analytics endpoint. Learn more: https://bit.ly/CRA-vitals
reportWebVitals();
