#pragma once

struct element
{
	int data = 0;
	element* next = NULL, * prev = NULL;
};

struct ring
{
	element* current = NULL;
};

void InitRing(ring* r, int d);
void PushNextRing(ring* r, int d);
void PushPrevRing(ring* r, int d);
int PopRing(ring* r);
int PeekRing(ring* const r);
void GoNextRing(ring* r);
void GoPrevRing(ring* r);
void PrintRing(ring* const r);
void DestroyRing(ring* r);
bool IsRingEmpty(ring* const r);
int GetSizeRing(ring* const r);
bool FindInRing(ring* const r, int d);


void CopyRing(ring* firstR, ring* secondR);
void DeleteK_Element(ring* const r, int d);