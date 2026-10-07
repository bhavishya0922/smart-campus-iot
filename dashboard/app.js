// Simulated telemetry engine for local demonstration without live hardware
let occupancy = 28;
let temp = 24.5;
let hum = 52.0;
let light = 680;

function updateTelemetry() {
  // Add realistic micro-fluctuations
  temp = +(temp + (Math.random() * 0.4 - 0.2)).toFixed(1);
  hum = +(hum + (Math.random() * 0.6 - 0.3)).toFixed(1);
  light = Math.max(200, Math.min(1000, Math.round(light + (Math.random() * 30 - 15))));

  document.getElementById('tempVal').textContent = `${temp} °C`;
  document.getElementById('humVal').textContent = `${hum} %`;
  document.getElementById('occVal').textContent = `${occupancy} Students`;
  document.getElementById('lightVal').textContent = `${light} Lux`;
}

setInterval(updateTelemetry, 2500);

document.getElementById('simToggleBtn').addEventListener('click', () => {
  occupancy = (occupancy === 28) ? 0 : 28;
  const hvac = document.getElementById('hvacStatus');
  const lights = document.getElementById('lightsStatus');

  if (occupancy === 0) {
    hvac.textContent = "ECO STANDBY (Classroom Empty)";
    hvac.style.color = "#94a3b8";
    lights.textContent = "LIGHTS OFF (Energy Saved)";
    lights.style.color = "#94a3b8";
  } else {
    hvac.textContent = "AUTOMATED ACTIVE (24°C)";
    hvac.style.color = "#10b981";
    lights.textContent = "DIMMED (Natural Sunlight > 500 Lux)";
    lights.style.color = "#10b981";
  }
  updateTelemetry();
});
