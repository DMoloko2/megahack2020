import socket

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock.connect(('172.20.10.4',8888))
sock.send(b'pressure_0')
sock.close()
