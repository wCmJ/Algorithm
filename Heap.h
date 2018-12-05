#pragma once
template<class T>
void Heap_Maximum_Node(T *data, int i, int len) {
	int max = i;
	if (2 * i + 1 < len && data[2 * i + 1] > data[max]) {
		max = 2 * i + 1;
	}
	if (2 * i + 2 < len && data[2 * i + 2] > data[max]) {
		max = 2 * i + 2;
	}
	if (max != i) {
		T tmp = data[max];
		data[max] = data[i];
		data[i] = tmp;
		Heap_Maximum_Node(data, max,len);
	}
}

template<class T>
void Heap_Maximum_Construct(T *data, size_t len) {
	for (int i = len / 2; i >= 0; i--) {
		Heap_Maximum_Node<T>(data, i, len);
	}
}

template<class T>
void Heap_Minimum_Node(T *data, int i, int len) {
	int min = i;
	if (2 * i + 1 < len && data[2 * i + 1] < data[min]) {
		min = 2 * i + 1;
	}
	if (2 * i + 2 < len && data[2 * i + 2] < data[min]) {
		min = 2 * i + 2;
	}
	if (min != i) {
		T tmp = data[min];
		data[min] = data[i];
		data[i] = tmp;
		Heap_Minimum_Node(data, min, len);
	}
}

template<class T>
void Heap_Minimum_Construct(T *data, size_t len) {
	for (int i = len / 2; i >= 0; i--) {
		Heap_Minimum_Node<T>(data, i, len);
	}
}





