# Clinic Management System

The Clinic Management System is a C program that allows users to manage patient records, reservations, and other administrative tasks for a clinic. The program has two modes: admin mode and user mode.

## Features

### Admin Mode
1. Password-protected login:
   - The default password is `1234`.
   - The system allows 3 attempts to enter the correct password. If the password is incorrect for 3 consecutive times, the system will close.
2. Patient Management:
   - Add new patient record:
     - The admin can enter a patient's name, age, gender, and unique ID.
     - If the entered ID already exists, the system will reject the entry.
   - Edit patient record:
     - The admin can edit a patient's information by entering the patient's ID.
     - If the ID does not exist, the system will display an "Incorrect ID" message.
3. Reservation Management:
   - Reserve a slot with the doctor:
     - The system displays the available slots by default: 2pm to 2:30pm, 2:30pm to 3pm, 3pm to 3:30pm, 4pm to 4:30pm, and 4:30pm to 5pm.
     - The admin can enter the patient ID and the desired slot.
     - The reserved slot will not be displayed in the available slots window for the next patient reservation.
   - Cancel reservation:
     - The admin can cancel a reservation by entering the patient ID.
     - The canceled reservation will be shown again in the available slots window.

### User Mode
1. View patient record:
   - By entering the patient ID, the system will display the basic information for the patient.
2. View today's reservations:
   - The system will print all reservations with the patient ID attached to each reservation slot.

