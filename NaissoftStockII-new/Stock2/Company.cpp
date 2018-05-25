/*
* Company.cpp
*
* ȸ�� ���� ������ �� ó��
*
* Created on : 2018-05-02
*     Author : Jeong Ji-ung
*/
#include "global.h"

namespace GameSystem
{
	
char gCompanyName[MAX_COMPANY][COMPANY_NAME_SIZE] =
{
	"Naissoft",
	"HawTech",
	"�ϰܳ��",
	"MK Electronics",
	"���뱺��",
	"CJ ���ϼտ���",
	"KJS �ý���",
	"Fruit",
	"������ ���ͽ�",
	"�������",
};

char *gTips[MAX_TIP] =
{
	"�ְ��� �� �� �ż��ϰ� ��� �� �ŵ��ؼ� ������ ������!",
	"������ ���� ���� ���� �Ǿ����!",
	"1�޸��� ������ ���ϴ�. ��� ��ٸ��ٰ� �Ļ��� �� ������ �����ϼ���!",
	"���� ȸ���� �ֽ��� �� �� �ֽ��ϴ�. ȸ�� ����� Ȯ���ϼ���!",
};

char *gGoodNews[MAX_NEWS] =
{
	"�� �� ��ǰ, �α���� ��",
	"�� ������ �̲� �� CEO�� �濵ö��...",
	"�� �������� �� ����",
	", ȯ�� �޵����� �ְ� ����",
	"�� �ܱ����� ��Ը� ���ڷ� ȣ��",
};

char *gBadNews[MAX_NEWS] =
{
	"�� �� ��ǰ �� ����... CEO ���� ����",
	", ���� �߼��δ� �����ϴ� - ������ �м�",
	"�� ����... �ñ��� ��å ���� �ʿ�",
	", ȯ���� ���� �ɰ��� ����",
	" �ֽ� ����.. �ܱ��� ��Ը� �ŵ��� �ְ� �޶�",
};

char *gInfos[MAX_COMPANY] =
{
	" Naissoft�� ��Ī ���ѹα� �ִ� �Ը��� ����Ʈ���� ���� ��ü�Դϴ�.\n ��ƿ��Ƽ, ���� �� ���� ���� ���α׷����� �����ϰ� ����.",
	" HawTech�� Naissoft�� ������� �̷�� ����Ʈ���� ��ü�Դϴ�.",
	" �ϰܳ���� �������� �� ����� �̽��� �۹��� ������ �����ϰ� ��ǰ�� ����� ȸ���Դϴ�.\n Ư���� �̸��� ȸ�� �����ÿ� ������ ����.\n �ֱ��� ���� �� ��ⱸ�� �����ϰ� �ִ�ϴ�.",
	" MK Electronics�� ������ǰ ���� ȸ���Դϴ�.\n TV, PC, ����Ʈ��, ����� ���� ��������.",
	" ���뱺���� ���� ���� ���� ��ü�Դϴ�.\n �̸���� ��ź�� �ַ� �����ϴ� ȸ�翹��.",
	" CJ ���ϼտ���� �н�Ʈ Ǫ�� ��ü�Դϴ�.\n �տ���� ���� ��(��), ��ġ ��(��), �� ��(�) ��,\n �׻� �Դ� ��ġ�� �������� ���̶�� �ǹ̶��ϴ�.",
	" KJS �ý����� ���, ������ ����Ʈ��� �����ϴ� ȸ���Դϴ�.\n �ַ� ���� �ӽ�, ������ ���� ���� ������.",
	" Fruit�� ������ ����� ��� ȸ���Դϴ�.\n �º�, ����Ʈ��, ����Ʈ ��ġ ���� �����ϰ� �־��.\n Grand Theft Auto V�⿡ �⿬�� ���� �ִ�ϴ�.",
	" ������ ���ͽ��� �ڵ����� ����/�����ϴ� ��ü�Դϴ�.\n �������� ������ ���� ���̸�, ������ �ڵ��� ȸ���� ���� ���Դϴ�.",
	" ����������� ��߱׷� ������ �߰��� ȸ���, �踦 ����� ȸ����ϴ�.",
};

char *gGoodHeadline[MAX_HEADLINE] =
{
	", ���� ���� ������ ��",
	"��(��) ���� �츰��",
	", ������ �����ϳ�",
	" �濵������ ������ ����",
	" �ְ� ������� ��",
};

char *gBadHeadline[MAX_HEADLINE] =
{
	" ���� ��ȭ ����",
	", ��¼�� �̷��� �Ƴ�",
	" �ְ� �޶��� ��",
	" ��Ȳ, �� ��������",
	", �̴�� ���ٰ� �Ļ�",
};

char *gGoodArticle[MAX_ARTICLE] =
{
	"��(��) ���� ���� ������\n\
����ϰ� �ִ�. ���� �������� ���ͺ信 \n\
�� �谩�� �ؽ´� �濵�а� �������� \"\n\
���� ��������� ����쳪 ���� ���弼��\n\
��� ������ ��\"�̶�� �亯�ߴ�. �� �� \n\
���� ȯ���� ��� ȸ�� ���� ���� ������\n\
������ ���忡 �ۿ��ߴٰ� �����ϰ� �ִ�",

	"�� ����ǰ�� ū �α⸦\n\
���� �ִ�. �� �� ����� �� ��ǰ�� ȸ\n\
�� �濵������ �ݴ븦 �������� �����  \n\
ǰ�̴�. ���� �ʹݺ��� ������ �������� \n\
����� ��Ÿ���� ȸ���� ��ǥ �𵨷� �� \n\
���ű��ϴ� ���̴�.",

	"��(��)\n���� ������ �����̴�.\n\
ڸ �Һ��ڴ�ü NSC�� ���� ��� �ٸ� ȸ \n\
����� ��� ��ġ�� ������ ���� 1����  \n\
�޼��Ͽ�����, �̿� ���� �Ǹŷ��� ���� \n\
�� �þ�� �ִ�. �̷� �߼���� �� �� \n\
�� ���嵵 ����� �� ���� ������ ������\n\
��.",
};

void cCompany::UpdatePrice()
{
	// ȸ�� ���¿� ���� �ֽ� ���� ������Ʈ
	// ���� �ñ� : 1�ʿ� �ѹ�
	mPrevPrice				= mPrice;

	if (mCompStatus == true)
	{
		if ((rand() % 2) == 0)
			mPrice			+= (rand() % MAX_UP_PRICE);
		else
			mPrice			-= (rand() % LOW_DOWN_PRICE);
	}
	else
	{
		if ((rand() % 2) == 0)
			mPrice			+= (rand() % LOW_UP_PRICE);
		else
			mPrice			-= (rand() % MAX_DOWN_PRICE);
	}

	// �� ȸ���� �ֽ� ������ 2000 ���Ϸ� �������� �ʴ´�.
	if (mPrice < 2000)
		mPrice				= 2000;
	// ������ ���ڸ� ���� ����.
	mPrice					= mPrice / 10 * 10;
}

void cCompany::UpdateStatus()
{
	// ȸ�� ���� ������Ʈ.
	// ���� �ñ� : 24�ʿ� �ѹ�(���� �ð� ���� ���� 1��)
	if (rand() % 2 == 0) 
		mCompStatus			= true;
	else 
		mCompStatus			= false;
}

void cCompany::Update()
{
	UpdateStatus();
	UpdatePrice();
}

void cCompany::SetCompanyStatus(bool _status)
{
	mCompStatus				= _status;
}

void cCompany::SetCompanyName(char* _name)
{
	strcpy(mCompanyName, _name);
}

void cCompany::SetPrice(int _price)
{
	mPrevPrice				= mPrice;
	mPrice					= _price;
}

bool cCompany::GetCompanyStatus()
{
	return mCompStatus;
}

char* cCompany::GetCompanyName()
{
	return mCompanyName;
}

int cCompany::GetPrice()
{
	return mPrice;
}

int cCompany::GetPrevPrice()
{
	return mPrevPrice;
}

void cCompany::DrawNewspaper()
{
	textcolor(112);

	for (int i = 0; i < 25; i++)
	{
		gotoxy(75, 10 + i);

		for (int j = 0; j < 40; j++) 
			_putch(' ');
	}

	gotoxy(88, 12);
	printf("��  �  ��  ��     %d�� %d��", cTimer::GetInstance()->GetMonth() + 1, cTimer::GetInstance()->GetDay() + 1);
	gotoxy(76, 13);
	printf("��������������������������������������������������������������������������");

	textcolor(15);
	gotoxy(76, 14);

	if (mCompStatus == true)
		printf(" %s%s ", mCompanyName, gGoodHeadline[rand() % MAX_HEADLINE]);
	else
		printf(" %s%s ", mCompanyName, gBadHeadline[rand() % MAX_HEADLINE]);

	textcolor(112);
	gotoxy(76, 16);

	if (mCompStatus == true)
	{
		int					i = 0;
		int					articleNo = rand() % MAX_ARTICLE;
		int					cnt = 0;

		printf(" %s", mCompanyName);
		while (gGoodArticle[articleNo][i] != '\0')
		{
			if (gGoodArticle[articleNo][i] == '\n')
			{
				cnt++;
				gotoxy(76, 16 + cnt);
			}
			else 
				putchar(gGoodArticle[articleNo][i]);
			
			i++;
		}
	}

	textcolor(7);
}

void cCompany::PrintStockPrice()
{
	int						diffOfPrice;

	printf(" ȸ�� : ");
	if (mCompStatus)
	{
		textcolor(10);
		printf("%-20s", mCompanyName);
		textcolor(7);
	}
	else
	{
		textcolor(12);
		printf("%-20s", mCompanyName);
		textcolor(7);
	}
	printf(" �� ���� : %5d��  ", mPrice);

	diffOfPrice				= mPrice - mPrevPrice;
	if (diffOfPrice > 0)
	{
		textcolor(2);
		printf("��%4d�� ", diffOfPrice);
		textcolor(7);
	}
	else if (diffOfPrice < 0)
	{
		textcolor(14);
		printf("��%4d�� ", -1 * diffOfPrice);
		textcolor(7);
	}
	printf("\n");
}

void cCompanyManager::Init()
{
	for (int i = 0; i < MAX_COMPANY; i++)
	{
		mCompany[i].SetCompanyName(gCompanyName[i]);
		mCompany[i].SetCompanyStatus(true);
		mCompany[i].SetPrice(9000);
		mCompany[i].UpdatePrice();
	}
}

void cCompanyManager::UpdateAllCompanyStatus()
{
	// ��� ȸ�� ���� ������Ʈ.
	// ���� �ñ� : 24�ʿ� �ѹ�
	for (int i = 0; i < MAX_COMPANY; i++)
		mCompany[i].UpdateStatus();
}

void cCompanyManager::UpdateAllCompanyPrice()
{
	// ��� ȸ�� �ֽİ��� ������Ʈ.
	// ���� �ñ� : 1�ʿ� �ѹ�
	for (int i = 0; i < MAX_COMPANY; i++)
		mCompany[i].UpdatePrice();
}

void cCompanyManager::UpdateGraphData()
{
	for (int i = 0; i < MAX_COMPANY; i++)
	{
		for (int j = 46; j >= 0; j--)
		{
			mGraphData[i][j + 1]	= mGraphData[i][j];
		}
		
		mGraphData[i][0]	= mCompany[i].GetPrice();
	}
}

cCompany* cCompanyManager::GetCompany(int _num)
{
	return &mCompany[_num];
}

void cCompanyManager::DrawNewspaper(int _selectComp)
{
	GetCompany(_selectComp)->DrawNewspaper();
}

/** Draw stock price on console
*
* @param mode
* Mode is view mode
* ���� ��尡 0�̸� ���ӿ��� ������ ������ �ֽ� ������ ����մϴ�
* ���� ��尡 1�̸� ������������ �����Ͽ� �ֽ� ������ ����մϴ�
* ���� ��尡 2�̸� ������������ �����Ͽ� �ֽ� ������ ����մϴ�
*
* @return void
*/
void cCompanyManager::ShowStockPrice(int _viewMode)
{
	int						order[MAX_COMPANY];
	int						temp;

	if (_viewMode == 0)
	{
		for (int i = 0; i < MAX_COMPANY; i++)
			mCompany[i].PrintStockPrice();

		return;
	}

	for (int i = 0; i < MAX_COMPANY; i++)
		order[i]			= mCompany[i].GetPrice();

	if (_viewMode == 1)
	{
		/* Sort in ascending order */
		for (int i = 0; i < MAX_COMPANY; i++)
		{
			for (int j = 0; j < MAX_COMPANY; j++)
			{
				if (order[i] > order[j])
				{
					temp	= order[i];
					order[i]= order[j];
					order[j]= temp;
				}
			}
		}

		for (int i = 0; i < MAX_COMPANY; i++)
		{
			for (int j = 0; j < MAX_COMPANY; j++)
			{
				if (order[i] == mCompany[j].GetPrice())
				{
					mCompany[j].PrintStockPrice();
					order[i]= 0;
				}
			}
		}
	}
	else if (_viewMode == 2)
	{
		/* Sort in descending order */
		for (int i = 0; i < MAX_COMPANY; i++)
		{
			for (int j = 0; j < MAX_COMPANY; j++)
			{
				if (order[i] < order[j])
				{
					temp	= order[i];
					order[i]= order[j];
					order[j]= temp;
				}
			}
		}
		
		for (int i = 0; i < MAX_COMPANY; i++)
		{
			for (int j = 0; j < MAX_COMPANY; j++)
			{
				if (order[i] == mCompany[j].GetPrice())
				{
					mCompany[j].PrintStockPrice();
					order[i]= 0;
				}
			}
		}
	}
}

void cCompanyManager::DrawGraph(int _comp)
{
	// ���� ���� �� �ֽ� ���� ��ȭ ����
	gotoxy(0, 25);
	printf(" 24000                                                                     \n 22000                                                                     \n 20000                                                                     "
		"\n 18000                                                                     \n 16000                                                                     \n 14000                                                                     "
		"\n 12000                                                                     \n 10000                                                                     \n  8000                                                                     "
		"\n  6000                                                                     \n  4000                                                                     \n  2000                                                                     \n                                                                              ");
	gotoxy(7, 46);

	int j = 0;
	for (int i = 47; i >= 0; i--)
	{
		if (mGraphData[_comp][i] > 0 && mGraphData[_comp][i] < 26000)
		{
			gotoxy(7 + j, 36 - ((int)((mGraphData[_comp][i] % 26000) / 2000) - 1));
			
			if (mGraphData[_comp][i] < 2000) 
				printf("v");
			else 
				printf("*");
			
			j++;
		}
		else if (mGraphData[_comp][i] >= 26000)
		{
			gotoxy(7 + j, 36 - ((int)(((mGraphData[_comp][i] - 2000) % 24000) / 2000)));
			
			if ((mGraphData[_comp][i] - 2000) / 24000 + 1 > 9)
				printf("+");
			else 
				printf("%d", (mGraphData[_comp][i] - 2000) / 24000 + 1);
			
			j++;
		}
	}
}

void cCompanyManager::ShowCompanyReport(int _comp)
{
	for (int i = 2; i < 7; i++)
	{
		gotoxy(75, i);
		printf("                     ");
	}

	gotoxy(75, 2);
	printf("ȸ�� : %s", mCompany[_comp].GetCompanyName());
	
	gotoxy(75, 4);
	printf("���� �ְ� : %d��", mCompany[_comp].GetPrice());
	
	gotoxy(75, 6);
	printf("������ �ǰ� : %s", mCompany[_comp].GetCompanyStatus() ? "������" : "������");
}

void cCompanyManager::ShowCompanyInfo()
{
	int						i = 0;
	char					ch = '\0';

	system("cls");

	while (ch != 27)
	{
		system("cls");
		titleLine("ȸ�� ����");

		gotoxy(0, 5);
		printf(" %d / %d. W, S Ű�� �Ѱ� �� �� �ֽ��ϴ�. Esc�� ������\n ȸ�� : %s\n\n", i + 1, MAX_COMPANY, mCompany[i].GetCompanyName());
		printf("%s", gInfos[i]);

		ch					= (char)_getch();

		switch (ch)
		{
		case 'W':
		case 'w':
			if (i < MAX_COMPANY - 1) 
				i++;
			break;

		case 'S':
		case 's':
			if (i > 0)
				i--;
			break;
		}
	}
	system("cls");
}

}