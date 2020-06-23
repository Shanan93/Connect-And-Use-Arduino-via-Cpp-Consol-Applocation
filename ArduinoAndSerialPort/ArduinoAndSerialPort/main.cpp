

/* PC 2 Arduino */

#include<iostream>
using namespace std;
#include<string>
#include<stdlib.h>
#include"ArduinoAndSerialPort.h"
#include "ArduinoAndSerialPort.h"

char output[MAX_DATA_LENGTH];
char incomingData[MAX_DATA_LENGTH];

// change the name of the port with the port name of your computer
// must remember that the backslashes are essential so do not remove them
const char* port = "\\\\.\\COM4";

int main() {
	SerialPort arduino(const_cast<char*>(port));
	if (arduino.isConnected()) {
		cout << "Connection made" << endl << endl;
	}
	else {
		cout << "Error in port name" << endl << endl;
	}
	while (arduino.isConnected()) {
		
			/**arduino.readSerialPort(output, MAX_DATA_LENGTH);
			cout << output;
			//delete[] charArray;**/
		
		
		
		cout << "Enter your command: " << endl;
		string data;
		cin >> data;

		char* charArray = new char[data.size() + 1];
		copy(data.begin(), data.end(), charArray);
		charArray[data.size()] = '\n';

		arduino.writeSerialPort(charArray, MAX_DATA_LENGTH);
		arduino.readSerialPort(output, MAX_DATA_LENGTH);

		cout << ">> " << output << endl;

		delete[] charArray; 
	}
	return 0;
}
