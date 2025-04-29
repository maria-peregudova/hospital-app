# hospital-app
This code will help monitor the state of patients currently in a hospital.

It will need 2 separate codes for now:
1. generates random patient data and stores it in a .txt file (simulates aquiring data live from machines monitoring the patients), adds a status: {1,2,3,4,5} after the patient name if some of the stats get out of the allowed range (e.g. lack of pulse)
2. reads from patient data files and updates the database, shows critical patient names and locations on screen, will be able to search for patients
