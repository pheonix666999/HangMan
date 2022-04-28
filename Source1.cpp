#include<SFML\Graphics.hpp>
#include<iostream>
#include<conio.h>
using namespace std;
void main()
{
	char word[30];
	int i, count = 0, x = 0,right = 0,wrong = 0,z = 0;
	std::cout << "                                             THIS IS HANGMAN!!";
	std::cout << "\n";
	cout << "                                               DON'T ENTER A WORD TWICE!";
	cout << endl;
	std::cout << "                                          IT IS A TWO PLAYER GAME.";
	std::cout << "\n";
	std::cout << "                               ONE WILL ENTER THE WORD THE OTHER WILL GUESS IT.";
	std::cout << "\n";
	std::cout << "ENTER WORD MINIMUM LENGTH SHOULD BE FIVE LETTERS(WHEN DONE PRESS SPACE): ";
	for (i = 0; i < 30; i++)
	{
		word[i] = _getch();
		count++;
		if (word[i] == ' ')
			break;
		cout << word[i];
	}
	count = count - 1;
	cout << endl;
	char places[30];
	int j;
	for (i = 0; i < count; i++)
	{
		places[i] = '_';
	}
	cout << "GUESS THE WORD.    ";
	for (i = 0; i < count; i++)
	{
		cout << places[i];
		cout << " ";
	}
	char input;
	int temp = count;
	sf::RenderWindow window(sf::VideoMode(400, 400), "HANGMAN", sf::Style::Resize | sf::Style::Close);
	sf::Vertex phansi[] = {
		sf::Vertex(sf::Vector2f(200,0)),
		sf::Vertex(sf::Vector2f(200,50))
	};
	sf::Vertex body[] = {
		sf::Vertex(sf::Vector2f(200,100)),
		sf::Vertex(sf::Vector2f(200,150))
	};
	sf::Vertex arm1[] = {
		sf::Vertex(sf::Vector2f(200,100)),
		sf::Vertex(sf::Vector2f(175,150))
	};
	sf::Vertex arm2[] = {
		sf::Vertex(sf::Vector2f(200,100)),
		sf::Vertex(sf::Vector2f(225,150))
	};
	sf::Vertex leg1[] = {
	sf::Vertex(sf::Vector2f(200,150)),
	sf::Vertex(sf::Vector2f(175,200))
	};
	sf::Vertex leg2[] = {
	sf::Vertex(sf::Vector2f(200,150)),
	sf::Vertex(sf::Vector2f(225,200))
	};

	sf::CircleShape head(25);

	head.setFillColor(sf::Color::Black);
	head.setOutlineColor(sf::Color::White);
	head.setOutlineThickness(-1);
	head.setPosition(175, 50);
	window.draw(phansi, 2, sf::Lines);
	window.display();

		while (temp != 0)
		{
			cout << endl << "ENTER LETTER: ";
			cin >> input;

			for (i = 0; i < count; i++)
			{
				/*if (i == x)
					i++;*/
				if (input == word[i])
				{
					x = i;
					places[i] = input;
					system("CLS");
					for (j = 0; j < count; j++)
					{
						cout << places[j];
						cout << " ";
					}
					temp--;
					right++;
				}
			}
			for (i = 0; i < count; i++)
			{
				if (input != word[i])
				{
					z++;
				}
			}
			if (z == count)
			{
				wrong += z;
				z = 0;
			}
			else
			{
				z = 0;
			}
			if (wrong == count)
			{
				window.draw(phansi, 2, sf::Lines);
				window.draw(head);
				window.display();
				
			}
			if (wrong == count * 2)
			{
				window.draw(phansi, 2, sf::Lines);
				window.draw(head);
				window.draw(body, 2, sf::Lines);
				window.display();
				
			}
			if (wrong == count * 3)
			{
				window.draw(phansi, 2, sf::Lines);
				window.draw(head);
				window.draw(body, 2, sf::Lines);
				window.draw(arm1, 2, sf::Lines);
				window.display();
			
			}
			if (wrong == count * 4)
			{
				window.draw(phansi, 2, sf::Lines);
				window.draw(head);
				window.draw(body, 2, sf::Lines);
				window.draw(arm1, 2, sf::Lines);
				window.draw(arm2, 2, sf::Lines);
				window.display();
				
			}
			if (wrong == count * 5)
			{
				window.draw(phansi, 2, sf::Lines);
				window.draw(head);
				window.draw(body, 2, sf::Lines);
				window.draw(arm1, 2, sf::Lines);
				window.draw(arm2, 2, sf::Lines);
				window.draw(leg1, 2, sf::Lines);
				window.display();
			
			}
			if (wrong == count * 6)
			{
				window.draw(phansi, 2, sf::Lines);
				window.draw(head);
				window.draw(body, 2, sf::Lines);
				window.draw(arm1, 2, sf::Lines);
				window.draw(arm2, 2, sf::Lines);
				window.draw(leg1, 2, sf::Lines);
				window.draw(leg2, 2, sf::Lines);
				window.display();
				temp = 0;
			}
		}
		if (right == count)
		{
			system("CLS");
			cout << "YOU WIN!!";
			cout << endl << "THE WORD: ";
			for (j = 0; j < count; j++)
			{
				cout << places[j];
				cout << " ";
			}
			wrong = 0;
			window.display();
		}
		if (wrong == count * 6)
		{
			system("CLS");
			cout << "YOU LOSE!!";
			cout << endl << "THE WORD: ";
			for (j = 0; j < count; j++)
			{
				cout << word[j];
				cout << " ";
			}
			window.display();
		}
}