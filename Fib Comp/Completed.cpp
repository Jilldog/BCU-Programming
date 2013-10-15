//This Code runs the Fibonacci Theory

#include <iostream>

using namespace std;

int main()
{
	unsigned int next;
	unsigned int current = 1;
	unsigned int previous = 0;
	int counter = 1;

	while (counter < 80)
	{
		next = current + previous;
		previous = current;
		current = next;
		counter++;
	}
	cout<< "80th: "<<current;
}