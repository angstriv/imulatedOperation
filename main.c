#define true 1

#include <stdio.h>
#include <windows.h>
#include "implement_method.h"
#include "keyEvent.h"

int main()
{
	//open_web("");//打开某个网址 
	//Sleep(4000);//延时4秒，等待网页打开完毕，再进行其它操作。根据实际情况（浏览器打开速度，网速）
	
	while (true)
	{
		if (keyPress(VK_ESCAPE) == 0)//如果esc没有被按下
		{
			click(1040, 880);//点击"开始" 坐标
			Sleep(500);//延迟
		}
		else//如果esc被按下
		{
			return 0;//结束程序
		}
		
	}
	

	return 0;
}