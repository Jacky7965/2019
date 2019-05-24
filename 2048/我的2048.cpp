#include <stdio.h> 
#include <stdlib.h> 
#include <conio.h>
#include <windows.h>
#include <io.h>
#include <direct.h>
#include <Shlobj.h>
#include <time.h>   
#include <graphics.h>
#include <ege.h>
#include <fps.h>

void init_game();    
void loop_game();    
void reset_game();   
void release_game(int signal); 
int read_keyboard();
void move_left();  
void move_right();
void move_up();   
void move_down();  
void add_rand_num();   
void check_game_over(); 
int get_null_count();   
void clear_screen();    
void refresh_show();    
/* ��ȡ���� �������� */
int read_keyboard()
{
	return _getch();
} 

/* ��ʼ��Ϸ �������� */
void loop_game()
{
	int board[4][4]; 
	int score;           
    int best; 
    int if_need_add_num; 
    int if_game_over;    
    int if_prepare_exit; 
    while (1)
	{
        int cmd = read_keyboard(); 
        /* �ж��Ƿ�׼���˳���Ϸ */
        if (if_prepare_exit)
		{
             if(cmd == 'y' || cmd == 'Y')
			 {
                /* �˳���Ϸ���������˳� */
                clear_screen();
                return;
             }
			 else if (cmd == 'n' || cmd == 'N')
			 {
                /* ȡ���˳� */
                if_prepare_exit = 0;
                refresh_show();
                continue;
             } 
			 else 
			 {
                continue;
             }
        }

        /* �ж��Ƿ��Ѿ������Ϸ */
        if (if_game_over) 
		{
            if (cmd == 'y' || cmd == 'Y') 
			{
                /* ������Ϸ */
                reset_game();
                continue;
            } 
			else if (cmd == 'n' || cmd == 'N') 
			{
                /* �˳���Ϸ���������˳�  */
                clear_screen();
                return;
            } 
			else 
			{
                continue;
            }
        }
        if_need_add_num = 0; 

        /* ���������w��s��a��d�ַ����������������q�����˳� */
        switch (cmd) 
		{
          case 'a':
          case 75:move_left();
            break;
          case 's':
          case 80:move_down();
            break;
          case 'w':
          case 72:move_up();
            break;
          case 'd':
          case 77:move_right();
            break;
          case 'q':
          case 27:if_prepare_exit = 1;
            break;
          default:continue;
        }
        char *config_path;
        /* ���Ƶ÷ּ�¼ */
        if (score > best) 
		{
            best = score;
            FILE *fp = fopen(config_path, "w");
            if (fp) 
			{
                fwrite(&best, sizeof(best), 1, fp);
                fclose(fp);
            }
        }

        if (if_need_add_num) 
		{
            add_rand_num();
            refresh_show();
        } 
		else if(if_prepare_exit) 
		{
            refresh_show();
        }
    }
}

/* ������Ϸ �������� */
void reset_game() 
{
	int board[4][4]; 
	int score= 0;            
    int if_need_add_num = 1;
    int if_game_over = 0;
    int if_prepare_exit = 0;

    int n=rand()%16;
    int i;
    for(i=0;i<4;++i) 
	{
        int j;
        for(j=0;j<4;++j) 
		{
            board[i][j] = ((n--)==0?2:0);
        }
    }
    add_rand_num();
    refresh_show();
}

/* ��������� �������� */
void add_rand_num() 
{
	int board[4][4]; 
    srand((unsigned int) time(0));
    int n=rand()%get_null_count();
    int i;
    for (i=0;i<4;++i) 
	{
        int j;
        for (j = 0; j < 4; ++j) 
		{
            if (board[i][j] == 0 && n-- == 0) 
			{
                board[i][j] = (rand() % 10 ? 2 : 4); 
                return;
            }
        }
    }
}

/* ��ȡ��λ������ �������� */
int get_null_count() 
{
	int board[4][4]; 
    int n=0;
    int i;
    for (i=0;i<4;++i) 
	{
        int j;
        for (j=0;j<4;++j) 
		{
            board[i][j]==0?(++n):1;
        }
    }
    return n;
}

/* �����Ϸ�Ƿ���� �������� */
void check_game_over() 
{
	int board[4][4]; 
	int if_game_over;
    int i;
    for (i = 0; i < 4; ++i) 
	{
        int j;
        for (j = 0; j < 3; ++j) 
		{
            if (board[i][j] == board[i][j + 1] || board[j][i] == board[j + 1][i]) 
			{
                if_game_over = 0;
                return;
            }
        }
    }
    if_game_over = 1;
}

/*  ���� �������� */
void move_left() 
{
	int board[4][4]; 
	int score;   
	int if_need_add_num; 
    int if_game_over;    
    int if_prepare_exit;         
    int i;
    for (i = 0; i < 4; ++i) 
	{
        int j, k;
        for (j = 1, k = 0; j < 4; ++j) 
		{
            if (board[i][j] > 0) 
            {
                if (board[i][k] == board[i][j]) 
				{
                    score += board[i][k++] *= 2;
                    board[i][j] = 0;
                    if_need_add_num = 1; 
                } 
				else if (board[i][k] == 0) 
				{
                    board[i][k] = board[i][j];
                    board[i][j] = 0;
                    if_need_add_num = 1;
                } 
				else 
				{
                    board[i][++k] = board[i][j];
                    if (j != k) 
					{
                        board[i][j] = 0;
                        if_need_add_num = 1;
                    }
                }
            }
        }
    }
}

/* ���� �������� */
void move_right() 
{
	int if_need_add_num; 
    int if_game_over;    
    int if_prepare_exit; 
	int board[4][4]; 
	int score;           
    int i;
    for (i = 0; i < 4; ++i) 
	{
        int j, k;
        for (j = 2, k = 3; j >= 0; --j) 
		{
            if (board[i][j] > 0) 
			{
                if (board[i][k] == board[i][j]) 
				{
                    score += board[i][k--] *= 2;
                    board[i][j] = 0;
                    if_need_add_num = 1;
                } 
				else if (board[i][k] == 0) 
				{
                    board[i][k] = board[i][j];
                    board[i][j] = 0;
                    if_need_add_num = 1;
                } 
				else 
				{
                    board[i][--k] = board[i][j];
                    if (j != k) 
					{
                        board[i][j] = 0;
                        if_need_add_num = 1;
                    }
                }
            }
        }
    }
}

/* ���� �������� */
void move_up() 
{
	int board[4][4]; 
	int score; 
	int if_need_add_num; 
    int if_game_over;    
    int if_prepare_exit;           
    int i;
    for (i = 0; i < 4; ++i) 
	{
        int j, k;
        for (j = 1, k = 0; j < 4; ++j) 
		{
            if (board[j][i] > 0) 
			{
                if (board[k][i] == board[j][i]) 
				{
                    score += board[k++][i] *= 2;
                    board[j][i] = 0;
                    if_need_add_num = 1;
                } 
				else if (board[k][i] == 0) 
				{
                    board[k][i] = board[j][i];
                    board[j][i] = 0;
                    if_need_add_num = 1;
                } 
				else 
				{
                    board[++k][i] = board[j][i];
                    if (j != k) 
					{
                        board[j][i] = 0;
                        if_need_add_num = 1;
                    }
                }
            }
        }
    }
}

/* ���� �������� */
void move_down() 
{
	int board[4][4];
	int if_need_add_num; 
    int if_game_over;    
    int if_prepare_exit;  
	int score;           
    int i;
    for (i = 0; i < 4; ++i) 
	{
        int j, k;
        for (j = 2, k = 3; j >= 0; --j) 
		{
            if (board[j][i] > 0) 
			{
                if (board[k][i] == board[j][i]) 
				{
                    score += board[k--][i] *= 2;
                    board[j][i] = 0;
                    if_need_add_num = 1;
                } 
				else if (board[k][i] == 0) 
				{
                    board[k][i] = board[j][i];
                    board[j][i] = 0;
                    if_need_add_num = 1;
                } 
				else 
				{
                    board[--k][i] = board[j][i];
                    if (j != k) {
                        board[j][i] = 0;
                        if_need_add_num = 1;
                    }
                }
            }
        }
    }
}

/* ���� */
void clear_screen() 
{
	int board[4][4]; 
    COORD pos = {0, 0};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
    CONSOLE_CURSOR_INFO info = {1, 0};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);

}

/* ˢ�½��� �������� */
void refresh_show() 
{
	int board[4][4]; 
	int if_need_add_num; 
    int if_game_over;    
    int if_prepare_exit; 
	int score;           
    int best;  
    clear_screen();
    printf("\n\n\n\n");
    printf("                  GAME: 2048     SCORE: %05d     BEST: %06d\n", score, best);
    printf("               --------------------------------------------------");

    /* ���Ʒ�������� */
    printf("\n\n                             �����������Щ��������Щ��������Щ���������\n");
    int i;
    for (i = 0; i < 4; ++i) {
        printf("                             ��");
        int j;
        for (j = 0; j < 4; ++j) {
            if (board[i][j] != 0) {
                if (board[i][j] < 10) {
                    printf("  %d ��", board[i][j]);
                } else if (board[i][j] < 100) {
                    printf(" %d ��", board[i][j]);
                } else if (board[i][j] < 1000) {
                    printf(" %d��", board[i][j]);
                } else if (board[i][j] < 10000) {
                    printf("%4d��", board[i][j]);
                } else {
                    int n = board[i][j];
                    int k;
                    for (k = 1; k < 20; ++k) {
                        n = n >> 1;
                        if (n == 1) {
                            printf("2^%02d��", k);
                            break;
                        }
                    }
                }
            } else printf("    ��");
        }

        if(i<3) 
		{
            printf("\n                             �����������੤�������੤�������੤��������\n");
        } 
		else 
		{
            printf("\n                             �����������ة��������ة��������ة���������\n");
        }
    }
    printf("\n");
    printf("               --------------------------------------------------\n");
    printf("                  [W]:UP [S]:DOWN [A]:LEFT [D]:RIGHT [Q]:EXIT");

    if (get_null_count() == 0) 
	{
        check_game_over();

        /* �ж��Ƿ������Ϸ */
        if (if_game_over) {
            printf("\r                      GAME OVER! TRY THE GAME AGAIN? [Y/N]:     \b\b\b\b");

            CONSOLE_CURSOR_INFO info = {1, 1};
            SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);

        }
    }

    /* �ж��Ƿ�׼���˳���Ϸ */
    if (if_prepare_exit) {
        printf("\r                   DO YOU REALLY WANT TO QUIT THE GAME? [Y/N]:   \b\b");

        CONSOLE_CURSOR_INFO info = {1, 1};
            SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);

    }

    fflush(0); /* ˢ����������� */
}

/* ��ʼ����Ϸ */
void init_game() 
{
    int score;           
    int best;  
    system("cls");
    char config_path[1000]={0}; 
    char m_lpszDefaultDir[MAX_PATH];
    char szDocument[MAX_PATH] = {0};
    memset(m_lpszDefaultDir, 0, _MAX_PATH);
    LPITEMIDLIST pidl = NULL;
    SHGetSpecialFolderLocation(NULL, CSIDL_LOCAL_APPDATA, &pidl);
    if (pidl && SHGetPathFromIDList(pidl, szDocument)) {
    GetShortPathName(szDocument, m_lpszDefaultDir, _MAX_PATH);
    }
    sprintf(config_path, "%s\\2048", m_lpszDefaultDir);
    if (_access(config_path, 0) == -1) {
    _mkdir(config_path);
    }
    sprintf(config_path, "%s\\2048\\2048.dat", m_lpszDefaultDir);


    /* ��ȡ��Ϸ��߷��� */
    FILE *fp = fopen(config_path, "r");
    if (fp) 
	{
        fread(&best, sizeof(best), 1, fp);
        fclose(fp);
    } 
	else 
	{
        best = 0;
        fp = fopen(config_path, "w");
        if (fp) 
		{
            fwrite(&best, sizeof(best), 1, fp);
            fclose(fp);
        }
    }

    reset_game();
}

/* �ͷ���Ϸ */
void release_game(int signal) 
{
    system("cls");
    CONSOLE_CURSOR_INFO info = {1, 1};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);

    exit(0);
}

#define WIDTH 700
#define HEIGHT 900

void lead()
{
	initgraph(WIDTH,HEIGHT);//����
	setbkcolor(RGB(251,248,241));//����
	settextcolor(RGB(150,126,104));
	//o1();
}

void start()
{
	cleardevice();//����
	setfont(145,0,"Microsoft Yahei UI Bold");
	settextcolor(RGB(120,116,101));//��������
	outtextxy(15,0,"2048");

	setfillcolor(RGB(184,175,160));//���õ�ǰ�����ɫ
	solidroundrect(390,10,530,80,15,15);//Բ������
	setfont(28,0,"Microsoft Yahei UI Bold");//���õ�ǰ����
	setbkcolor(RGB(184,175,160));//������ɫ
	settextcolor(RGB(248,247,241));//������ɫ
	outtextxy(435,20,"����");
	 
	solidroundrect(550,10,690,80,15,15);//Բ������
	outtextxy(590,20,"��߷�");

	setfillcolor(RGB(141,122,105));
	solidroundrect(480,95,690,137.5,15,15);
	setbkcolor(RGB(141,122,105));//������ɫ
	setfont(33,0,"Microsoft Yahei UI Bold");
	outtextxy(525,100,"������ҳ��");

	setfillcolor(RGB(141,122,105));
	solidroundrect(480,152.5,690,195,15,15);
	setbkcolor(RGB(141,122,105));//������ɫ
	setfont(33,0,"Microsoft Yahei UI Bold");
	outtextxy(540,160,"���¿�ʼ");

	setfillcolor(RGB(187,173,160));
	solidroundrect(10,210,690,890,20,20);

	int i,j;
	for(i=0;i<4;i++)
	{
		setfillcolor(RGB(206,192,181));
		for(j=0;j<4;j++)
		{
			solidroundrect(30+165*i,230+165*j,175+165*i,375+165*j,5,5);
		}
	}

	MOUSEMSG m;
	while(1)
	{
		m=GetMouseMsg();
		if(m.uMsg==WM_LBUTTONDOWN)
		{
			initgraph(WIDTH,HEIGHT);//����
			setbkcolor(RGB(251,248,241));//����
			settextcolor(RGB(150,126,104));
			if(m.x>480&&m.x<690&&m.y>95&&m.y<137.5)
				o1();

			if(m.x>480&&m.x<690&&m.y>152.5&&m.y<195)
				start();
		}
	}

}
int main() 
{
	lead();
    init_game();
    loop_game();
    release_game(0);
    return 0;
}


