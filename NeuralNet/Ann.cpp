#include "stdafx.h"
#include "Ann.h"
#include <fstream>
#include <stdio.h>
#include <ctime>
Ann::Ann(void)
{
}

Ann::~Ann(void)
{
}

void Ann::Load()
{
	int i, j, y;
	FILE *fin;
	int z, n;
	unsigned char *c;
	fin = fopen(fName, "r");
	fscanf(fin, "%d", &Type);
	if (Type<2)
	{
		fscanf(fin, "%d %d %d %d", &NinputX, &NinputY, &Noutput, &Number);
		Ninput = NinputX*NinputY;
		Data = new unsigned char[Number*NinputX*NinputY]; // выборка, память под размер
		c = Data;
		n = 0;
		for (i = 0; i<Number; i++)
		{
			for (j = 0; j<Ninput; j++)
			{
				y = fscanf(fin, "%d ", &z);
				*c = z;
				c++;
			}
			fscanf(fin, "%d ", &z);
			Classes[i] = z;
		}
		fclose(fin);
	}
}
void Ann::Init()
{
	int i, j, k, m1, m2;
	float u, u1;
	srand((unsigned)time(0));
	for (i = 0; i <= NumberLayers + 1; i++)
	{
		for (j = 0; j <= Ninput; j++)
		{
			for (k = 0; k<MaxNeurons; k++)
			{
				u = (float)rand() / (RAND_MAX + 1) * 2 - 1;
				W[i][j][k] = u;
			}
		}
	}
	for (i = 0; i <= NumberLayers + 1; i++)
	{
		for (k = 0; k<Ninput; k++)
		{
			u = (float)rand() / (RAND_MAX + 1) * 2 - 1;
			B[i][k] = u;
		}
	}
}

void Ann::Forward()
{
	int k, i, j, m1, m2;
	for (k = 1; k <= NumberLayers + 1; k++)
	{
		m1 = neurons[k - 1];
		m2 = neurons[k];
		for (i = 0; i<m2; i++)
		{
			X[k][i] = 0;
			for (j = 0; j<m1; j++)
			{
				X[k][i] += Y[k - 1][j] * W[k - 1][j][i];
			}
			if (IsBias == 1)
			{
				X[k][i] += B[k - 1][i];
			}
			Y[k][i] = Activate(X[k][i]);
		}
	}
}

float Ann::Activate(float x)
{
	if (TypeActivate == 1)
	{
		return 1.0 / (1 + exp(-Beta*x));
	}
	if (TypeActivate == 2)
	{
		return (exp(x) - exp(-x)) / (exp(x) + exp(-x));
	}
	// 3
	if (x<0)
		return 0;
	else
		return x;
}

void Ann::CalcErr(int m)
{
	int i, n, p;
	float z;
	n = neurons[NumberLayers + 1];
	Eri = 0.0;
	p = Classes[m];
	for (i = 0; i<n; i++)
	{
		z = Y[NumberLayers + 1][i];
		if (p - 1 == i)
		{
			Eri += (z - 1)*(z - 1) / 2.0;
		}
		else
		{
			Eri += z*z / 2.0;
		}
	}
}
void Ann::Backward(int d)
{
	int k, m1, m2, i, p, n;
	float z;
	for (k = NumberLayers + 1; k >= 1; k--)
	{
		m2 = neurons[k];
		m1 = neurons[k + 1];
		if (k == NumberLayers + 1)
		{
			p = Classes[d];

			for (i = 0; i<m2; i++)
			{
				z = Y[k][i];
				if (p - 1 == i)
				{
					EY[k][i] = z - 1;
				}
				else
				{
					EY[k][i] = z;
				}
			}
		}
		else
		{
			m1 = neurons[k + 1];
			for (i = 0; i<m2; i++)
			{
				EY[k][i] = 0;
				for (n = 0; n<m1; n++)
				{
					EY[k][i] += EX[k + 1][n] * W[k][i][n];
				}
			}
		}
		// EX
		for (i = 0; i<m2; i++)
		{
			EX[k][i] = EY[k][i] * DifActivate(Y[k][i]);
		}
		// EW
		m1 = neurons[k - 1];
		for (n = 0; n<m1; n++)
		{
			for (i = 0; i<m2; i++)
			{
				EW[k - 1][n][i] = EX[k][i] * Y[k - 1][n];
			}
			if (IsBias == 1)
				for (i = 0; i<m2; i++)
				{
					EB[k - 1][i] = EX[k][i];
				}
		}
	}
}

float Ann::DifActivate(double x)
{
	if (TypeActivate == 1)
	{
		return Beta*x*(1 - x);
	}
	if (TypeActivate == 2)
	{
		float y;
		y = (exp(x) - exp(-x)) / (exp(x) + exp(-x));
		return 1 - y*y;
	}
	// 3
	if (x<0)
		return 0;
	else
		return 1;
}

void Ann::CorrectWeights(int d)
{
	int i, j, k, m1, m2;
	for (k = 0; k<NumberLayers + 1; k++)
	{
		m1 = neurons[k];
		m2 = neurons[k + 1];
		for (i = 0; i<m1; i++)
		{
			for (j = 0; j<m2; j++)
			{
				W[k][i][j] -= Delta*EW[k][i][j];///Number;
			}
			if (IsBias == 1)
			{
				for (j = 0; j<m2; j++)
				{
					B[k][j] -= Delta*EB[k][j];///Number;
				}
			}
		}
	}
}

void Ann::DistrInputs()
{
	int Nd;
	int i, j, k, m, n, z;
	NumberGroups = Number / SizeGroup;
	Nd = Number - NumberGroups*SizeGroup;

	srand((unsigned)time(0));
	n = 0;
	j = 0;
	k = Number;
	for (i = 0; i<Number; i++)
	{
		IndexGroup[i] = i;
	}

	for (i = 0; i<NumberGroups; i++)
	{
		j = 0;
		while (j<SizeGroup)
		{
			m = (double)rand() / (RAND_MAX + 1) * k;
			GroupNumbers[n] = IndexGroup[m];
			for (z = m; z<k - 1; z++)
			{
				IndexGroup[z] = IndexGroup[z + 1];
			}
			n++;
			k--;
			j++;
		}
		GroupNumbers[n] = 0;
		n++;
	}
	for (i = 0; i<Nd; i++)
	{
		GroupNumbers[n] = IndexGroup[i];
		n++;
	}
	GroupNumbers[n] = 0;
	n++;
}

/*
for(i=0;i<Number;i++)
{
IndexGroup[i]=-1;
}

for(i=0;i<NumberGroups;i++)
{
j=0;
while(j<SizeGroup)
{
m=(double)rand() / (RAND_MAX + 1) * Number;
if(IndexGroup[m]==-1)
{
IndexGroup[m]=i;
j++;
}
}
}
for(i=0;i<Number;i++)
{
if(IndexGroup[i]==-1)
{
IndexGroup[i]=NumberGroups;
}
}
}
*/

void Ann::ClearDiff()
{
	int i, j, k;
	for (i = 0; i <= NumberLayers + 1; i++)
	{
		for (j = 0; j<Ninput; j++)
		{
			for (k = 0; k<MaxNeurons; k++)
			{
				EWg[i][j][k] = 0;
			}
		}
	}
}

void Ann::SumGrad()
{
	int i, j, k;
	for (i = 0; i <= NumberLayers + 1; i++)
	{
		for (j = 0; j<Ninput; j++)
		{
			for (k = 0; k<MaxNeurons; k++)
			{
				EWg[i][j][k] += EW[i][j][k];
			}
		}
	}
}

void Ann::CopySum()
{
	int i, j, k;
	for (i = 0; i <= NumberLayers + 1; i++)
	{
		for (j = 0; j<Ninput; j++)
		{
			for (k = 0; k<MaxNeurons; k++)
			{
				EW[i][j][k] = EWg[i][j][k] / SizeGroup;
			}
		}
	}
}
