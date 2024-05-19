#include<iostream>

using namespace std;

int main() {

	int index = 0;

	char student_answers[100000],teacher_answers[100000];
	int num = 0;
	cin >> index;

	for (int i = 0; i < index; i++)
	{
		cin >> student_answers[i];
	}

	for (int i = 0; i < index; i++)
	{
		cin >> teacher_answers[i];
	}

	for (int i = 0; i < index; i++)
	{
		if (student_answers[i] == teacher_answers[i])
		{
			num++;
		}
	}

	cout << num << endl;
	return 0;
}