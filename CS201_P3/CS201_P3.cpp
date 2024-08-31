// Gunner Pace, Program 3 - Distance
#include <iostream>
#include <string>
#include <cstdlib>  
#include <ctime>    
#include <cmath>    

using namespace std;

int main() {
    // Set up variables used
    string in1, in2, in3, in4;
    int x1, y1, x2, y2;
    float dist1, dist2;
    char choice;

    // Get choice from user 
    cout << "How would you like to get the 4 values (e to enter manually, g to generate randomly): ";
    cin >> choice;

    if (choice == 'e') {
        cout << "Please enter 4 values: " << endl;
        cin >> in1 >> in2 >> in3 >> in4;
        string choiceArray[4] = { in1, in2, in3, in4 };

        for (int i = 0; i < 4; i++) {
            try {
                // Convert string to integer
                int value = stoi(choiceArray[i]);

                // Check if the value is in the range [-10, 10]
                if (value < -10 || value > 10) {
                    cout << "Invalid input, " << choiceArray[i] << " is not in range (-10, 10)." << endl;
                }
            }
            catch (const invalid_argument&) {
                cout << "Invalid input, " << choiceArray[i] << " is not a number." << endl;
            }
            catch (const out_of_range&) {
                cout << "Invalid input, " << choiceArray[i] << " is out of range." << endl;
            }
        }

        // Convert valid strings to integers
        x1 = stoi(in1);
        y1 = stoi(in2);
        x2 = stoi(in3);
        y2 = stoi(in4);
    }
    else if (choice == 'g') {
        srand(time(0));
        // Generate 4 random numbers between -10 and 10
        x1 = rand() % 21 - 10;
        y1 = rand() % 21 - 10;
        x2 = rand() % 21 - 10;
        y2 = rand() % 21 - 10;
    }
    else {
        cout << "Invalid choice. Please enter 'e' or 'g'." << endl;
    }

    cout << "Point 1 = (" << x1 << ", " << y1 << ") Point 2 = (" << x2 << ", " << y2 << ")" << endl;

    // Calculate distances from origin (0,0)
    dist1 = sqrt(pow(x1, 2) + pow(y1, 2));
    dist2 = sqrt(pow(x2, 2) + pow(y2, 2));
    cout << "Distance of P1 = " << dist1 << endl;
    cout << "Distance of P2 = " << dist2 << endl;
    if (dist1 > dist2) {
        cout << "Point 1 is farther with a distance of " << dist1 << endl;
    }
    else {
        cout << "Point 2 is farther with a distance of " << dist2 << endl;
    }

    return 0;
}