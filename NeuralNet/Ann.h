#pragma once
#define MaxNumber 11000
#define MaxLayers 5
#define MaxOutput 50
#define MaxInputX 150
#define MaxInputY 150
#define MaxNeurons 300
#define MaxInput 11000
class Ann
{
public:
	Ann(void);
	~Ann(void);
	char fName[300];
	void Load();
	int NinputX, NinputY, Noutput, Number, Ninput;
	int Type;   // 0 - bit,  1 - grey
	int Classes[MaxNumber];
	unsigned char *Data;     // выборка
	bool CalcInterrupt;
	int NumberLayers;
	int Epoch;
	float Delta;
	float Beta;
	int neurons[MaxLayers + 1];
	void Init();
	float W[MaxLayers][MaxInput][MaxNeurons];
	float X[MaxLayers][MaxInput];
	float Y[MaxLayers][MaxInput];
	float B[MaxLayers][MaxInput];
	float EW[MaxLayers][MaxInput][MaxNeurons];
	float EX[MaxLayers][MaxInput];
	float EY[MaxLayers][MaxInput];
	float EB[MaxLayers][MaxInput];
	float EWg[MaxLayers][MaxInput][MaxNeurons];
	void Forward();
	float Activate(float x);
	void CalcErr(int m);
	float Eri;
	void Backward(int d);
	float DifActivate(double x);
	void CorrectWeights(int d);
	int IsBias;
	int NumberGroups;
	int SizeGroup;
	void DistrInputs();
	int IndexGroup[MaxNumber];
	int GroupNumbers[2 * MaxNumber];
	void ClearDiff();
	void SumGrad();
	void CopySum();
	int TypeActivate;
};

