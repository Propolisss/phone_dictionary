#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>

bool is_correct_phone_number(const std::string st)
{
	if (st.size() != 12)
	{
		std::cout << "������������ ����� ��������, ������� ��� ��� ���(������� ��������� ��� ������� ����� ��������)\n";
		return false;
	}
	if (st[0] != '+')
	{
		std::cout << "������������ ����� ��������, ������� ��� ��� ���(������ ������ ������ ���� +)\n";
		return false;
	}
	for (size_t i = 1; i < st.size(); i++)
	{
		if (!std::isdigit(st[i]))
		{
			std::cout << "������������ ����� ��������, ������� ��� ��� ���(������� ������ �������� ����� ����)\n";
			return false;
		}
	}

	return true;
}


class phone_dictionary
{
public:
	void AddContact()
	{
		contact _contact;
		bool is_correct_number = false;
		std::cout << "������� ����� �������� � ���� +7-999-999-99-99 (������ ���� �� �����)\n";
		while (!is_correct_number)
		{
			std::cin >> _contact.number;
			is_correct_number = is_correct_phone_number(_contact.number);
		}
		std::cout << "������� ��� ��������\n";
		std::cin >> _contact.name;
		std::cout << "������� ������� ��������\n";
		std::cin >> _contact.surname;
		contacts.push_back(_contact);
	}

	void PrintInfo()
	{
		for (size_t i = 0; i < contacts.size(); i++)
		{
			std::cout << i + 1 << " �������\n";
			std::cout << "����� ��������: " << contacts[i].number << '\n';
			std::cout << "���: " << contacts[i].name << '\n';
			std::cout << "�������: " << contacts[i].surname << '\n';
		}
	}

	void ChangeInfo(const int _n)
	{
		int temp_change_number;
		std::cout << "����� �� ������ ��������? ������� �����\n";
		std::cout << "1 - �����\n";
		std::cout << "2 - ���\n";
		std::cout << "3 - �������\n";
		std::cin >> temp_change_number;
		switch (temp_change_number)
		{
		case 1:
		{
			std::string temp_number;
			std::cout << "������� ����� ����� ��������\n";
			bool is_correct_temp_number = false;
			while (!is_correct_temp_number)
			{
				std::cin >> temp_number;
				is_correct_temp_number = is_correct_phone_number(temp_number);
			}
			contacts[_n].number = temp_number;
		}

		case 2:
		{
			std::string temp_name;
			std::cout << "������� ����� ���\n";
			std::cin >> temp_name;
			contacts[_n].name = temp_name;
		}

		case 3:
		{
			std::string temp_surname;
			std::cout << "������� ����� �������\n";
			std::cin >> temp_surname;
			contacts[_n].surname = temp_surname;
		}

		}
	}

	void ClearInfo()
	{
		contacts = {};
	}

	bool isEmpty()
	{
		return contacts.empty();
	}

private:
	class contact
	{
	public:
		std::string name;
		std::string surname;
		std::string number;
	};
	static std::vector<contact> contacts;
};
std::vector<phone_dictionary::contact> phone_dictionary::contacts{};



int main()
{
	setlocale(LC_ALL, "ru");
	int menu_id = 0;
	phone_dictionary test;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	while (true)
	{
		std::cout << "�������� ��������, ������� ������ ���������\n";
		std::cout << "1 - �������� ����� �������\n";
		std::cout << "2 - ���������� ������������ ��������\n";
		std::cout << "3 - �������� �����-���� �������\n";
		std::cout << "4 - �������� ���\n";

		std::cin >> menu_id;

		if (menu_id == 1)
		{
			test.AddContact();
		}

		if (menu_id == 2)
		{
			if (test.isEmpty())
			{
				std::cout << "���� ��� ��� ���������\n";
			}
			else
			{
				test.PrintInfo();
			}
		}

		if (menu_id == 3)
		{
			if (test.isEmpty())
			{
				std::cout << "���� ��������� ��� ���������\n";
			}
			else
			{
				test.PrintInfo();
				int temp_contact_id;
				std::cout << "����� ������� �� �� ������ ��������? ������� ��� �����\n";
				std::cin >> temp_contact_id;
				test.ChangeInfo(temp_contact_id);
			}
		}

		if (menu_id == 4)
		{
			test.ClearInfo();
		}


		std::cout << '\n' << '\n';
	}


	return 0;
}