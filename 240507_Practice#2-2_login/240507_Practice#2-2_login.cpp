// 회원 명부 작성하기 (ID,PW)

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;


int main()
{
	
	//사용자에게 3명의 회원에 대한 이름 비밀번호 입력 받기

	string ID;
	string PW;

	// 3X2 행렬 생성;
	string list[3][2];

	cout << "회원 3명에 대한 이름과 비밀번호를 순차적으로 작성해주세요.\n";


	for (int i = 0; i < 3; i++)
	{
		cout << i + 1 << " 번째 회원 :  ";

		for (int j = 0; j < 2; j++)
		{
			cin >> list[i][j];		// list[i][0]: 이름(ID), list[i][1]: 비밀번호(PW)
		}
	}


	// 2. 사용자에게 입력받은 정보를 member.txt에 기록 

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

	
	// 3. member.txt에 저장된 회원명부 출력
	
	cout << "-----------회원 명부 파일 읽기------------" << endl;

	ifstream Read_file("member.txt");

	// member.txt 파일에 저장된 값들을 새로 써서 출력
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
	// 파일 읽어오기
	ifstream Read_file("member.txt");
	
	// 위의 파일 내부 내용을 읽어오기 위해서는 따로 작업이 필요
	string line;
	getline(Read_file, line);
	*/

	// 4. 이름, 비밀번호 입력 받기
	
	cout << endl;
	cout << "이름을 입력하세요 ";
	cin >> ID;
	
	cout << "비밀번호를 입력하세요 ";
	cin >> PW;

	// 매칭 결과를 저장한 변수 선언
	
	string saveResult[3];

	// 매칭 결과 저장
	for (int i = 0; i < 3; i++)
	{
		if ((list[i][0] != ID) || (list[i][1] != PW))
		{
			saveResult[i] = "로그인 실패";
		}

		if ((list[i][0] == ID) && (list[i][1] == PW))
		{
			saveResult[i] = "로그인 성공";
		}
	}

	// 매칭 결과 확인
	
	int cnt = 0;
	while (1)
	{
		if (saveResult[cnt] == "로그인 성공")
		{
			cout << "로그인 성공" << endl;
			break;
		}

		else if (saveResult[cnt] != "로그인 성공")
		{
			if (cnt == 2)
			{
				cout << "로그인 실패" << endl;
				break;
			}
			else
				cnt++;
		}
		
	}
	
	system("pause");


}


