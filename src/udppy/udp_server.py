import socket

ip = "127.0.0.1"
port = 20001
bufferSize = 1024
msgFromServer = "Hello UDP client\n"
bytesToSend = str.encode(msgFromServer)

# Creating a socket
UDPServerSocket = socket.socket(family=socket.AF_INET, type=socket.SOCK_DGRAM)

# Bind port and ip to socket
UDPServerSocket.bind((ip, port))

# Listen for incoming datagrams
print("UDP server up and listening")
while (True):
    bytesAddressPair = UDPServerSocket.recvfrom(bufferSize)
    message = bytesAddressPair[0]
    address = bytesAddressPair[1]
    print(f"Message from client: {message}")
    print(f"Client IP Address: {address}")

    # Sending a reply to client
    UDPServerSocket.sendto(bytesToSend, address)

# To stop the server press ctrl + c in command line
