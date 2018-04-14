import os
import threading
import socket
import speech_recognition
import time


# Opens a TCP socket on port 6000, sends the value, closes the connection
def send_message(command_value):

    sender = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sender.connect(("127.0.0.1", 6000))

    data = command_value

    sender.sendall(str.encode(data))
    sender.close()


def main():


    valid_commands = ["down", "left", "forward", "up", "right", "backward", "stop"]

    send_message("left")
    print("testing")
'''
    for command in valid_commands:
        print("sending command " + str(command))
        send_message(command)
        time.sleep(5)



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