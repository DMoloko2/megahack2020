let socket = new WebSocket("ws://127.0.0.1:8080");

socket.onopen = function(e) {
  alert("[open] Соединение установлено");
};

socket.onmessage = function(event) {
    console.log(event.data);
};

socket.onclose = function(event) {
  if (event.wasClean) {
    alert(`код=${event.code} причина=${event.reason}`);
  } else {
    alert('[close] Соединение прервано');
  }
};

socket.onerror = function(error) {
  alert(`[error] ${error.message}`);
};
