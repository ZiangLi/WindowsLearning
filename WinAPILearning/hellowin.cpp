//#include <windows.h>
//#include <mmsystem.h> 
////��Ч��������������������WINMM.LIB
//#pragma comment(lib, "WINMM.LIB") 
////�Զ�����Ϣ
//#define WM_MYMSG (WM_USER + 100)
//
////�ص���������
//LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
//
//int WINAPI WinMain(HINSTANCE hInstance,      // ��ǰʵ�����
//	HINSTANCE hPrevInstance,  // ��ǰʵ�������ͨ��Ϊ��
//	LPSTR lpCmdLine,          // ������
//	int nCmdShow)            // ��ʾ״̬:��󻯡���С��
//{
//
//	//�����������
//	static TCHAR szAppName[] = TEXT("MyWindowsProgram");
//	//���
//	HWND hwnd;
//	//��Ϣ����Ϣ�ṹ�������У��������Ϣʶ�����������Ϣ��������Ϣ����ϢͶ��ʱ�䡢��ϢͶ��ʱ�Ĺ��λ��
//	//��Ϣ����ϵͳ��д�ġ�
//	MSG  msg;
//	//������
//	WNDCLASS wndclass;
//	//���ڷ�񣬿������κ�Class Styles�����
//	wndclass.style = CS_HREDRAW | CS_VREDRAW;//���˶����ߴ�С����ʱ�ػ洰��
//	//ָ�򴰿ڹ��̣�����ʹ�ûص��������ô��ڹ���
//	wndclass.lpfnWndProc = WndProc;
//	//ָ������ı��������䴰����ṹ
//	wndclass.cbClsExtra = 0;
//	//ָ������ı��������䴰��ʵ��
//	wndclass.cbWndExtra = 0;
//	//ʵ�����
//	wndclass.hInstance = hInstance;
//	//ͼ�꣺װ��ͼ�꺯����Ӧ��ʵ����ͼ�����ͣ�������ʹ��Ĭ��ͼ��
//	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
//	//���:װ�ع�꺯����Ӧ��ʵ����������ͣ�������ʹ�ñ�׼��ͷ
//	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
//	//����:ˢ������ ��ɫ
//	wndclass.hbrBackground = (HBRUSH)GetStockObject(DKGRAY_BRUSH);
//	//�˵���������ʱû��
//	wndclass.lpszMenuName = NULL;
//	//0��β���ַ������߰�ť��������һ���ַ�����ָ����������
//	wndclass.lpszClassName = szAppName;
//
//	//ע�ᴰ��
//	if (!RegisterClass(&wndclass))
//	{
//		return 0;
//	}
//	//��������
//	/*
//	hwnd = CreateWindow(szAppName,				  //��������
//		TEXT("�ҵ�windows����"),  //���ڱ�ǩ
//		WS_OVERLAPPEDWINDOW,	  //���ڷ��
//		CW_USEDEFAULT,			  //X����
//		CW_USEDEFAULT,			  //Y����
//		CW_USEDEFAULT,			  //���
//		CW_USEDEFAULT,			  //�߶�
//		NULL,					  //�����ھ��
//		NULL,					  //���ڲ˵����
//		hInstance,				  //����ʵ�����
//		NULL);					  //��������
//	*/
//	hwnd = CreateWindowEx(NULL, NULL, szAppName,
//		WS_OVERLAPPEDWINDOW | WS_VISIBLE, 500, 500,
//		500, 500, NULL, NULL, hInstance, NULL);
//
//	//��ʾ����,����Ϊ�����ھ������ʾ״̬
//	ShowWindow(hwnd,SW_SHOWNORMAL);
//	//���´���
//	UpdateWindow(hwnd);
//
//
//	while (GetMessage(&msg, NULL, 0, 0))	//��ȡ��Ϣ������ָ��MSG�ṹ,���ھ����NULL��ʾ�����̵߳��κδ��ڣ�����һ����Ϣ�����һ����Ϣ
//	{
//		//�������Ϣת��Ϊ�ַ���Ϣ�ַ���Ϣ�����͵������̵߳���Ϣ���������һ���̵߳��ú���GetMessage��PeekMessageʱ������
//		TranslateMessage(&msg);
//		//�ú����ַ�һ����Ϣ�����ڳ���ͨ����Ϣ��GetMessage������á���Ϣ���ַ����ص����������̺���)����������Ϣ���ݸ�����ϵͳ��Ȼ�����ϵͳȥ�������ǵĻص�������Ҳ����˵�����ڴ���Ĺ��̺����д�����Ϣ��
//		DispatchMessage(&msg);
//	}
//	//msg.wParam���˳���Ϣ
//	return msg.wParam;
//}
//
////�ص��������ɳ���Ա���壬ϵͳ���õĺ���,ǰ��������Ϣ��������������Win16ϵͳ���������Ĳ���
//LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
//{
//	//�豸���ݾ��
//	HDC hdc;
//	//PAINTSTRUCT�ṹ�����˻��ƿͻ��������Ϣ����һ����������HDC���
//	PAINTSTRUCT ps;
//	RECT rect;
//	switch (message)
//	{
//		//����������Ϣ��CreateWindow�����������Ժ�ͻᷢ���������Ϣ��������Ϣ���С�
//	case WM_CREATE:
//		//����Ϊ�����ŵ����������м��������һ��ΪNULL������ʹ��SND_RESOURCE ���ű�Ǳ�ǣ������ű�ǣ�ͬ�����첽���������ڣ���������������£�ͬ������һ���ţ��첽���ڵ�ڶ���ʱֹͣ��һ�µ�������ֱ�Ӳ��ŵڶ��£�
//		//ֻ�ܲ���wav��ʽ
//		//PlaySound(TEXT ("D:/videos/msg.wav"),NULL,SND_FILENAME | SND_SYNC);
//		return 0;
//		//���ƴ�����Ϣ
//	case WM_PAINT:
//
//		//BeginPaint����׼��ָ���Ĵ��ڻ�ͼ
//		//����Ϊ�����ھ����ָ��PAINTSTRUCT�ṹ�Ļ�ͼ��Ϣ
//		hdc = BeginPaint(hwnd, &ps);
//		//��ȡ�ͻ��������꣺����Ϊ����Ҫ����ȡ����Ĵ��ڣ�ָ��RECT�ṹ��ָ�����������
//		GetClientRect(hwnd, &rect);
//		//��ָ�����򻭸�ʽ�����ı�
//		//����Ϊ���豸���ݾ������Ҫ��չʾ���ַ����ı����ȣ�-1��ʾ�ٶ���0��β�ģ���RECT���͵ĵ�ַ�������ı���Ҫ�����ﱻ��ʽ������ʽ����ʽ��������ˮƽ����ֱ������
//		DrawText(hdc, TEXT("Hello, Windows7!"), -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
//		PlaySound(TEXT("D:/videos/msg.wav"), NULL, SND_FILENAME | SND_SYNC);
//		//���ƴ��ڽ���
//		EndPaint(hwnd, &ps);
//		return 0;
//
//	case WM_LBUTTONDOWN:
//		//��ָ�������Ϊ��Ч��
//		//PlaySound(TEXT ("D:/videos/msg.wav"),NULL,SND_FILENAME | SND_SYNC);
//		//ʹָ�������Ϊ��Ч����Ȼ����Զ�����paint����
//		//InvalidateRect(hwnd,NULL,FALSE);
//		//������Ϣ������Ϊ����Ϣ����˭����ʲô��Ϣ������������Ϣ��Ϣ
//		//SendMessage(hwnd,WM_MYMSG,wParam,lParam);
//		if (wParam & MK_RBUTTON)//ͬʱ�Ҽ�Ҳ����
//			PlaySound(TEXT("D:/videos/msg.wav"), NULL, SND_FILENAME | SND_SYNC);
//		return 0;
//
//	case WM_RBUTTONDOWN:
//		if (wParam & MK_LBUTTON)
//			PlaySound(TEXT("D:/videos/msg.wav"), NULL, SND_FILENAME | SND_SYNC);
//		return 0;
//
//	case WM_MYMSG:
//		PlaySound(TEXT("D:/videos/msg.wav"), NULL, SND_FILENAME | SND_SYNC);
//		return 0;
//
//		//�رմ�����Ϣ
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		return 0;
//
//	}
//	return DefWindowProc(hwnd, message, wParam, lParam); //ִ��ȱʡ��Ϣ
//}