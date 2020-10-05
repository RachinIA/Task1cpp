#include "Figure.h"
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <memory>

using namespace std;

bool comp(unique_ptr<Curve>& first, unique_ptr<Curve>& second)   //For sorting
{
	return first->getArea() < second->getArea();
} 

double random(double max)   //Random double
{
	double n = (double)rand() / RAND_MAX;
	return 0.0 + n * (max);
} 

int main()
{
	double sumOfAreas = 0;  //Total area
	vector <unique_ptr<Curve>> curves;  //Vector

	srand(time(0));

	for (int i = 0; i < 20; i++)  //Filling vector
		if (rand() % 11 < 5)
		{
			curves.emplace_back(make_unique<Ellipse>(random(50),random(50)));
		}
		else
		{
			curves.emplace_back(make_unique<Circle>(random(50)));
		}

	sort(curves.begin(), curves.end(), comp);  //Sorting 

	int k = 1;
	for (vector <unique_ptr<Curve>>::iterator i = curves.begin(); i != curves.end(); ++i) //Output of areas
	{
		cout << k << ")" << (*i)->getArea() << "\t";
		if (k % 5 == 0)
			cout << endl;
		k++;
	}

	for (vector <unique_ptr<Curve>>::iterator i = curves.begin(); i != curves.end(); ++i)  //Get total area
	{
		sumOfAreas += (*i)->getArea();
	}

	printf("\nTotal area of all circles - %.2f\n",sumOfAreas);
	system("pause");
	return 0;
}