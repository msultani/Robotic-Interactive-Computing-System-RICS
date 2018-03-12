import os
import threading
import socket
import speech_recognition
import json


def handle_requests(data):
	print(data)

def main():
	# Open a socket for a TCP connection
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.bind(("0.0.0.0", 6000))
    s.listen(5)
    print("Listening")


    while True:
        clientsocket, address = s.accept()
        max_data = 1024
        all_data = ""

        while True:
            message = clientsocket.recv(max_data)
            all_data += message.decode("utf-8")

            if len(message) != max_data:
                break

        clientsocket.close()
        try:
            #print(json.loads(all_data))
            handle_requests(json.loads(all_data))
        except Exception as e:
            print(e)
            print("invalid json")


if __name__ == '__main__':
    main()