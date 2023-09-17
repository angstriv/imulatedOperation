#include <windows.h>


int keyPress(int keyValue)//某键是否按下 键值
{
	int keyState = GetKeyState(keyValue);//获取某键状态 

	if (keyState < 0)//某键被按下 
	{
		return 1;
	}
	else
	{
		return 0;
	}

}

int keyRelease(int keyValue)//某键是否松开 键值
{
	int keyState = GetKeyState(keyValue);//获取某键状态 

	if (keyState > 0)//某键被松开
	{
		return 1;
	}
	else
	{
		return 0;
	}

}