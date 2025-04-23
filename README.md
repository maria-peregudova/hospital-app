# hospital-app
This code will help monitor the state of patients currently in a hospital.

It will need 3 separate codes for now:
1. generates random patient data and stores it in a .txt file (simulates aquiring data live from machines monitoring the patients)
2. edits the file with patient stats, adds a status: _critical_ after the patient name if some of the stats get out of the allowed range (e.g. lack of pulse)
3. reads from patient data files and updates the database, shows critical patient names and locations on screen, will be able to search for patients
