import socketserver
import config
class EchoTCPHandler(socketserver.BaseRequestHandler):

    def handle(self):
        data = self.request.recv(1024).strip()
        self.request.sendall(b'data')
        print('Address:{}'.format(self.client_address[0]))
        print('Data:{}'.format(data.decode()))
        config.write_file(data)

if __name__ == "__main__":
    with socketserver.TCPServer(('172.20.10.4',8888),EchoTCPHandler) as server:
        server.serve_forever()
#global result
#sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
#sock.bind(('',8888))
#sock.listen(7)
#while True:
#    try:
#        client, addr = sock.accept()
#    except KeyboardInterrapt:
#        sock.close()
#        break
#    else:
#        result = client.recv(1024)
#        client.close()
#        print(result.decode('utf-8'))
            #return(result)'''
