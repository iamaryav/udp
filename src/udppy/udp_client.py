import socket

message = "Hi UDP server \n"
bytesToSend = str.encode(message)
serverAddressPort = ("127.0.0.1", 20001)
bufferSize = 1024

# UDP Socket at the client side
UDPClientSocket = socket.socket(family=socket.AF_INET, type=socket.SOCK_DGRAM)


# Send data to UDP server
UDPClientSocket.sendto(bytesToSend, serverAddressPort)

# Recieve message from server
msgFromServer = UDPClientSocket.recvfrom(bufferSize)
print(f"Message from Server: {msgFromServer[0]}")
