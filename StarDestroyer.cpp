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

bool check(){
	
	if (map[1][1] == 'X' && map[1][2] == 'X' && map[1][3] == 'X' && map[1][4] == 'X' && map[1][5] == 'X' && map[1][6] == 'X' && map[1][7] == 'X'){
		
		return true;
	}
	
	return false;
}

// check if star and projectile collide
bool check1(int starPos){
	
	if (map[1][starPos] == '*'){
		
		map[1][starPos] = 'X';
		prin();
		
	} else if (map[2][starPos] == '*') {
		
		map[2][starPos] = 'X';
		prin();
		
	} else if (map[3][starPos] == '*') {
		
		map[3][starPos] = 'X';
		prin();
		
	} else if (map[4][starPos] == '*') {
		
		map[4][starPos] = 'X';
		prin();
		
	} else if (map[5][starPos] == '*') {
		
		map[5][starPos] = 'X';
		prin();
		
	} else if (map[6][starPos] == '*') {
		
		map[6][starPos] = 'X';
		prin();
		
	} else if (map[7][starPos] == '*') {
		
		map[7][starPos] = 'X';
		prin();
		
	}
}

void time(int t){
	
	clock_t endWait = clock() + t;
	
	while (clock() <= endWait){
		
		
	}
}

// Show turn sequence as well as bot turns

int main(){
	
	int pos = 4;
	int starPosY = 1;
	int starPosX = 0;
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
					
				if (starPosX >= 0 && starPosX < 8){
					
					// TODO: fix issue with previous star not going to blank
					
					map[starPosY][arr1[starPosX]] = '@';
					
					if (starPosY > 1){
						
						map[starPosY - 1][arr1[starPosX]] = ' ';
					}
					
					prin();
					time(800);
					check1(arr1[starPosX]);
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
					time(2);
					system("cls");
					
					map[5][pos] = '*';
					map[6][pos] = ' ';
					time(2);
					prin();
					system("cls");
					
					map[4][pos] = '*';
					map[5][pos] = ' ';
					time(2);
					prin();
					system("cls");
					
					map[3][pos] = '*';
					map[4][pos] = ' ';
					time(2);
					prin();
					system("cls");
					
					map[2][pos] = '*';
					map[3][pos] = ' ';
					time(2);
					prin();
					system("cls");
					
					// the first index of map is why the x keeps floating to the top
					map[1][pos] = 'X';
					map[2][pos] = ' ';
					time(2);
					prin();
					system("cls");
				}
				
				prin();
				
				cin >> button;
				
				turn++;
			}
		}
	}
	
	return 0;
}