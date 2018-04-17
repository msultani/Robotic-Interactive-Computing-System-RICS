"""Must go into __init__.py in speech_recognition library and change line 924
    'speechContext' to 'speechContexts'
/Library/Frameworks/Python.framework/Versions/3.6/
      lib/python3.6/site-packages/speech_recognition."""
import speech_recognition as sr
import socket
import threading
import json
import os
import time

r = sr.Recognizer()
m = sr.Microphone()

<<<<<<< HEAD
tcp_on = 1  # 1 for release
=======
tcp_on = 1 # 1 for release
>>>>>>> edits to mainwindow and speech.py
            # 0 to use without sending TCP

commands = ["retract",
            "extend",
            "rise",
            "down",
            "left",
            "right",
            "forward",
            "backward",
            "cancel",
            "near", # claw
            "away", # claw
            ]

hints = ["Echo start",  # activation word
        "Echo stop",    # deactivation word
        ]

hints.extend(commands)

activated = False    # False for release
                    # True to skip "Echo start"

def process_text(text):
    global activated
    words = text.split()
    keep = []
    for idx, word in enumerate(words):
        if word == "Echo":
            if words[idx+1] == "start":
                if activated:
                    print("Voice commands are already on.")
                else:
                    activated = True
                    print("Voice commands turned ON.")
                    send_message(str.encode("Activate"))
            elif words[idx+1] == "stop":
                if activated:
                    activated = False
                    print("Voice commands turned OFF.")
                    send_message(str.encode("Deactivate"))
                else:
                    print("Voice commands are already off.")

        if activated and word in commands:
            keep.append(word)
    return keep


def send_message(command_value):
    if tcp_on:
        sender = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        sender.connect(("0.0.0.0", 6000))
        print("sending " + str(command_value))
        sender.sendall(command_value)
        sender.close()


try:
    print("A moment of silence, please...")
    with m as source: r.adjust_for_ambient_noise(source)
    print("Set minimum energy threshold to {}".format(r.energy_threshold))
    while True:
        print("Say something!")
        send_message(str.encode("Recording on"))
        with m as source: audio = r.listen(source)
        print("Got it! Now to recognize it...")
        send_message(str.encode("Recording off"))
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

            # Send entire audio to Qt
            if activated:
                whole_message = "m:" + str(val)
                send_message(str.encode(whole_message))

            valid = process_text(val)
            print(valid)
            for word in valid:
                send_message(str.encode(word))
                time.sleep(1)
        except sr.UnknownValueError:
            print("Oops! Didn't catch that")
            if activated:
                send_message(str.encode("unintelligible_message"))
        except sr.RequestError as e:
            print("Uh oh! Couldn't request results from Google Speech Recognition service; {0}".format(e))
            if activated:
                send_message(str.encode("message_too_long"))
except KeyboardInterrupt:
    pass

