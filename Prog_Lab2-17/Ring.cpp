#include <stdlib.h>
#include <stdio.h>
#include "Ring.h"


void InitRing(ring* r, int d)
{
	element* e = (element*)malloc(sizeof(element));
	e->data = d;
	e->next = e;
	e->prev = e;
	r->current = e;
}

void PushNextRing(ring* r, int d)
{
	if (IsRingEmpty(r))
	{
		InitRing(r, d);
		return;
	}

	element* e =(element*)malloc(sizeof(element));
	e->data = d;
	e->next = r->current->next;
	e->prev = r->current;
	r->current->next = e;
	e->next->prev = e;
}

void PushPrevRing(ring* r, int d)
{
	if (IsRingEmpty(r))
	{
		InitRing(r, d);
		return;
	}

	element* e = (element*)malloc(sizeof(element));
	e->data = d;
	e->next = r->current;
	e->prev = r->current->prev;
	r->current->prev->next = e;
	r->current->prev = e;
}

int PopRing(ring* r)
{
	if (IsRingEmpty(r))
		return INT_MAX;

	int d = r->current->data;

	if (r->current == r->current->next)
	{
		free(r->current);
		r->current = NULL;
		return d;
	}

	element* e = r->current;
	r->current->prev->next = r->current->next;
	r->current->next->prev = r->current->prev;
	r->current = r->current->next;
	free(e);
	return d;
}

int PeekRing(ring* const r)
{
	if (IsRingEmpty(r))
		return INT_MAX;

	return r->current->data;
}

void GoNextRing(ring* r)
{
	r->current = r->current->next;
}

void GoPrevRing(ring* r)
{
	r->current = r->current->prev;
}

void PrintRing(ring* const r)
{
	if (IsRingEmpty(r))
		return;

	printf_s("<-> %d <-> ", r->current->data);

	if (r->current == r->current->next)
	{
		printf_s("\n");
		return;
	}

	for (element* i = r->current->next; i != r->current; i = i->next)
		printf_s("%d <-> ", i->data);

	printf_s("\n");
}

void DestroyRing(ring* r)
{
	while (PopRing(r) != INT_MAX);
}

bool IsRingEmpty(ring* const r)
{
	return r->current == NULL;
}

int GetSizeRing(ring* const r)
{
	int size = 0;
	if (IsRingEmpty(r))
		return 0;


	++size;
	if (r->current == r->current->next)
		return size;

	for (element* i = r->current->next; i != r->current; i = i->next)
		size++;

	return size;
}

bool FindInRing(ring* const r, int d)
{
	if (IsRingEmpty(r))
		return 0;

	if (r->current == r->current->next)
		return r->current->data == d;

	if (r->current->data == d)
		return 1;

	for (element* i = r->current->next; i != r->current; i = i->next)
		if (i->data == d)
			return 1;

	return 0;
}

void CopyRing(ring* firstR, ring* secondR)
{
	if (IsRingEmpty(firstR))
		return;

	PushNextRing(secondR, firstR->current->data);

	for (element* i = firstR->current->next; i != firstR->current; i = i->next)
	{
		GoNextRing(secondR);
		PushNextRing(secondR, i->data);
	}
	GoNextRing(secondR);
	GoNextRing(secondR);
}

void DeleteK_Element(ring* const r, int k)
{
	if (IsRingEmpty(r))
	{
		printf_s("Your ring is empty.\n");
		return;
	}

	ring newRing = {NULL};

	CopyRing(r, &newRing);

	printf_s("Elements are removed in the following order: ");

	while (!IsRingEmpty(&newRing))
	{
		for (int i = 0; i <= k; i++)
			GoNextRing(&newRing);
		printf_s("%d - ", PopRing(&newRing));
	}
	printf_s("\b\b  \n");

	PrintRing(&newRing);

	DestroyRing(&newRing);
}