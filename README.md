# Robotic-Interactive-Computing-System-RICS-
Senior Capstone project with EECS 498 Section 9 at the University of Michigan -- Ann Arbor

The purpose of this project is to create a program to control an Arduino-powered MeArm to assist our client with certain everyday tasks. The arm is controllable through both a desktop and a voice application. The desktop app was developed using the Qt software. The basis for the voice application is the open-source [SpeechRegonition program](https://github.com/Uberi/speech_recognition), which is routed through the Google Cloud Speech API.

The most recent code is currently located on the "voice" branch. 

Please navigate to branch "voice". Run "RICSapp.app" in the "RICS_Beta" directory to launch the GUI application. Run "python3 speech_recognition/speech_recognition/__main__.py" to run the voice application. Speak a command listed below to move the arm as desired.
[
            "retrieve",
            "up",
            "down",
            "left",
            "right",
            "forward",
            "backward",
            "stop",
            "open", # claw
            "close" # claw
]

Arduino code is found in the "RICS_Arduino" directory.
