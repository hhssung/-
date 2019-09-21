#include <iostream>

using namespace std;

char U[3][3];	//up
char L[3][3];	//left
char R[3][3];	//right
char F[3][3];	//front
char B[3][3];	//back
char D[3][3];	//down
char save1[12];
char save2[2];

void rotate1(char a0, char a1, char a2, char b0, char b1, char b2, char c0, char c1, char c2, char d0, char d1, char d2, char x)
{
	if (x == '+')
	{
		save1[0] = b0;
		save1[1] = b1;
		save1[2] = b2;
		save1[3] = c0;
		save1[4] = c1;
		save1[5] = c2;
		save1[6] = d0;
		save1[7] = d1;
		save1[8] = d2;
		save1[9] = a0;
		save1[10] = a1;
		save1[11] = a2;

	}
	else {
		save1[0] = d0;
		save1[1] = d1;
		save1[2] = d2;
		save1[3] = a0;
		save1[4] = a1;
		save1[5] = a2;
		save1[6] = b0;
		save1[7] = b1;
		save1[8] = b2;
		save1[9] = c0;
		save1[10] = c1;
		save1[11] = c2;
	}
}

void rotate2(char arr[][3], char x)
{
	if (x == '+')
	{
		save2[0] = arr[0][0];   save2[1] = arr[0][1];
		arr[0][0] = arr[2][0];   arr[0][1] = arr[1][0];
		arr[2][0] = arr[2][2];   arr[1][0] = arr[2][1];
		arr[2][2] = arr[0][2];   arr[2][1] = arr[1][2];
		arr[0][2] = save2[0];   arr[1][2] = save2[1];
	}
	else if (x == '-'){
		save2[0] = arr[0][0];   save2[1] = arr[0][1];
		arr[0][0] = arr[0][2];   arr[0][1] = arr[1][2];
		arr[0][2] = arr[2][2];   arr[1][2] = arr[2][1];
		arr[2][2] = arr[2][0];   arr[2][1] = arr[1][0];
		arr[2][0] = save2[0];   arr[1][0] = save2[1];
	}
}

int main(void)
{
	int N;
	cin >> N;

	int s;
	char rotate;
	char x;

	for (int i = 0; i < N; i++)
	{
		cin >> s;
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				U[j][k] = 'w';
				R[j][k] = 'b';
				L[j][k] = 'g';
				F[j][k] = 'r';
				B[j][k] = 'o';
				D[j][k] = 'y';
			}
		}

		for (int j = 0; j < s; j++)
		{
			cin >> rotate;
			switch (rotate)
			{
			case 'U':
				cin >> x;
				rotate1(L[0][0], L[0][1], L[0][2], F[0][0], F[0][1], F[0][2], R[0][0], R[0][1], R[0][2], B[0][0], B[0][1], B[0][2], x);
				L[0][0] = save1[0];
				L[0][1] = save1[1];
				L[0][2] = save1[2];
				F[0][0] = save1[3];
				F[0][1] = save1[4];
				F[0][2] = save1[5];
				R[0][0] = save1[6];
				R[0][1] = save1[7];
				R[0][2] = save1[8];
				B[0][0] = save1[9];
				B[0][1] = save1[10];
				B[0][2] = save1[11];
				rotate2(U,x);
				break;
			case 'D':
				cin >> x;
				rotate1(R[2][2], R[2][1], R[2][0], F[2][2], F[2][1], F[2][0], L[2][2], L[2][1], L[2][0], B[2][2], B[2][1], B[2][0], x);
				R[2][2] = save1[0];
				R[2][1] = save1[1];
				R[2][0] = save1[2];
				F[2][2] = save1[3];
				F[2][1] = save1[4];
				F[2][0] = save1[5];
				L[2][2] = save1[6];
				L[2][1] = save1[7];
				L[2][0] = save1[8];
				B[2][2] = save1[9];
				B[2][1] = save1[10];
				B[2][0] = save1[11];
				if (x == '+')
				{
					x = '-';
				}
				else {
					x = '+';
				}

				rotate2(D, x);
				break;
			case 'F':
				cin >> x;
				rotate1(L[0][2], L[1][2], L[2][2], D[2][0], D[2][1], D[2][2], R[2][0], R[1][0], R[0][0], U[2][2], U[2][1], U[2][0], x);
				L[0][2] = save1[0];
				L[1][2] = save1[1];
				L[2][2] = save1[2];
				D[2][0] = save1[3];
				D[2][1] = save1[4];
				D[2][2] = save1[5];
				R[2][0] = save1[6];
				R[1][0] = save1[7];
				R[0][0] = save1[8];
				U[2][2] = save1[9];
				U[2][1] = save1[10];
				U[2][0] = save1[11];
				rotate2(F, x);
				break;
			case 'B':
				cin >> x;
				rotate1(R[0][2], R[1][2], R[2][2], D[0][2], D[0][1], D[0][0], L[2][0], L[1][0], L[0][0], U[0][0], U[0][1], U[0][2], x);
				R[0][2] = save1[0]; 
				R[1][2] = save1[1]; 
				R[2][2] = save1[2]; 
				D[0][2] = save1[3]; 
				D[0][1] = save1[4]; 
				D[0][0] = save1[5];
				L[2][0] = save1[6]; 
				L[1][0] = save1[7]; 
				L[0][0] = save1[8]; 
				U[0][0] = save1[9]; 
				U[0][1] = save1[10]; 
				U[0][2] = save1[11];
				rotate2(B, x);
				break;
			case 'L':
				cin >> x;
				rotate1(B[2][2], B[1][2], B[0][2], D[2][0], D[1][0], D[0][0] , F[0][0], F[1][0], F[2][0], U[0][0], U[1][0], U[2][0], x);
				B[2][2] = save1[0];
				B[1][2] = save1[1]; 
				B[0][2] = save1[2];
				D[2][0] = save1[3]; 
				D[1][0] = save1[4];
				D[0][0] = save1[5]; 
				F[0][0] = save1[6]; 
				F[1][0] = save1[7]; 
				F[2][0] = save1[8];  
				U[0][0] = save1[9]; 
				U[1][0] = save1[10]; 
				U[2][0] = save1[11];
				rotate2(L, x);
				break;
			case 'R':
				cin >> x;
				rotate1(F[0][2], F[1][2], F[2][2], D[2][2], D[1][2], D[0][2], B[2][0], B[1][0], B[0][0], U[0][2], U[1][2], U[2][2], x);
				F[0][2] = save1[0];
				F[1][2] = save1[1];
				F[2][2] = save1[2];
				D[2][2] = save1[3];
				D[1][2] = save1[4];
				D[0][2] = save1[5];
				B[2][0] = save1[6];
				B[1][0] = save1[7];
				B[0][0] = save1[8];
				U[0][2] = save1[9];
				U[1][2] = save1[10];
				U[2][2] = save1[11];
				rotate2(R, x);
				break;
			}
		}
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				cout << U[j][k];
			}
			cout << endl;
		}
		/*
		cout << endl;
	
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				cout << D[j][k];
			}
			cout << endl;
		}
		cout << endl;

		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				cout << F[j][k];
			}
			cout << endl;
		}
		cout << endl;

		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				cout << B[j][k];
			}
			cout << endl;
		}
		cout << endl;


		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				cout << L[j][k];
			}
			cout << endl;
		}
		cout << endl;

		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				cout << R[j][k];
			}
			cout << endl;
		}
		cout << endl;
		*/
	}

	system("pause");
	return 0;
}
