# FingerPrint_Lock_System
This repository contains code and diagram for Fingerprint lock system using Arduino



Activity Link:(practical_video);
https://youtu.be/fDYc6-bksqM




#Things to do before working on this project

1)Dump the Fingerprint Enroll code first and Register the fingerprint using the code (fingerprint enrolls 2 times).

2)Errors:
    -UPLOADING ERROR : Check the cable.Better try to use the standard and the short cable while dumping the code.
    -FINGERPRINT SENSOR NOT DETECTED : Connect the Tx yellow wire to == 2 and Rx wire green wire to == 3 from the fingerprint sensor.
    -FILE NOT FOUND : Install the fingerprint library from this link :    https://github.com/adafruit/Adafruit-Fingerprint-Sensor-Library
				or
    - You can include the library from the library manager in the arduino software.

    -NOTE: Register the fingerprint using the # symbol and type any id number between 1-125 in Serial monitor.

3)After register , Now dump the Fingerprint door lock code to the arduino .

4)connect the circuit same as in the image file.

5)It takes the 3 seconds of delay while to lock the solenoid lock after the successful unlock.



