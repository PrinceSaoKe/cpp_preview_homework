#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <fstream>
using namespace std;

int function(int n);

int main()
{
	int n;

	FILE* Input = fopen("input.txt", "r");
	FILE* Output = fopen("output.txt", "w");
	fscanf(Input, "%d", &n);
	fprintf(Output, "%d\n", n + 1);

	return 0;
}

int function(int n)
{
	return n + 1;
}