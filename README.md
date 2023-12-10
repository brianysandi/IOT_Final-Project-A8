# IOT_Final-Project-A8
<hr>

## Introduction to the problem and the solution
<p align="justify">In the rapidly evolving landscape of Internet of Things (IoT) applications, voice interaction has emerged as a compelling interface for user engagement. The integration of Speech-to-Text (STT) technology into IoT projects allows for natural and intuitive communication between users and connected devices. </p>

## Hardware design and implementation details
<p align="justify">To design a speech-to-text system using an ESP32, an INMP441 microphone, and Google Cloud Speech-to-Text API, first we have to do soldering job to assemble the INMP441 pins
. After the soldering job to integrate the INMP441 module with its pin, we have to check our soldering job so that it can do its function properly. We used a multimeter to test whether the module and its pins can conduct electricity with no flaw. Next, we connect the jumper cables to the corresponding pins on the ESP32. 
</p>

## Network Infrastructure
![image](https://github.com/brianysandi/IOT_Final-Project-A8/assets/84609758/89d97ca1-c31b-43e0-9a73-6fda95a0c152)

## Software implementation details 
<p align="justify">The software development phase of the project focuses on integrating speech-to-text functionality using ESP32, INMP441 microphone, and Google Cloud Speech-to-Text API. Key steps include programming ESP32 in Arduino IDE, incorporating necessary libraries (ESP32-Arduino core, INMP441 library, and Google Cloud Speech-to-Text API library), and implementing intricate logic for capturing and formatting audio data. The process involves transmitting data to Google API for processing, managing API authentication, handling text output, and fortifying the codebase with error-handling mechanisms. This approach creates a sophisticated system for audio capture, translation, and seamless interaction with Google's cloud-based speech recognition service, ensuring robust performance under diverse circumstances.</p>

## Test results and performance evaluation
<p align="justify">Example 1 Result: "This is the final project for Internet of Things class. Device will record its sound and write into the serial monitor."</p>

![image](https://github.com/brianysandi/IOT_Final-Project-A8/assets/84609758/a82c32f6-c94e-4a97-8c54-40eb97d90232)

<p align="justify">Example 2 Result: "This test will check how accurate the device is to record our voice based on what we say.""</p>
![image](https://github.com/brianysandi/IOT_Final-Project-A8/assets/84609758/67c36c45-b5b0-4667-8dae-b15e7b64f9a2)
<p align="justify">In Example 1, a total of 4 out of 22 words exhibited inaccuracies in transcription. In Example 2, 3 out of 19 words were not transcribed accurately. It's noteworthy that the inaccuracies primarily occurred in specific technical terms and were influenced by factors such as pronunciation variations and background noise.</p>


## Conclusion and future work
<p align="justify">ESP32-LNW's evaluation revealed overall commendable accuracy despite some identified inaccuracies in transcribing technical and casual speech. Factors like technical term complexities, pronunciation variations, and background noise influenced discrepancies. The test highlighted strengths and improvement areas, affirming success in addressing communication challenges. Future focus includes continuous refinement for better accuracy across real-world scenarios, forming the basis for ongoing evolution of this IoT solution. </p>
