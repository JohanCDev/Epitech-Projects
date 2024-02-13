import React, { useState } from 'react';
import "./App.css";

import App1 from "./App1";
import App2 from "./App2";
import App3 from "./App3";
import App4 from "./App4";

const WeatherApp = () => {

  return (
    <div className={"quarter-grid-container"}>
      <div className={"grid-item"} onClick={() => { window.location.href = "/#/1" }}><App1 /></div>
      <div className={"grid-item"} onClick={() => { window.location.href = "/#/2" }}><App2 /></div>
      <div className={"grid-item"} onClick={() => { window.location.href = "/#/3" }}><App3 /></div>
      <div className={"grid-item"} onClick={() => { window.location.href = "/#/4" }}><App4 /></div>
    </div>
  );
};

export default WeatherApp;
