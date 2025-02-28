🚀 A button-controlled shooting game on a 16x2 LCD, built using the LPC2148 microcontroller!

🕹️ Game Overview
This is a three-level shooting game where the player must eliminate robots while avoiding humans. The game runs on an alphanumeric 16x2 LCD and is controlled using three buttons.

🎯 Gameplay Levels:
1️⃣ Level 1: Shoot 5 robots in 60 seconds to proceed.
2️⃣ Level 2: Robot speed increases, and time is reduced for an added challenge.
3️⃣ Level 3: Avoid shooting humans! Game over if a human is hit.

🔧 Technical Details
Microcontroller Used: LPC2148 (Hardware)
Simulation Tested On: LPC2124 (Proteus)
Programmed In: C (Keil uVision)
Display: 16x2 Alphanumeric LCD
Controls: Three-button input

🛠️ How to Run the Project
1️⃣ Simulation (Proteus)
Open the Proteus project (GAME_SIMULATION.pdsprj file).
Load the HEX file generated from Keil.
Run the simulation to see the game in action.
2️⃣ Hardware Implementation
Flash the compiled binary (.hex) to the LPC2148 microcontroller using Flash Magic.
Connect the LCD (16x2) and buttons as per the circuit diagram.
Power up and start playing!
