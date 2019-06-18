
import sockets
import os

client_socket=socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client_socket.connect(('107.170.192.50', 2506))
client_socket.recv(4096)
client_socket.send("\r\n")

while True:
    number=client_socket.recv(4096)
    try:
        int(number)
        client_socket.send(number)
    except:
        print(number)

