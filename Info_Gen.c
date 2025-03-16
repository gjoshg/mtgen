//////////////////////////////////
// 
// Jacob A Rolon
// Info Generator 
// 
////////////////////////////////
//
// Inputs: None
// Outputs: Prints
//
////////////////////////////////
#include<stdio.h> 
#include <time.h>

// Struct to hold info
typedef struct {
    char header[50];
    char date[20];
    char mgrs[30];
} Information;

void Start_Key(void);
void set_cursor_position(int row, int col);
void displayInfo(Information info[], int infoCount, int delaySeconds);
void clearScreen(void);



int main(void){
	setbuf(stdout, NULL);// Disable output buffering
	
	int infoCount = sizeof(infos) / sizeof(infos[0]);
    int delaySeconds = 60; // Delay between outputs

	Start_Key(); // Waits for keybaord input to start program 
	
	// Predefined information
    Information infos[] = {
        {"Weather Update", "2025-03-16", "33TWN8845281234"},
        {"Enemy Movement", "2025-03-15", "34UET1234567890"},
        {"Supply Drop", "2025-03-14", "35VXT9876543210"}
    };
	
	displayInfo(infos, infoCount, delaySeconds);

    set_cursor_position(infoCount + 5, 0); // Move cursor after info
    printf("All information displayed.\n");

    return 0;
	
	
	
}// end main

///////////////////////
// Sets cursor to desired position
// inputs: programmer
// outputs: moves cursor
///////////////////////////
void set_cursor_position(int row, int col){
 HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
 fflush(stdout);
 COORD coord = { (SHORT)col, (SHORT)row };
 SetConsoleCursorPosition(hOut, coord);
 return;
}// end set_cursor_position


////////////////////////////
// Start Program Function
// Inputs: None
// Outputs: None
////////////////////////////
void Start_Key(void){
    set_cursor_position(2, 0);
    printf("Press Enter to GO...");
    getchar(); // Wait for Enter key
}

/////////////////////////
// clear screen func
// inputs: none
// outputs: none
//////////////////////////
void clearScreen(void){
	
	system("cls"); // Clears Screen
	
}// end clear screen func

///////////////////////
// Information Display Function
// Inputs: None
// Outputs: Prints
///////////////////////
void displayInfo(Information info[], int infoCount, int delaySeconds){
	time_t startTime = time(NULL);
    int infoIndex = 0;

    while (infoIndex < infoCount){
        clearScreen();

        // Calculate elapsed time
        time_t currentTime = time(NULL);
        int elapsed = (int)(currentTime - startTime);

        int hours = elapsed / 3600;
        int minutes = (elapsed % 3600) / 60;
        int seconds = elapsed % 60;

        // Print elapsed time at top-right (column 55+ for spacing)
        set_cursor_position(0, 55);
        printf("Elapsed: %02d:%02d:%02d", hours, minutes, seconds);

        // Print header at top-left
        set_cursor_position(0, 0);
        printf("Info Generator");

        // Print displayed info so far
        for (int i = 0; i <= infoIndex; i++){
            set_cursor_position(i + 2, 0);
            printf("Header: %s | Date: %s | MGRS: %s", info[i].header, info[i].date, info[i].mgrs);
        }

        Sleep(delaySeconds * 1000); // Sleep for specified seconds
        infoIndex++;
    }
}
	