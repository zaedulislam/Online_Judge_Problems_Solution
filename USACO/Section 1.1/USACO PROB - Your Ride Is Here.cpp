// Section 1.1
// USACO PROB - Your Ride Is Here.cpp

/*
ID: zayedkh1
PROG: ride
LANG: C++
*/

#include<iostream>
#include <fstream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<stack>
#include<ctime>
#include<queue>
#include<algorithm>
typedef unsigned long long llu;

using namespace std;

const int MOD = 47;
const int _size = 10;
string cometName;
string groupName;
char alphabet[] = " ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main()
{
	int valueComet = 1, valueGroup = 1;
	
	ofstream fout("ride.out");
	ifstream fin("ride.in");

	fin >> cometName >> groupName;

	int lenComet = cometName.length();

	int I, K;
	for (I = 0; I < lenComet; I++) {
		for (K = 1; K <= 26; K++) {
			if (cometName[I] == alphabet[K]) {
				valueComet *= K;
				break;
			}
		}
	}
	valueComet %= MOD;

	int lenGroup = groupName.length();

	for (I = 0; I < lenGroup; I++) {
		for (K = 1; K <= 26; K++) {
			if (groupName[I] == alphabet[K]) {
				valueGroup *= K;
				break;
			}
		}
	}
	valueGroup %= MOD;

	if (valueComet == valueGroup)
		fout << "GO" << endl;
	else
		fout << "STAY" << endl;

	return 0;
}

