import time

import cv2
import serial

# Load Haar cascade classifier for face detection
face_cascade = cv2.CascadeClassifier(r'D:\DownloadFiles\Python-Face Tracking\haarcascade_frontalface_default.xml')

# Check for available cameras and handle potential errors
try:
    # print(f"Available cameras: {cv2.VideoCapture.get_device_count()}")
    camera_index = 0  # Adjust based on your setup
    cap = cv2.VideoCapture(camera_index)
except cv2.error as e:
    print(f"Error accessing camera: {e}")
    exit()

# Establish serial communication with Arduino
try:
    ArduinoSerial = serial.Serial('com3', 9600, timeout=0.1)
except serial.SerialException as e:
    print(f"Error connecting to Arduino: {e}")
    exit()

# Set up video writer (optional)
fourcc = cv2.VideoWriter_fourcc(*'XVID')
out = cv2.VideoWriter('face_detection4.avi', fourcc, 20.0, (640, 480))

time.sleep(1)  # Allow camera to warm up

while cap.isOpened():
    # Capture frame
    ret, frame = cap.read()

    if not ret:
        print("Error reading frame from camera")
        break

    # Mirror the image
    frame = cv2.flip(frame, 1)

    # Convert to grayscale
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

    # Detect faces
    faces = face_cascade.detectMultiScale(gray, 1.1, 6)

    for x, y, w, h in faces:
        # Calculate face center coordinates
        center_x = x + w // 2
        center_y = y + h // 2

        # Send coordinates to Arduino
        string = f'X{center_x:d}Y{center_y:d}'
        ArduinoSerial.write(string.encode('utf-8'))

        # Draw face detection elements
        cv2.circle(frame, (center_x, center_y), 2, (0, 255, 0), 2)  # Center point
        cv2.rectangle(frame, (x, y), (x + w, y + h), (0, 0, 255), 3)  # Face rectangle

    # Draw center square
    cv2.rectangle(frame, (640 // 2 - 30, 480 // 2 - 30),
                  (640 // 2 + 30, 480 // 2 + 30),
                  (255, 255, 255), 3)

    # Optional: Write frame to video file
    out.write(frame)

    # Display the resulting frame
    cv2.imshow('img', frame)

    # Optional: Save image to file
    # cv2.imwrite('output_img.jpg', frame)

    # Check for 'q' key to quit
    if cv2.waitKey(10) & 0xFF == ord('q'):
        break

# Release resources
cap.release()
out.release()
cv2.destroyAllWindows()
