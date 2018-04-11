"""Must go into __init__.py in speech_recognition library and change line 924 'speechContext' to 'speechContexts'"""

import speech_recognition as sr
import socket
import threading
import json
import os
import time

r = sr.Recognizer()
m = sr.Microphone()

DEBUG = 1

commands = ["retract",
            "rise",
            "down",
            "left",
            "right",
            "forward",
            "backward",
            "cancel",
            "near", # claw
            "away" # claw
            ]

hints = ["Echo start",  # activation word
        "Echo stop",    # deactivation word
        "retract",
        "rise",
        "down",
        "left",
        "right",
        "forward",
        "backward",
        "cancel",
        "near", # claw
        "away"
        ]

hints.extend(commands)

activated = False

def process_text(text):
    global activated
    words = text.split()
    keep = []
    for idx, word in enumerate(words):
        if word == "Echo":   
            if words[idx+1] == "start":
                activated = True
                print("Voice commands turned ON.")
            elif words[idx+1] == "stop":
                activated = False
                print("Voice commands turned OFF.")

        if activated:
            if word in commands:
                keep.append(word)
    return keep


# See python_ports.py from kccla@umich.edu
def send_message(command_value):
    if DEBUG:
        sender = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        sender.connect(("0.0.0.0", 6000))
        #data = json.dumps( {"message_value" : command_value} )
        print("sending " + command_value)
        sender.sendall(command_value)
        sender.close()


try:
    print("A moment of silence, please...")
    with m as source: r.adjust_for_ambient_noise(source)
    print("Set minimum energy threshold to {}".format(r.energy_threshold))
    while True:
        print("Say something!")
        send_message("Recording on")
        with m as source: audio = r.listen(source)
        print("Got it! Now to recognize it...")
        send_message("Recording off")
        try:
            # recognize speech using Google Speech Recognition
            with open("RICS-8b2cdf068357.json", 'r') as json_data:
                cereal = json.dumps(json.load(json_data))
                value = r.recognize_google_cloud(audio, cereal, "en-US", hints)

            send = socket.socket()
            # we need some special handling here to correctly print unicode characters to standard output
            if str is bytes:  # this version of Python uses bytes for strings (Python 2)
                print(u"You said {}".format(value).encode("utf-8"))
            else:  # this version of Python uses unicode for strings (Python 3+)
                print("You said {}".format(value))
            # RICS code
            val = format(value)
            valid = process_text(val)
            print(valid)
            for word in valid:
                send_message(word)
                time.sleep(1)
        except sr.UnknownValueError:
            print("Oops! Didn't catch that")
        except sr.RequestError as e:
            print("Uh oh! Couldn't request results from Google Speech Recognition service; {0}".format(e))
except KeyboardInterrupt:
    pass

