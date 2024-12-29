#include <iostream> // For input/output
#include <cstdlib>  // For random number generation
#include <ctime>    // For seeding the random generator
using namespace std;

// Function to simulate temperature sensor
int getTemperature() {
    return rand() % 50; // Generate a random temperature between 0 and 49
}

// Function to simulate light sensor
int getLightLevel() {
    return rand() % 100; // Generate a random light level between 0 and 99
}

// Function to simulate humidity sensor
int getHumidity() {
    return rand() % 100; // Generate a random humidity level between 0 and 99
}

// Function to display the window state and sensor data
void displayStatus(int temperature, int lightLevel, int humidity, string windowState) {
    cout << "\n--- Current Sensor Readings ---" << endl;
    cout << "Temperature: " << temperature << "°C" << endl;
    cout << "Light Level: " << lightLevel << "%" << endl;
    cout << "Humidity: " << humidity << "%" << endl;
    cout << "Window State: " << windowState << endl;
    cout << "--------------------------------" << endl;
}

int main() {
    // Set up random number generator
    srand(time(0)); // Seed the random number generator

    // Initialize the window state as "closed"
    string windowState = "closed";

    // Allow the user to set thresholds
    int tempThreshold, lightThreshold, humidityThreshold;
    cout << "Welcome to the Automated Window System!" << endl;
    cout << "Please set the thresholds for window automation." << endl;

    cout << "Enter temperature threshold (e.g., 30): ";
    cin >> tempThreshold;

    cout << "Enter light level threshold (e.g., 70): ";
    cin >> lightThreshold;

    cout << "Enter humidity threshold (e.g., 60): ";
    cin >> humidityThreshold;

    // Start the loop for continuous automation
    while (true) {
        // Get random sensor readings
        int temperature = getTemperature();
        int lightLevel = getLightLevel();
        int humidity = getHumidity();

        // Display current readings
        displayStatus(temperature, lightLevel, humidity, windowState);

        // Ask if the user wants to override the system
        cout << "Do you want to override the window state? (yes/no): ";
        string userInput;
        cin >> userInput;

        if (userInput == "yes") {
            // If user chooses to override, ask for new state
            cout << "Enter new window state (open/closed): ";
            cin >> windowState;
        } else {
            // Automated logic based on thresholds
            if (temperature > tempThreshold || lightLevel > lightThreshold || humidity > humidityThreshold) {
                windowState = "open"; // Open the window if any condition is met
            } else {
                windowState = "closed"; // Close the window otherwise
            }
        }

        // Add a pause to make the simulation readable
        cout << "Press any key to continue..." << endl;
        system("pause>0");
    }

    return 0;
}
