#include <iostream>
#include <ctime>
#include <Windows.h>
#include <cstdlib>

using namespace std;
	
int instr;																						//these are the diferents variables we'll use
int frag[4];// = { frag0, frag1, frag2, frag3 };												//this is used as an array, used later
int colmn;
int mode;
int fragT;
int resta;
int pc;
bool player = true;												

int main() 
{

	srand(time(0));																				//this lets us create a random number generator that work with the time
	cout << "Benvingut al joc de Nim!" << endl;													//introducing values
	cout << "Prem 1 si vols les intruccions" << endl;			
	cin >> instr;																				//this variable will let us to select to display the guide

	if (instr == 1) {																			//if the player hits 1, a simple guide will be introduced

		cout << "El joc es molt simple. Hi han varies 3 columnes dividides en variis fragments" << endl;
		Sleep(3000);
		cout << "L'objectiu del mateix es ser l'ultim en quedar-se sense pedres." << endl;
		Sleep(3000);
		cout << "Hi hauran dos jugadors i cada un tindra un torn" << endl;
		Sleep(3000);
		cout << "En cada torn el jugador podra treure de 1 a 3 fragments, tot i que tan sol poden ser de la mateixa columna" << endl;
		Sleep(3000);
		cout << "Aixi doncs el jugador que es quedi sense pedres al seu torn, guanya" << endl;
		Sleep(3000);
		cout << "Per treure les pedres, primer escriuras el numero de la columna, enter" << endl;
		Sleep(3000);
		cout << "I seguidament diras quin nombre de fragments retiraras, i de nou, enter" << endl;
		Sleep(3000);
	}
	else {																						//In case the player hit anything else, it displays this message, and then continues

		cout << "Perfecte! Sembla que ja coneixes aquest joc, som-hi!" << endl;
		Sleep(1000);
	}

	cout << "Comensarem per decidir quants fragments tindra cada columna" << endl;
	Sleep(1000);
	cout << "Insereix el nombre de fragments que hi hauran, d'entre 3 a 9:" << endl;
	cin >> frag[0];

	while (frag[0] < 3 || frag[0] > 9) {														//This void will let us avoid the player to insert a non fuctional number

		cout << "Erroni, siusplau, insereix un valor correcte" << endl;
		cin >> frag[0];
	}
		frag[1] = frag[0];																		//This lets us give the value introduced to the others arrays
		frag[2] = frag[0];
		frag[3] = frag[0];
	

	cout << "Molt be! Prem 1 per jugar contra la maquina o 2 per un segon jugador" << endl;		//This part lets us decide the game mode
	cin >> mode;																				//By setting the int mode into 1 or 2
	fragT = (frag[1] + frag[2] + frag[3]);														//We created an int that saves the total of the 3 columns
	

	if (mode == 1){																				//This mode lets you play against the computer

		cout << "Aixi doncs, comences tu, escull primer el numero de la columna i despres, quantes treuras" << endl;

		while (fragT != 0) {
			cout << "Columna 1: " << frag[1] << "   Columna 2: " << frag[2] << "   Columna 3: " << frag[3] << endl;
			do {
				cout << "Torn del jugador!" << endl;
				cout << "Escull la columna destijada" << endl;
				cin >> colmn;																	//After displaying the number of frags left in each column, we let the player choose which one wants to change
			} while (colmn < 1 || colmn>3);														//This lets us create a void as long as colmn is between 1 and 3
				
			Sleep(1000);

			cout << "Escollim la columna " << colmn << " !" << endl;							//depending on the column we decided, a number will be displayed
			Sleep(500);

			cout << "Escull un numero del 1 al 3:" << endl;
			cin >> resta;																		//this variable will be set to rest numbers from the value
			Sleep(500);

			if (resta == 1 || resta == 2 || resta == 3) {										//this avoids the player to introduce a number diferent from the accepted ones
				frag[colmn] -= resta;															//because we did the array, we can avoid to do a switch with lots of lines, we can create an array that changes with the number

				cout << "Restem a la columna: " << resta << endl << endl;						//after the value is updated , it will be shown and 
				resta = 0;																		//the value will return to 0 to avoid possibles errors

				if (frag[colmn] < 0) {															//this is made to avoid the program to set a diferent number from 0, like -1 or -2

					frag[colmn] = 0;

				}

				fragT = (frag[1] + frag[2] + frag[3]);											//this gives us the result of all the frags, to update it each time we reproduce this void
			}

			else {																				//this displays in case the player introduces a non accepted value
				cout << "Em sap greu! Numero erroni! Perds el torn :P" << endl << endl;
				Sleep(3000);
			}

			//This if will determinate how the program will work when playing with the computer
			if (fragT != 0) {																	//we introduced this condition that, in case the players set the value to 0, the void will stop
				
				if (frag[2] <= 0 && frag[3] <= 0) {												//In case column 2 & 3 is 0, it chooses the column 1

					pc = 1;
				}
				
				else if (frag[1] <= 0 && frag[3] <= 0) {										//In case column 1 & 3 is 0, it chooses the column 2

					pc = 2;
				}

				else if (frag[1] <= 0 && frag[2] <= 0) {										//In case column 1 & 2 is 0, it chooses column 3

					pc = 3;
				}

				else if (frag[2] == 0) {														//In column column 2 is 0, it generates a random value that chooses 1 or 3

					int man = 0;
					man = rand() % 2 + 1;

					switch (man) {

					case 1: pc = 1;

					case 2: pc = 3;

					default: pc = 3;															//This is used to avoid errors
					}

				}

				else if (frag[3] <= 0) {														//Same as others, in case the 3 is 0, it chooses column 1 or 2 randomly

					pc = rand() % 2 + 1;
				}

				else if (frag[1] <= 0) {														//Same as the last one, but between 2 or 3

					pc = rand() % 2 + 2;
				}

				else {																			//This is the default function, leading into choose between 1, 2 or 3

					pc = rand() % 3 + 1;
				}

				while (frag != 0) {																//This remains as a void because it keeps working, it's from a latest version of the code

					cout << "Torn de la maquina!!" << endl;										//this message displays as an indicator for the player that it's the computer's turn
					Sleep(3000);

					cout << "Escollim la columna " << pc << " !" << endl;						//This will display the pc that'll let us use the array frag later
					Sleep(500);

					cout << "Escull un numero del 1 al 3:" << endl;								//this is to simulate the computer selecting the number
					Sleep(500);

					resta = rand() % 3 + 1;														//this will state a random value into the resta variable


					if (resta == 1 || resta == 2 || resta == 3) {								//as long as the value equals to 1, 2 or 3, the operation will be applied
						frag[pc] -= resta;														//this applies the operation to the array, depending on the number of the pc value

						cout << "Restem a la columna: " << resta << endl << endl;				//this shows how the operation went
						resta = 0;																//and this resets the value to 0 to avoid errors

						if (frag[pc] < 0) {														//this condition will transform any negative number to the value 0, to avoid errors

							frag[pc] = 0;

						}

						
						fragT = (frag[1] + frag[2] + frag[3]);									//and now this will calculate again the total value, to know if the program has to keep working or now stops
						Sleep(500);

						if (fragT == 0) {														//in case the game stops at this pont, it will show the message that the computer has won
							cout << "Llastima! Ha guanyat la maquina!" << endl;
						}
					}
					else {																		//this else activates in case the resta value is not equal to 1, 2 or 3
						cout << "Em sap greu! Numero erroni! Perds el torn :P" << endl;
						Sleep(3000);
					}

					break;

				}

				}

			else {																				//this will apply in case the player wins the game by setting all pieces to 0
				cout << "Guanya el jugador!";
			}

		}
	}

	else if (mode == 2) {																		//this case is used in case the player sets the gamemode to 2, to play with another player

		cout << "Molt bé! Suposo que ja us gestioneu aqui vosaltres! GLHF!" << endl;			//here the comùter gives you the total control of the game
		Sleep(3000);
		while (fragT != 0) {
			cout << "Columna 1: " << frag[1] << "   Columna 2: " << frag[2] << "   Columna 3: " << frag[3] << endl;
			do {
				cout << "Torn del jugador!" << endl;
				cout << "Escull la columna destijada" << endl;
				cin >> colmn;																	//After displaying the number of frags left in each column, we let the player choose which one wants to change
			} while (colmn < 1 || colmn>3);														//This lets us create a void as long as colmn is between 1 and 3

				cout << "Escollim la columna " << colmn << "!" << endl;							//this message is used to anounce the selected column
				Sleep(500);
								
				cout << "Escull un numero del 1 al 3:" << endl;									
				cin >> resta;																	//this variable stores the minus value to apply
				Sleep(500);

				if (resta == 1 || resta == 2 || resta == 3) {									//in case the num is equal to 1, 2 or 3
					frag[colmn] -= resta;														//it will apply the operation to the selected array

					cout << "Restem a la columna: " << resta << endl;							//this shows how much is applied
					resta = 0;																	//and restores the value to 0 again
					Sleep(500);

					if (frag[colmn] < 0) {														//this is used to set the value again to 0 in case the applied value sets it to a negative value

						frag[colmn] = 0;

					}

					
					fragT = (frag[1] + frag[2] + frag[3]);										//and does again the operation to update the total value

					if (fragT !=0) {															//in case the total is diferent to 0, the message to continue the game will display
						cout << "Seguent torn!" << endl << endl;
						Sleep(500);
					}
				}
				else {																			//in case the resta value is wrong, it will display this message and the turn will pass
					cout << "Em sap greu! Numero erroni! Perds el torn :P" << endl;
					Sleep(3000);
				}

			}

			cout << "Fi del joc!";																//once the void is broken, it displays an endgame message

		}

		else {
			cout << "Resposta incorrecte, torna a iniciar el programa.";						//in case the player does not set a correct value, t
		}

	}