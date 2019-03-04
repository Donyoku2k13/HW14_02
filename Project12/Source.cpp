#include <iostream>
#include <random>
#include <chrono>
#include <cstdlib>

using namespace std;

int min10(int a[100], int n, int &p)
{
	int s = 0;
	for (int i = n; i < n + 10; ++i) s += a[i];
	cout << "n: " << n << "; s: " << s << endl;
	if (100 - n == 10)
	{
		p = n;
		return s;
	}
	else
	{
		int s1 = min10(a, n + 1, p);
		if (s <= s1)
		{
			p = n;
			return s;
		}
		else return s1;
	}
}

int main()
{

	//task 1.Ќапишите рекурсивную функцию, котора€ принимает одномерный массив из 100 целых чисел заполненных случайным образом и находит позицию, с которой начинаетс€ последовательность из 10 чисел, сумма которых минимальна.
	int a[100];
	int p;

	std::default_random_engine generator(std::chrono::system_clock::now().time_since_epoch().count());
	std::uniform_int_distribution<int> rnd(-100, 100);

	for (int i = 0; i < 100; ++i) a[i] = rnd(generator);
	for (int i = 0; i < 100; ++i) cout << a[i] << '\t';
	cout << endl << endl;

	min10(a, 0, p);

	cout << "Minimum position: " << p << endl << endl;


	//task2.	Ќапишите рекурсивную функцию, котора€ заполн€ет матрицу по спирали
	int n, ar[100][100], z = 1;
	printf("input n\n");
	scanf("%d", &n);
	int iu = 0, id = n - 1, jl = 0, jr = n - 1;
	int i, j;
	while (z <= n * n)
	{
		for (i = id; i >= iu; i--)
			ar[i][jl] = z++;
		jl++;
		if (z > n*n) break;

		for (i = jl; i <= jr; i++)
			ar[iu][i] = z++;
		iu++;
		if (z > n*n) break;

		for (i = iu; i <= id; i++)
			ar[i][jr] = z++;
		jr--;
		if (z > n*n) break;

		for (i = jr; i >= jl; i--)
			ar[id][i] = z++;
		id--;
		if (z > n*n) break;

	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - 1; j++)
			printf("%02d ", ar[i][j]);
		printf("%02d\n", ar[i][n - 1]);
	}


	system("pause");
}