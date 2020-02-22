#include <vector>
#include <iterator>
#include <iostream>
#include <string>

void input(std::vector<std::string>*);
void setup(std::vector<std::string>*, std::vector<std::string>*);
void edit(std::vector<std::string>*, std::vector<std::string>*, int);
void ins(std::vector<std::string>*, std::vector<std::string>*, int);
void del(std::vector<std::string>*, std::vector<std::string>*, int);
void loop(std::vector<std::string>*, std::vector<std::string>*, int);

int main()
{
	std::vector<std::string> text;
	input(&text);
	
	std::vector<std::string> line;
	setup(&text, &line);

	return 0;
}

void input(std::vector<std::string>* text)
{
	std::cout << "Input strings:\n";
	std::string s;
	do
	{
		getline(std::cin, s);
		s.push_back('\t');
		text->push_back(s);
	} while (s.length() > 1);
	text->pop_back();
}

void setup(std::vector<std::string>* text, std::vector<std::string>* line)
{	
	system("cls");
	std::cout << "Your text:\n";
	copy(text->begin(), text->end(), std::ostream_iterator<std::string>(std::cout, "\n"));

	std::cout << "Choose a line to change: ";
	int n;
	std::cin >> n;
	std::string s = (*text)[n];
	line->clear();

	do
	{
		line->push_back(s.substr(0, s.find("\t")));
		s = s.substr(s.find("\t") + 1);
	} while (s.length() > 1);

	std::cout << "\nYour line:\n";
	copy(line->begin(), line->end(), std::ostream_iterator<std::string>(std::cout, "\t"));
	std::cout << "\n";

	loop(text, line, n);
}

void del(std::vector<std::string>* text, std::vector<std::string>* line, int n)
{
	int x;
	std::cout << "Which one? ";
	std::cin >> x;
	line->erase(line->begin() + x);

	system("cls");
	copy(line->begin(), line->end(), std::ostream_iterator<std::string>(std::cout, "\t"));
	std::cout << "\n";

	(*text)[n].clear();
	for (int i = 0; i != line->size(); ++i)
		(*text)[n] += (*line)[i]+"\t";

	loop(text, line, n);
}

void ins(std::vector<std::string>* text, std::vector<std::string>* line, int n)
{
	int x;
	std::string s;
	std::cout << "Where to? ";
	std::cin >> x;
	std::cout << "Input a word: ";
	std::cin >> s;
	line->insert(line->begin() + x, s);

	system("cls");
	copy(line->begin(), line->end(), std::ostream_iterator<std::string>(std::cout, "\t"));
	std::cout << "\n";

	(*text)[n].clear();
	for (int i = 0; i != line->size(); ++i)
		(*text)[n] += (*line)[i] + "\t";

	loop(text, line, n);
}

void edit(std::vector<std::string>* text, std::vector<std::string>* line, int n)
{
	int x;
	std::string s;
	std::cout << "Which one? ";
	std::cin >> x;
	std::cout << "Edit: ";
	std::cin >> s;
	(*line)[x] = s;

	system("cls");
	copy(line->begin(), line->end(), std::ostream_iterator<std::string>(std::cout, "\t"));
	std::cout << "\n";

	(*text)[n].clear();
	for (int i = 0; i != line->size(); ++i)
		(*text)[n] += (*line)[i] + "\t";

	loop(text, line, n);
}

void loop(std::vector<std::string>* text, std::vector<std::string>* line, int n)
{
	int c;
	std::cout << "What do you want?\n1.delete a cell\t2.insert a cell\t3.edit a cell\t4.change a line\n0.exit\n";
	std::cin >> c;
	switch (c)
	{
	case 1: del(text, line, n);
	case 2: ins(text, line, n);
	case 3: edit(text, line, n);
	case 4: setup(text, line);
	case 0: exit(0);
	}
}
