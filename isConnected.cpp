#include <iostream>
#include <fstream>
#include <string> 
using namespace std;

#define M 20
#define N 40

//0 means we couldn't find any not null value from map array
int findNotNullSquare(int map[M][N],int &startX,int &startY)
{
	bool end = false;
	for(int i = 0; i < M;i++)
	{
		if(end == true)
		{
			break;
		}else{
			for(int j = 0; j < N;j++)
			{
				
				if(map[i][j] == 1){
					startX = i;
					startY = j;
					end = true;
					break;
				}
			}
		}
	}

	if(end == true)
	{
		return 1;
	}else{
		return 0;
	}
}
//Flood Fill Algorithm
void isConnected(int map[M][N],int x, int y)
{

	if(x < 0 || y < 0 || x >= M || y >= N) return;

	if(map[x][y] == 0) return;
	
	map[x][y] = 0;
	isConnected(map,x+1,y);
	isConnected(map,x-1,y);
	isConnected(map,x,y+1);
	isConnected(map,x,y-1);
	isConnected(map,x+1,y+1);
	isConnected(map,x-1,y-1);
	isConnected(map,x+1,y-1);
	isConnected(map,x-1,y+1);
}

void storeData(string fileName,int data[M][N])
{
	ifstream input;
	input.open(fileName);

	string line[M];

	string x;

	int k = 0;
	
	while(input >> x)
	{
		line[k] = x;
		k++;
	}

	for(int i = 0;i < M;i++)
	{
		for(int j = 0;j < N;j++)
		{
			data[i][j] = line[i][j] - '0';
		}
	}

	input.close();
}

int main()
{
	int map[M][N] = {};

	//First We Store Circuit Map in an array
	storeData("circuit.txt",map);

	//
	int startX,startY;
	
	findNotNullSquare(map,startX,startY);

	isConnected(map,startX,startY);

	if(findNotNullSquare(map,startX,startY))
	{
		cout << "the circuit is not fully connected!";
	}else{
		cout << "the circuit is fully connected!";
	}

	
	return 0;
}