#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

struct car
{
	string loaiXe;
	int soDangKy = 0;
};

struct InforOfCar
{
	car* xe;
	InforOfCar* next;
};

struct Queue
{
	InforOfCar* front;
	InforOfCar* rear;
	int cout;
	const int Max = 3;
};

int random(int minN, int maxN) {
	return minN + rand() % (maxN + 1 - minN);
}

car* thongtinxe()	
{
	car* xe = new car;
	int r = random(1, 4);
	switch (r) {
	case 1:
		xe->loaiXe = "xe Tai";
		break;
	case 2:
		xe->loaiXe = "xe Khach";
		break;
	case 3:
		xe->loaiXe = "xe Con";
		break;
	case 4:
		xe->loaiXe = "xe Container";
		break;
	}
	xe->soDangKy = random(1, 100);
	return xe;
}

InforOfCar* createNode(car* data)
{
	InforOfCar* p = new InforOfCar;
	if (p == NULL)
	{
		cout << "Day bo nho" << endl;
		exit(1);
	}

	else
	{
		p->xe = data;
		p->next = NULL;
	}
	return p;
}

void InIt(Queue& queue)
{
	queue.front = NULL;
	queue.rear = NULL;
	queue.cout = 0;
}

bool IsFull(Queue& queue)
{
	return queue.cout == queue.Max;
}

bool IsEmty(Queue queue)
{
	return queue.front == NULL;
}

void EnQueue(Queue& queue, InforOfCar* p)
{
	if (IsEmty(queue))
	{
		queue.front = p;
	}
	else 
		queue.rear->next = p;
	queue.rear = p;
	queue.cout++;
}

void Dequeue(Queue& queue)
{
	if (IsEmty(queue))
		exit(1);
	else
	{
		InforOfCar* p = queue.front;
		if (queue.front == queue.rear)
			queue.rear = queue.front = NULL;
		queue.front = p->next;
		cout << "Loai xe: " << p->xe->loaiXe
			<< " So dang ky: " << p->xe->soDangKy << endl;
		delete p;
		queue.cout--;
	}
}

void CarIn(Queue& queue)
{
	int r = random(0, 3);
	InIt(queue);
	for (int i = 0; i < r; i++)
		EnQueue(queue, createNode(thongtinxe()));
}

void DisPlay(Queue queue)
{
	if (IsEmty(queue))
	{
		cout << "Khong co xe o hang doi" << endl;
	}
	InforOfCar* p = queue.front;
	while (p != NULL)
	{
		cout << "Loai xe " << p->xe->loaiXe << "\nSo dang ky " << p->xe->soDangKy << " ";
		p = p->next;
	}
}

int main()
{
	srand((int)time(NULL));
	Queue queue;
	InIt(queue);
	while (true)
	{
		CarIn(queue);
		Dequeue(queue);
	}
	system("Pause");
	return 0;
}