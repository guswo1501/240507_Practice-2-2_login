// ȸ�� ��� �ۼ��ϱ� (ID,PW)

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;


int main()
{
	
	//����ڿ��� 3���� ȸ���� ���� �̸� ��й�ȣ �Է� �ޱ�

	string ID;
	string PW;

	// 3X2 ��� ����;
	string list[3][2];

	cout << "ȸ�� 3�� ���� �̸��� ��й�ȣ�� ���������� �ۼ����ּ���.\n";


	for (int i = 0; i < 3; i++)
	{
		cout << i + 1 << " ��° ȸ�� :  ";

		for (int j = 0; j < 2; j++)
		{
			cin >> list[i][j];		// list[i][0]: �̸�(ID), list[i][1]: ��й�ȣ(PW)
		}
	}


	// 2. ����ڿ��� �Է¹��� ������ member.txt�� ��� 

	ofstream ID_file("member.txt");

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			ID_file <<  list[i][j] << "  ";
		}

		ID_file << endl;
	}
	
	ID_file.close();

	
	// 3. member.txt�� ����� ȸ����� ���
	
	cout << "-----------ȸ�� ��� ���� �б�------------" << endl;

	ifstream Read_file("member.txt");

	// member.txt ���Ͽ� ����� ������ ���� �Ἥ ���
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cout << list[i][j] << "  ";
		}

		cout << endl;
	}

	Read_file.close();
	


	/*
	// ���� �о����
	ifstream Read_file("member.txt");
	
	// ���� ���� ���� ������ �о���� ���ؼ��� ���� �۾��� �ʿ�
	string line;
	getline(Read_file, line);
	*/

	// 4. �̸�, ��й�ȣ �Է� �ޱ�
	
	cout << endl;
	cout << "�̸��� �Է��ϼ��� ";
	cin >> ID;
	
	cout << "��й�ȣ�� �Է��ϼ��� ";
	cin >> PW;

	// ��Ī ����� ������ ���� ����
	
	string saveResult[3];

	// ��Ī ��� ����
	for (int i = 0; i < 3; i++)
	{
		if ((list[i][0] != ID) || (list[i][1] != PW))
		{
			saveResult[i] = "�α��� ����";
		}

		if ((list[i][0] == ID) && (list[i][1] == PW))
		{
			saveResult[i] = "�α��� ����";
		}
	}

	// ��Ī ��� Ȯ��
	
	int cnt = 0;
	while (1)
	{
		if (saveResult[cnt] == "�α��� ����")
		{
			cout << "�α��� ����" << endl;
			break;
		}

		else if (saveResult[cnt] != "�α��� ����")
		{
			if (cnt == 2)
			{
				cout << "�α��� ����" << endl;
				break;
			}
			else
				cnt++;
		}
		
	}
	
	system("pause");


}


