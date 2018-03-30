import os
import threading
import socket
import speech_recognition
import json

# Code for TCP connections taken from my previous EECS 485 project
# Some code for python's speech recognition taken from the speech recognition example
# found at: https://github.com/Uberi/speech_recognition/blob/master/speech_recognition/__main__.py


def listen():
    # Open a socket for a TCP connection listening on port 60001
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.bind(("localhost", 6001))
    s.listen(5)

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
            print(json.loads(all_data))
            handle_requests(master, json.loads(all_data))
        except Exception as e:
            print(e)
            print("invalid json")


# Opens a TCP socket on port 6000, sends the value, closes the connection
def send_message(command_value):

    sender = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sender.connect(("127.0.0.1", 6000))

    data = "testing"

    sender.sendall(str.encode(data))
    sender.close()


def main():
    # Create a new thread to listen for messages - only necessary if we need to receive and data, and I'm not sure if we do
    #t = threading.Thread(target=listen, args=())
    r = speech_recognition.Recognizer()
    m = speech_recognition.Microphone()

    valid_commands = ["robot up", "robot down", "robot left", "robot right", "robot forward", "robot backward"]

    send_message("robot up")
'''
    try:
        while True:
            with m as source: audio = r.listen(source)
            print("Got it! Now to recognize it...")
            try:
                # recognize speech using Google Speech Recognition
                value = r.recognize_google(audio)

                # we need some special handling here to correctly print unicode characters to standard output
                if str is bytes:  # this version of Python uses bytes for strings (Python 2)
                    print(u"You said {}".format(value).encode("utf-8"))
                else:  # this version of Python uses unicode for strings (Python 3+)
                    print("You said {}".format(value))

                # Send messages
                if value in valid_commands:
                    send_message(value)


            except speech_recognition.UnknownValueError:
                print("Oops! Didn't catch that")
            except speech_recognition.RequestError as e:
                print("Uh oh! Couldn't request results from Google Speech Recognition service; {0}".format(e))
    except KeyboardInterrupt:
        pass
'''


if __name__ == '__main__':
    main()