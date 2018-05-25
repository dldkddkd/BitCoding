/*
* Company.cpp
*
* 회사 관련 데이터 및 처리
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
	"암겨농업",
	"MK Electronics",
	"폭펭군수",
	"CJ 제일손연재",
	"KJS 시스템",
	"Fruit",
	"수배자 모터스",
	"기야조선",
};

char *gTips[MAX_TIP] =
{
	"주가가 쌀 때 매수하고 비쌀 때 매도해서 이익을 내세요!",
	"전략을 세워 투자 왕이 되어보세요!",
	"1달마다 세금을 냅니다. 계속 기다리다간 파산할 수 있으니 조심하세요!",
	"여러 회사의 주식을 살 수 있습니다. 회사 목록을 확인하세요!",
};

char *gGoodNews[MAX_NEWS] =
{
	"의 새 상품, 인기몰이 중",
	"의 발전을 이끈 새 CEO의 경영철학...",
	"의 성공적인 새 전략",
	", 환율 급등으로 주가 폭등",
	"에 외국인의 대규모 투자로 호재",
};

char *gBadNews[MAX_NEWS] =
{
	"의 새 상품 대 실패... CEO 해임 위기",
	", 지금 추세로는 위험하다 - 전문가 분석",
	"의 위기... 시급한 대책 마련 필요",
	", 환율로 인한 심각한 피해",
	" 주식 팔자.. 외국인 대규모 매도에 주가 급락",
};

char *gInfos[MAX_COMPANY] =
{
	" Naissoft는 자칭 대한민국 최대 규모의 소프트웨어 개발 업체입니다.\n 유틸리티, 게임 등 여러 가지 프로그램들을 개발하고 있죠.",
	" HawTech는 Naissoft와 양대산맥을 이루는 소프트웨어 업체입니다.",
	" 암겨농업은 산지에서 갓 생산된 싱싱한 작물을 전국에 유통하고 식품을 만드는 회사입니다.\n 특이한 이름이 회사 마케팅에 도움을 주죠.\n 최근은 경운기 등 농기구도 생산하고 있답니다.",
	" MK Electronics는 전자제품 생산 회사입니다.\n TV, PC, 스마트폰, 냉장고 등을 생산하죠.",
	" 폭펭군수는 군수 물자 생산 업체입니다.\n 이름답게 폭탄을 주로 생산하는 회사예요.",
	" CJ 제일손연재는 패스트 푸드 업체입니다.\n 손연재란 먹을 손(飡), 잔치 연(宴), 집 재(齋) 로,\n 항상 먹는 잔치가 벌어지는 집이라는 의미랍니다.",
	" KJS 시스템은 기업, 서버용 소프트웨어를 개발하는 회사입니다.\n 주로 가상 머신, 개발자 도구 등을 만들죠.",
	" Fruit는 유명한 모바일 기기 회사입니다.\n 태블릿, 스마트폰, 스마트 워치 등을 생산하고 있어요.\n Grand Theft Auto V™에 출연한 적이 있답니다.",
	" 수배자 모터스는 자동차를 개발/생산하는 업체입니다.\n 독자적인 엔진도 개발 중이며, 독일의 자동차 회사들과 경쟁 중입니다.",
	" 기야조선업은 기야그룹 산하의 중공업 회사로, 배를 만드는 회사랍니다.",
};

char *gGoodHeadline[MAX_HEADLINE] =
{
	", 유례 없는 성장할 듯",
	"이(가) 나라 살린다",
	", 어디까지 성장하나",
	" 경영진들의 현명한 선택",
	" 주가 고공행진 중",
};

char *gBadHeadline[MAX_HEADLINE] =
{
	" 성장 둔화 전망",
	", 어쩌다 이렇게 됐나",
	" 주가 급락할 듯",
	" 상황, 더 나빠진다",
	", 이대로 가다간 파산",
};

char *gGoodArticle[MAX_ARTICLE] =
{
	"이(가) 유례 없는 성장을\n\
계속하고 있다. 어제 본지와의 인터뷰에 \n\
서 김갑동 준승대 경영학과 명예교수는 \"\n\
아직 단정짓기는 어려우나 현재 성장세를\n\
계속 유지할 것\"이라고 답변했다. 김 교 \n\
수는 환율과 경기 회복 등의 여러 요인이\n\
현재의 성장에 작용했다고 주장하고 있다",

	"의 신제품이 큰 인기를\n\
끌고 있다. 얼마 전 출시한 이 제품은 회\n\
사 경영진들의 반대를 무릅쓰고 출시한  \n\
품이다. 개발 초반부터 잡음이 많았으나 \n\
현재는 자타공인 회사의 대표 모델로 자 \n\
리매김하는 중이다.",

	"이(가)\n더욱 성장할 전망이다.\n\
美 소비자단체 NSC의 조사 결과 다른 회 \n\
사들을 모두 제치고 만족도 지수 1위를  \n\
달성하였으며, 이에 따라 판매량도 꾸준 \n\
히 늘어나고 있다. 이런 추세라면 곧 국 \n\
내 시장도 장악할 수 있을 것으로 전망된\n\
다.",
};

void cCompany::UpdatePrice()
{
	// 회사 상태에 따른 주식 가격 업데이트
	// 진입 시기 : 1초에 한번
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

	// 각 회사의 주식 가격은 2000 이하로 떨어지지 않는다.
	if (mPrice < 2000)
		mPrice				= 2000;
	// 가격의 일자리 수는 내림.
	mPrice					= mPrice / 10 * 10;
}

void cCompany::UpdateStatus()
{
	// 회사 상태 업데이트.
	// 지입 시기 : 24초에 한번(게임 시간 매일 오전 1시)
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
	printf("羅  所  日  報     %d월 %d일", cTimer::GetInstance()->GetMonth() + 1, cTimer::GetInstance()->GetDay() + 1);
	gotoxy(76, 13);
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━");

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

	printf(" 회사 : ");
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
	printf(" │ 가격 : %5d원  ", mPrice);

	diffOfPrice				= mPrice - mPrevPrice;
	if (diffOfPrice > 0)
	{
		textcolor(2);
		printf("▲%4d원 ", diffOfPrice);
		textcolor(7);
	}
	else if (diffOfPrice < 0)
	{
		textcolor(14);
		printf("▼%4d원 ", -1 * diffOfPrice);
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
	// 모든 회사 상태 업데이트.
	// 진입 시기 : 24초에 한번
	for (int i = 0; i < MAX_COMPANY; i++)
		mCompany[i].UpdateStatus();
}

void cCompanyManager::UpdateAllCompanyPrice()
{
	// 모든 회사 주식가격 업데이트.
	// 진입 시기 : 1초에 한번
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
* 만약 모드가 0이면 게임에서 설정한 순서로 주식 가격을 출력합니다
* 만약 모드가 1이면 오름차순으로 정렬하여 주식 가격을 출력합니다
* 만약 모드가 2이면 내림차순으로 정렬하여 주식 가격을 출력합니다
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
	// 현재 선택 된 주식 가격 변화 추이
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
	printf("회사 : %s", mCompany[_comp].GetCompanyName());
	
	gotoxy(75, 4);
	printf("현재 주가 : %d원", mCompany[_comp].GetPrice());
	
	gotoxy(75, 6);
	printf("전문가 의견 : %s", mCompany[_comp].GetCompanyStatus() ? "긍정적" : "부정적");
}

void cCompanyManager::ShowCompanyInfo()
{
	int						i = 0;
	char					ch = '\0';

	system("cls");

	while (ch != 27)
	{
		system("cls");
		titleLine("회사 정보");

		gotoxy(0, 5);
		printf(" %d / %d. W, S 키로 넘겨 볼 수 있습니다. Esc로 나가기\n 회사 : %s\n\n", i + 1, MAX_COMPANY, mCompany[i].GetCompanyName());
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