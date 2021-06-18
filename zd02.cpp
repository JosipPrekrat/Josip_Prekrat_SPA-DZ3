#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

struct Tocka {
	int row;
	int colum;
	char z;
};

void refreh()
{
	printf("Press enter to for next step");
	getchar();
	system("cls");
}

Tocka gore(Tocka& a) {
	a.row--;
	return a;
}

Tocka dole(Tocka& a) {
	a.row++;
	return a;
}

Tocka lijevo(Tocka& a) {
	a.colum--;
	return a;
}

Tocka desno(Tocka& a) {
	a.colum++;
	return a;
}


Tocka nova_tocka(Tocka& a, Tocka& b, Tocka& curr) {

	Tocka zid[10];
	int z1_row = 0;
	int z2_row = 10;
	int z1_col = 12;
	int z2_col = 0;

	for (int i = 0; i < 10; i++)
	{
		zid[i].row = z1_row + 1;
		zid[i].colum = z1_col;
		zid[i].z = '*';
	}


	Tocka d = desno(curr);
	Tocka l = lijevo(curr);


	if (curr.colum < b.colum)
	{

		if (d.colum == z1_col && d.row <= z2_row)
		{
			curr = dole(curr);
		}
		else
		{
			curr = desno(curr);
		}
	}

	if (curr.colum > b.colum)
	{
		if (l.colum == z1_col && l.row <= z2_col)
		{
			curr = dole(curr);
		}
		else
		{
			curr = lijevo(curr);
		}
	}
	else if (curr.row < b.row && curr.colum == b.colum)
	{
		curr = dole(curr);
	}
	else if (curr.row > b.row && curr.colum == b.colum)
	{
		curr = gore(curr);
	}

	return curr;
}


void crtaj(Tocka& a, Tocka& b, Tocka& c)
{
	Tocka zid[10];
	int z1_row = 0;
	int z2_row = 10;
	int z1_col = 12;
	int z2_col = 0;

	for (int i = 0; i < 10; i++)
	{
		zid[i].row = z1_row + 1;
		zid[i].colum = z1_col;
		zid[i].z = '*';
	}
	const int row = 20;
	const int colum = 40;
	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= colum; j++)
		{
			if (i <= z2_row && j == z1_col)
			{
				cout << "*";
			}
			if (i > z2_row && j == z1_col)
			{
				cout << "-";
			}
			if (i == c.row && j == c.colum)
			{
				cout << "x";
			}
			else if (i == b.row && j == b.colum)
			{
				cout << "B";
			}
			else if (i == a.row && j == a.colum)
			{
				cout << "A";
			}
			else
			{
				cout << "-";
			}
		}
		cout << endl;
	}
}

int main() {

	Tocka a;
	Tocka b;
	Tocka curr;
	Tocka nova;
	int x = 100;

	cout << "redak A: ";
	cin >> a.row;
	cout << "stupac A: ";
	cin >> a.colum;

	cout << "redak B: ";
	cin >> b.row;
	cout << "stupac B: ";
	cin >> b.colum;

	curr.row = a.row;
	curr.colum = a.colum;
	crtaj(a, b, curr);
	refreh();

	for (int i = 0; i < x; i++)
	{
		nova = nova_tocka(a, b, curr);
		curr = nova;
		crtaj(a, b, curr);
		refreh();

		if (curr.row == b.row && curr.colum == b.colum)
		{
			return 1;
		}
	}

	return 0;
}