import speech_recognition as sr
import socket
import threading
import json
import os

r = sr.Recognizer()
m = sr.Microphone()

commands = ["wake",
            "fetch",
            "up", # move? 
            "down", # move?
            "left", # move?
            "right", # move?
            "forward", # move?
            "backward" # move?
            ]


def process_text(text):
    words = text.split()
    keep = []
    for word, num in enumerate(words):
        if word is "move":
            if words[num+1] in commands:
                keep.append(word)
        elif word is "wake" or word is "fetch":
            keep.append(word)
    return keep


# See python_ports.py from kccla@umich.edu
def send_message(command_value):
    sender = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sender.connect(("0.0.0.0", 6000))
    data = json.dumps( {"message_value" : command_value} )

    sender.sendall(str.encode(data))
    sender.close()



try:
    print("A moment of silence, please...")
    with m as source: r.adjust_for_ambient_noise(source)
    print("Set minimum energy threshold to {}".format(r.energy_threshold))
    while True:
        print("Say something!")
        with m as source: audio = r.listen(source)
        print("Got it! Now to recognize it...")
        try:
            with open("RICS-1cde6e998337.json") as json_data:
                d = json.load(json_data)
                # print(d)
                # recognize speech using Google Speech Recognition
                value = r.recognize_google_cloud(audio, credentials_json=json.dumps(d), language="en-US", preferred_phrases=commands, show_all=False)

            # TODO RICS: process and send value
            send = socket.socket()
            f = open('words.txt', 'w')
            # we need some special handling here to correctly print unicode characters to standard output
            if str is bytes:  # this version of Python uses bytes for strings (Python 2)
                print(u"You said {}".format(value).encode("utf-8"))
            else:  # this version of Python uses unicode for strings (Python 3+)
                print("You said {}".format(value))
                val = format(value)
                f.write(val)
                valid = process_text(val)
                print(valid)
        except sr.UnknownValueError:
            print("Oops! Didn't catch that")
        except sr.RequestError as e:
            print("Uh oh! Couldn't request results from Google Speech Recognition service; {0}".format(e))
except KeyboardInterrupt:
    pass

