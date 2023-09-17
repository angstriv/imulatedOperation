#include <stdlib.h>
#include <Windows.h> //ShellExecuteA()

//打开某个网址:website （使用默认浏览器） 
void open_web(char* website)
{
	ShellExecuteA(0, "open", website, 0, 0, 1);
}


//模拟鼠标点击  （x,y）是要点击的位置 
void click(int x, int y)
{
	//将鼠标光标移动到 指定的位置     例屏幕分辨率1920*1080  在鼠标坐标系统中，屏幕在水平和垂直方向上均匀分割成65535×65535个单元
	mouse_event(MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE, x * 65535 / 1920, y * 65535 / 1080, 0, 0);

	//Sleep(50);请在外部加延迟 
	mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);//鼠标左键按下 
	mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);//鼠标左键抬起
}

//模拟键盘输入 keybd_event(要按下的字符,0,动作,0);动作为0是按下，动作为2是抬起 
void input(char user[], char pwd[])//账号 密码
{
	click(823, 392); //点击"用户名输入框"的位置 	

	int i;
	//输入账号 
	for (i = 0; i < sizeof(user); i++)
	{
		keybd_event(user[i], 0, 0, 0);
		keybd_event(user[i], 0, 2, 0);
		Sleep(30);
	}

	//tab键 对应的编号是0x09  让密码输入框 获取焦点 
	keybd_event(0x09, 0, 0, 0);//按下 
	keybd_event(0x09, 0, 2, 0); //松开 
	Sleep(30);

	//输入密码 
	for (i = 0; i < sizeof(pwd); i++)
	{
		keybd_event(pwd[i], 0, 0, 0);
		keybd_event(pwd[i], 0, 2, 0);
		Sleep(30);
	}

	//模拟按下tab键 让登录按钮获取焦点 
	click(824, 530);//点击"登录按钮" 
	Sleep(30);
}


//将chrome.exe进程杀掉，在例子中尚未使用 
void close()
{
	system("taskkill  /f  /im chrome.exe");
}

