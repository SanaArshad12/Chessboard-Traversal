#include "Traversal.h"
#include<iostream>
using namespace std;
Traversal::Traversal() {
	this->vertices = 64;
	this->Matrix = new int* [this->vertices];
	for (int i = 0; i < this->vertices; i++) {
		this->Matrix[i] = new int[this->vertices];
		for (int j = 0; j < this->vertices; j++) {
			this->Matrix[i][j] = 0;
		}
	}
	visited = new bool[this->vertices];
	for (int i = 0; i < this->vertices; i++) {
		this->visited[i] = false;
	}
}
void Traversal::AddEdge(int row, int col) {
	Matrix[row][col] = 1;
	Matrix[col][row] = 1;
}
void Traversal::AddChessBoardEdges() {
	int rows = 8;
	int cols = 8;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			int currentIndex = i * cols + j;

			if (i > 0) AddEdge(currentIndex, (i - 1) * cols + j);
			if (i < rows - 1) AddEdge(currentIndex, (i + 1) * cols + j);
			if (j > 0) AddEdge(currentIndex, i * cols + (j - 1));
			if (j < cols - 1) AddEdge(currentIndex, i * cols + (j + 1));

			if (i > 0 && j > 0) AddEdge(currentIndex, (i - 1) * cols + (j - 1));
			if (i > 0 && j < cols - 1) AddEdge(currentIndex, (i - 1) * cols + (j + 1));
			if (i < rows - 1 && j > 0) AddEdge(currentIndex, (i + 1) * cols + (j - 1));
			if (i < rows - 1 && j < cols - 1) AddEdge(currentIndex, (i + 1) * cols + (j + 1));
		}
	}
}

void Traversal::Display(int current) {
	int count = -1;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			count++;
			if (count == current) {
				cout << "(" << i << "," << j << ")" << "	";

				break;
			}

		}
	}

}

int Traversal::getStartVertex(int r, int c) {
	int count = -1;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			count++;
			if (r == i && c == j) {
				return count;
			}

		}
	}
	return -1;
}
void Traversal::BreadthFirstSearch() {
	int row;
	int col;
	
	cout << "Enter row : ";
	do {
		cin >> row;
		if (row < 0 || row > 7) {
			cout << "Enter a number between 0 and 7:  ";
		}
	} while (row < 0 || row > 7);

	cout << "Enter col : ";
	do {
		cin >> col;
		if (col < 0 || col > 7) {
			cout << "Enter a number between 0 and 7:  ";
		}
	} while (col < 0 || col > 7);

	cout << endl;
	int startVertex = getStartVertex(row, col);
	visited[startVertex] = true;
	q.Enqueue(startVertex);

	while (!q.IsEmpty()) {
		int currentVertex = q.Dequeue();
		Display(currentVertex);

		for (int i = 0; i < this->vertices; ++i) {
			if (this->Matrix[currentVertex][i] == 1 && !this->visited[i]) {
				this->visited[i] = true;
				q.Enqueue(i);
			}
		}
	}
	cout << endl;
	cout << endl;
	cout << endl;
}