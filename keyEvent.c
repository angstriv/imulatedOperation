#include <windows.h>


int keyPress(int keyValue)//ĳ���Ƿ��� ��ֵ
{
	int keyState = GetKeyState(keyValue);//��ȡĳ��״̬ 

	if (keyState < 0)//ĳ�������� 
	{
		return 1;
	}
	else
	{
		return 0;
	}

}

int keyRelease(int keyValue)//ĳ���Ƿ��ɿ� ��ֵ
{
	int keyState = GetKeyState(keyValue);//��ȡĳ��״̬ 

	if (keyState > 0)//ĳ�����ɿ�
	{
		return 1;
	}
	else
	{
		return 0;
	}

}