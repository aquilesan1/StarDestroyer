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
						
int arr[7] = {2, 6, 7, 3, 4, 1, 5};

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
// TODO: clean file
int main(){
	
	int pos = 4;
	int starPosY = 1;
	int starPosX = 0;
	char button;
	int turn = 0;
	int count = 0;
	
	system("cls");
	
	cout << "------------------------------\n|Welcome to Start Destroyer! |\n|Press w to shoot.           |\n|Press a to move left.       |\n|Press d to move right       |\n|                            |\n|Press s to start!           |\n|Press x at anypoint to exit.|\n------------------------------";
	
	cin >> button;
	system("cls");
	
	while (button != 'x'){
		
		while (turn < 32){
		
			prin();
			system("CLS");
		
			if (turn % 2 == 0){
				
				if (starPosY == 1){
					
					map[starPosY][arr[count]] = '@';
					prin();
					starPosY++;
					
				} else if (starPosY < 6 && starPosY > 1){
					
					map[starPosY][arr[count]] = '@';
					map[starPosY - 1][arr[count]] = ' ';
					prin();
					starPosY++;
					
					
				} else if (starPosY == 6){
					starPosY = 1;
					count++;
				}
				
				turn++;
				
			} else if (turn % 2 == 1){
			
				if (button == 'a'){
					
					map[7][pos - 1] = '^';
					map[7][pos] = ' ';
					prin();
					system("CLS");
					pos -= 1;
					turn++;
					
				} else if (button == 'd'){
					
					map[7][pos + 1] = '^';
					map[7][pos] = ' ';
					prin();
					system("CLS");
					pos += 1;
					turn++;
					
				} else if (button == 'w'){
					
					int projPos = 6;
					while (projPos != 0){
						
						if (projPos == 6){
							
							map[projPos][pos] = '*';
							ti(80);
							prin();
							system("cls");
							
						} else {
							
							map[projPos][pos] = '*';
							map[projPos + 1][pos] = ' ';
							ti(80);
							prin();
							system("CLS");
						}
						
						projPos--;
					}
				}
				
				prin();
				
				cin >> button;
				
				if (button == 'x'){
					break;
				}
			}
		}
	}
	
	return 0;
}