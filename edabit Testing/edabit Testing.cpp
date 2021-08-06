// edabit Testing.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include <string>
#include <algorithm>

struct PairVal
{
	PairVal();
	PairVal(int iz, int in);
	int z = 0;
	int n = 1;
	float v = 0;
	void setDiv();
	float getDiv()const;
};

PairVal::PairVal()
{
}

PairVal::PairVal(int iz, int in)
{
	z = iz;
	if (in > 0) {
		n = in;
	}
	else n = 1;
}


void PairVal::setDiv()
{
	v = (float)z / (float)n;
	return;
}

float PairVal::getDiv()const
{
	return (float)z / (float)n;
}

bool compPairVal(PairVal lhs, PairVal rhs) { return lhs.v < rhs.v; }

void doFarey(int in) {
	PairVal list[100];
	bool check = true;
	int index = 0;
	float div = 0;
	for (int n = 1; n <= in; n++) {
		for (int z = 0; z <= n; z++) {
			div = (float)z / (float)n;
			check = true;
			for (int c = 0; c < index; c++) {
				if (n > 1 && div == list[c].v && n > list[c].n) {
					check = false;
					break;
				}
			}
			if (check) {
				list[index].n = n;
				list[index].z = z;
				list[index].setDiv();
				index++;
			}
		}
	}

	std::sort(list, list+index , compPairVal);

	for (int i = 0; i < index; i++) {
		std::cout << std::to_string(list[i].z) << "/" << std::to_string(list[i].n) << " val:" << std::to_string(list[i].v) << '\n';
	}
	return;
}


int main()
{
	int n = 0;
	do {
		std::cin >> n;
		doFarey(n);
	} while (true);
}
