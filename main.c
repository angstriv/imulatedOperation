#define true 1

#include <stdio.h>
#include <windows.h>
#include "implement_method.h"
#include "keyEvent.h"

int main()
{
	//open_web("");//��ĳ����ַ 
	//Sleep(4000);//��ʱ4�룬�ȴ���ҳ����ϣ��ٽ�����������������ʵ���������������ٶȣ����٣�
	
	while (true)
	{
		if (keyPress(VK_ESCAPE) == 0)//���escû�б�����
		{
			click(1040, 880);//���"��ʼ" ����
			Sleep(500);//�ӳ�
		}
		else//���esc������
		{
			return 0;//��������
		}
		
	}
	

	return 0;
}