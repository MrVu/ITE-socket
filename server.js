var express = require('express');
var app = express();
var server = require('http').createServer(app);
var io = require('socket.io')(server);

var light = {state: false};

app.use(express.static(__dirname + '/node_modules'));
app.get('/', function (req, res, next) {
  res.sendFile(__dirname + '/index.html');
});

io.on('connection', function (client) {
  console.log('Client connected...');

  client.on('join', function (data) {
    console.log(data);
  });

  io.sockets.emit('led', light);
  client.on('toggle', function(state) {
    light.state = !light.state;
    console.log('id: ' + client.id + 'light: ' + light.state);
    io.sockets.emit('led', light);
  });

  client.on('moveRight', function() {
    io.sockets.emit('moveRight', 'command move right from server')
  })

  client.on('moveLeft', function () {
    io.sockets.emit('moveLeft', 'MOVE LEFT')
  })
  client.on('moveUp', function() {
    io.sockets.emit('moveUp', 'command move up from server')
  })
  client.on('moveDown', function() {
    io.sockets.emit('moveDown', 'command move down from server')
  })
  client.on('turnLeft', function() {
    io.sockets.emit('turnLeft', 'command turn left from server')
  })
  client.on('turnRight', function() {
    io.sockets.emit('turnRight', 'command turn right from server')
  })
  client.on('faceUp', function() {
    io.sockets.emit('faceUp', 'command faceUp from server')
  })
  
  client.on('disconnect', function () {
    console.log('Client disconnected!');
  });
});

server.listen(4200, '0.0.0.0', () => {
  console.log('Server is up and running on port 4200')
});
