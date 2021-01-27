// Task 1 - Напишите функцию, которая обычно принимает аргумент - адрес строки и выводит
//			эту строку один раз. Однако если задан второй аргумент типа int, не равный нулю,
//			то эта функция выводит строку столько раз, сколько было осуществлено вызовов этой
//			функции к моменту данного вызова. (Обратите внимание, что количество выводимых строк
//			не равно значению второго аргумента, оно равно числу вызовов функции к моменту
//			последнего вызова.)

#include <iostream>
#include <string>

void show(const std::string s1);
void show(const std::string s2, const size_t n);

int main(void)
{
	using namespace std;
	
	size_t count = 0;
	string word;
	cout << "Enter anything string ";
	getline(cin, word);

	show(word);
	++count;
	show(word);
	++count;
	show(word, count);

	cout << "Executed!" << endl;

	return 0;

}

void show(const std::string s1)
{
	std::cout << "Word: " << s1 << std::endl;
}

void show(const std::string s2, const size_t n)
{
	size_t index = 0;
	while (index < n)
	{
		std::cout << "Overloaded function word: " << s2 << std::endl;
		--n;
	}

}

// Task 2 - Структура CandyBar содержит три члена. Первый член хранит название коробки конфет.
//			Второй - её вес (который может иметь дробную часть), а третий - количество калорий
//			(целое значение). Напишите программу, использующую функцию, которая принимает
//			в качестве аргументов ссылку на CandyBar, указатель на char, значение double и 
//			значение int. Функция использует три последних значения для установки соответствующих
//			членов структуры. Три последних аргумента должны иметь значения по умолчанию:
//			"Millennium Munch", 2.85 и 350. Кроме того, программа должна ииспользовать
//			функцию, которая принимает в качестве аргумента ссылку на CandyBar и отображает содержимое
//			этой структуры.

#include <iostream>
#include <string>

struct CandyBar
{
	std::string name;
	double weight;
	int callories;
};

void set(CandyBar & s1, std::string name = "Millennium Munch", double weight = 2.85, int callories = 350);
void show(const CandyBar &);

int main(void)
{
	using namespace std;
	CandyBar box;

	set(box);
	show(box);
	cout << "Executed" << endl;

	return 0;

}

void show(const CandyBar & s2)
{
	using namespace std;
	cout << "name: " << s2.name << endl;
	cout << "weight: " << s2.weight << endl;
	cout << "callories: " << s2.callories << endl;
}

void set(CandyBar & s1, std::string name, double weight, int callories)
{
	s1.name = name;
	s1.weight = weight;
	s1.callories = callories;
}



// Task 3 - Напишите функцию, которая принимает ссылку на объект string в качестве
//			параметра и преобразует содержимое string в символы верхнего регистра.
//			Используйте функцию toupper(). Напишите программу, использующую цикл, которая
//			позволяет проверить работу функции для разного ввода

#include <iostream>
#include <string>
#include <cctype>

void change(std::string & s2);
void show(const std::string & s2);

int main()
{
	using namespace std;

	bool flag = true;
	string word;
	cout << "Enter a string" << endl;

	while (getline(cin, word) && word != "q")
	{
		for (int k = 0; k < word.size(); ++k)
		{
			if (isalpha(word[k]))
			{
				flag = true;
			}
			else
			{
				flag = false;
				break;
			}

		}
		if (flag)
		{
			change(word);
			show(word);
		}
		else
		{
			cout << "Enter a correct string" << endl;
			continue;
		}
		cout << "Enter a string yet" << endl;
	}
}

void change(std::string & s2)
{
	using namespace std;
	for (int i = 0; i < s2.size(); ++i)
		s2[i] = toupper(s2[i]);
}

void show(const std::string & s2)
{
	std::cout << s2 << std::endl;
}