# StarCraft: BroodWar AI - BWAPI 4.4.0

## Overview

This project implements a custom AI for StarCraft: Brood War using the Brood War Application Programming Interface (BWAPI) version 4.4.0. The AI is designed to control a Zerg bot that can perform a variety of tasks such as resource management, unit control, and decision-making. The AI operates based on rule-based systems, providing a consistent and reliable performance in short-term decision-making scenarios.

## Prerequisites

To work on this project, you will need the following:

- **StarCraft: Brood War** installed
- **BWAPI 4.4.0** installed and properly configured
- **Visual Studio 2019 or later** with support for C++20
- **v143 Build tools** installed for compilation
- **CMake** (optional but recommended for advanced builds)

## Setup Instructions

1. **BWAPI Configuration:**
   - Download and set up BWAPI from the official [BWAPI GitHub repository](https://github.com/bwapi/bwapi).
   - Ensure that BWAPI is linked with your StarCraft installation.

2. **Clone this Repository:**
   - Clone this repository into your local machine:
     ```bash
     git clone https://github.com/your-username/starcraft-bwapi-ai.git
     ```
   
3. **Build the Project:**
   - Open the project in Visual Studio and ensure that the BWAPI includes and libraries are correctly linked.
   - Build the project in `Release` mode using the C++20 standard.

4. **Run the AI:**
   - After compiling, an executable `StarterBot.exe` will be created. Run `RunStarcraftWithBWAPI.bat` to start StarCraft with the AI injected.
   - The AI will begin operating as soon as the game starts, controlling the Zerg faction.

## Project Structure

- **main.cpp:** Handles the connection between the AI and the BWAPI client.
- **StarterBot.cpp:** Core AI logic that runs on every game frame, handling decision-making and unit control.
- **MapTools.cpp:** Utility functions for map analysis and pathfinding.
- **Tools.cpp:** Helper functions for various game-related tasks such as resource management and unit coordination.

## AI Details

- **Architecture:** The AI is rule-based, focusing on consistent performance in short-term scenarios. The logic is limited to the Zerg race but is designed to perform efficiently in competitive matches.
  
- **OnStart():** Initializes game state and prepares the AI at the start of each match.
  
- **OnFrame():** The core function where decision-making and actions are performed on every game frame.
  
- **OnEnd():** Final cleanup after the game concludes, logging performance data for future improvements.

## Running the Project

1. Execute `RunStarcraftWithBWAPI.bat` to launch StarCraft with the AI injected.
2. Observe the debug output in the terminal where `StarterBot.exe` is running.
3. The AI will take control from the first game frame, managing Zerg units and executing strategies.
4. Upon game conclusion, the AI will stop, and performance data will be available.

## Future Work

- **Machine Learning Integration:** Future iterations could explore integrating machine learning techniques for improved decision-making.
- **Multiracial Support:** Expanding the AI to control Protoss and Terran races.
- **Advanced Strategy Development:** Incorporating more complex strategies and build orders, as well as better response systems against human opponents.
- **Enhanced Data Analysis:** Developing better tools for data logging and analysis to refine AI performance.

## Acknowledgments

- **Dave Churchhill** for guidance and development of BWAPI.
- **University of Alberta** for their contributions to StarCraft AI research.
- **DeepMind's AlphaStar** for inspiration in advancing AI performance in StarCraft.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

