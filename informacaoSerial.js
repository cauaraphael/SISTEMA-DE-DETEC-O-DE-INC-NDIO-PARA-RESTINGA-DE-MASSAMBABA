function fetchLastRow() {
  fetch('/lastrow')
  .then(response => response.text())
  .then(data => {
    document.getElementById('lastRow').textContent = data;
  });
}
fetchLastRow();
setInterval(fetchLastRow, 5000);
