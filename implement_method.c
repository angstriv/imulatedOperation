#include <stdlib.h>
#include <Windows.h> //ShellExecuteA()

//��ĳ����ַ:website ��ʹ��Ĭ��������� 
void open_web(char* website)
{
	ShellExecuteA(0, "open", website, 0, 0, 1);
}


//ģ�������  ��x,y����Ҫ�����λ�� 
void click(int x, int y)
{
	//��������ƶ��� ָ����λ��     ����Ļ�ֱ���1920*1080  ���������ϵͳ�У���Ļ��ˮƽ�ʹ�ֱ�����Ͼ��ȷָ��65535��65535����Ԫ
	mouse_event(MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE, x * 65535 / 1920, y * 65535 / 1080, 0, 0);

	//Sleep(50);�����ⲿ���ӳ� 
	mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);//���������� 
	mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);//������̧��
}

//ģ��������� keybd_event(Ҫ���µ��ַ�,0,����,0);����Ϊ0�ǰ��£�����Ϊ2��̧�� 
void input(char user[], char pwd[])//�˺� ����
{
	click(823, 392); //���"�û��������"��λ�� 	

	int i;
	//�����˺� 
	for (i = 0; i < sizeof(user); i++)
	{
		keybd_event(user[i], 0, 0, 0);
		keybd_event(user[i], 0, 2, 0);
		Sleep(30);
	}

	//tab�� ��Ӧ�ı����0x09  ����������� ��ȡ���� 
	keybd_event(0x09, 0, 0, 0);//���� 
	keybd_event(0x09, 0, 2, 0); //�ɿ� 
	Sleep(30);

	//�������� 
	for (i = 0; i < sizeof(pwd); i++)
	{
		keybd_event(pwd[i], 0, 0, 0);
		keybd_event(pwd[i], 0, 2, 0);
		Sleep(30);
	}

	//ģ�ⰴ��tab�� �õ�¼��ť��ȡ���� 
	click(824, 530);//���"��¼��ť" 
	Sleep(30);
}


//��chrome.exe����ɱ��������������δʹ�� 
void close()
{
	system("taskkill  /f  /im chrome.exe");
}

