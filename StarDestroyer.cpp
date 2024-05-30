#include <iostream>
#include <string>
#include <ctime>

using namespace std;

char map[9][9] = {{'-','-','-','-','-','-','-','-','-'},
						{'|',' ',' ',' ',' ',' ',' ',' ','|'},
						{'|',' ',' ',' ',' ',' ',' ',' ','|'},
						{'|',' ',' ',' ',' ',' ',' ',' ','|'},
						{'|',' ',' ',' ',' ',' ',' ',' ','|'},
						{'|',' ',' ',' ',' ',' ',' ',' ','|'},
						{'|',' ',' ',' ',' ',' ',' ',' ','|'},
						{'|',' ',' ',' ','^',' ',' ',' ','|'},
						{'-','-','-','-','-','-','-','-','-'}};
int arr[2] = {0, 1};
int arr1[7] = {2, 6, 7, 3, 4, 1, 5};
int arr2[7] = {5, 1, 4, 3, 7, 6, 2};

void prin(){
	
	for (int i = 0; i < 9; i++){
		
		for (int j = 0; j < 9; j++){
			
			cout << map[i][j];
		}
		cout << '\n';
	}
}

void ti(int t){
	
	clock_t endWait = clock() + t;
	
	while (clock() <= endWait){
		
		
	}
}

// TODO: show end game
// TODO: try to fix X functionality
int main(){
	
	int pos = 4;
	int starPosY = 1;
	int starPosX = 0;
	int projPos = 6;
	char button;
	int turn = 0;
	
	system("cls");
	
	cout << "------------------------------\n|Welcome to Start Destroyer! |\n|Press w to shoot.           |\n|Press a to move left.       |\n|Press d to move right       |\n|                            |\n|Press s to start!           |\n|Press x at anypoint to exit.|\n------------------------------";
	
	cin >> button;
	system("cls");
	
	while (button != 'x'){
		
		while (turn < 32){
		
			prin();
			system("CLS");
		
			if (turn % 2 == 0){
				
				// checks if star at position x is within range of 0 to 8
				if (starPosX >= 0 && starPosX < 8){
					
					// TODO: fix issue with star printing itself in middle of map
					
					map[starPosY][arr1[starPosX]] = '@';
					
					if (starPosY > 1){
						
						map[starPosY - 1][arr1[starPosX]] = ' ';
					}
					prin();
					ti(800);
					system("cls");
					
					starPosY++;
				}
				
				if (starPosY == 6){
					
					starPosY = 1;
					starPosX++;
				}
				
				turn++;
				
			} else if (turn % 2 == 1){
			
				if (button == 'a'){
					
					map[7][pos - 1] = '^';
					map[7][pos] = ' ';
					prin();
					system("CLS");
					pos -= 1;
					
				} else if (button == 'd'){
					
					map[7][pos + 1] = '^';
					map[7][pos] = ' ';
					prin();
					system("CLS");
					pos += 1;
					
				} else if (button == 'w'){
					
					
					map[6][pos] = '*';
					prin();
					ti(80);
					system("cls");
					
					map[5][pos] = '*';
					map[6][pos] = ' ';
					ti(80);
					prin();
					system("cls");
					
					map[4][pos] = '*';
					map[5][pos] = ' ';
					ti(80);
					prin();
					system("cls");
					
					map[3][pos] = '*';
					map[4][pos] = ' ';
					ti(80);
					prin();
					system("cls");
					
					map[2][pos] = '*';
					map[3][pos] = ' ';
					ti(80);
					prin();
					system("cls");
					
					map[1][pos] = 'X';
					map[2][pos] = ' ';
					ti(80);
					prin();
					system("cls");
				}
				
				prin();
				
				cin >> button;
				
				if (button == 'x'){
					break;
				}
				
				turn++;
			}
		}
	}
	
	return 0;
}