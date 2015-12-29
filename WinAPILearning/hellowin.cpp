//#include <windows.h>
//#include <mmsystem.h> 
////等效于添加了在设置里添加了WINMM.LIB
//#pragma comment(lib, "WINMM.LIB") 
////自定义消息
//#define WM_MYMSG (WM_USER + 100)
//
////回调函数声明
//LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
//
//int WINAPI WinMain(HINSTANCE hInstance,      // 当前实例句柄
//	HINSTANCE hPrevInstance,  // 先前实例句柄，通常为空
//	LPSTR lpCmdLine,          // 命令行
//	int nCmdShow)            // 显示状态:最大化、最小化
//{
//
//	//窗口类的名字
//	static TCHAR szAppName[] = TEXT("MyWindowsProgram");
//	//句柄
//	HWND hwnd;
//	//消息：消息结构体内容有：句柄、消息识别符、附加消息、附加消息、消息投递时间、消息投递时的光标位置
//	//消息是由系统填写的。
//	MSG  msg;
//	//窗口类
//	WNDCLASS wndclass;
//	//窗口风格，可以是任何Class Styles的组合
//	wndclass.style = CS_HREDRAW | CS_VREDRAW;//当运动或者大小调整时重绘窗口
//	//指向窗口过程，必须使用回调函数调用窗口过程
//	wndclass.lpfnWndProc = WndProc;
//	//指定额外的比特数分配窗口类结构
//	wndclass.cbClsExtra = 0;
//	//指定额外的比特数分配窗口实例
//	wndclass.cbWndExtra = 0;
//	//实例句柄
//	wndclass.hInstance = hInstance;
//	//图标：装载图标函数（应用实例，图标类型），这里使用默认图标
//	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
//	//光标:装载光标函数（应用实例，光标类型），这里使用标准箭头
//	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
//	//背景:刷子类型 白色
//	wndclass.hbrBackground = (HBRUSH)GetStockObject(DKGRAY_BRUSH);
//	//菜单：这里暂时没有
//	wndclass.lpszMenuName = NULL;
//	//0结尾的字符串或者按钮：这里是一个字符串，指明窗口类名
//	wndclass.lpszClassName = szAppName;
//
//	//注册窗口
//	if (!RegisterClass(&wndclass))
//	{
//		return 0;
//	}
//	//创建窗口
//	/*
//	hwnd = CreateWindow(szAppName,				  //窗口类名
//		TEXT("我的windows程序"),  //窗口标签
//		WS_OVERLAPPEDWINDOW,	  //窗口风格：
//		CW_USEDEFAULT,			  //X坐标
//		CW_USEDEFAULT,			  //Y坐标
//		CW_USEDEFAULT,			  //宽度
//		CW_USEDEFAULT,			  //高度
//		NULL,					  //父窗口句柄
//		NULL,					  //窗口菜单句柄
//		hInstance,				  //程序实例句柄
//		NULL);					  //创建参数
//	*/
//	hwnd = CreateWindowEx(NULL, NULL, szAppName,
//		WS_OVERLAPPEDWINDOW | WS_VISIBLE, 500, 500,
//		500, 500, NULL, NULL, hInstance, NULL);
//
//	//显示窗口,参数为：窗口句柄，显示状态
//	ShowWindow(hwnd,SW_SHOWNORMAL);
//	//更新窗口
//	UpdateWindow(hwnd);
//
//
//	while (GetMessage(&msg, NULL, 0, 0))	//获取消息参数：指向MSG结构,窗口句柄（NULL表示调用线程的任何窗口），第一条消息，最后一条消息
//	{
//		//虚拟键消息转换为字符消息字符消息被寄送到调用线程的消息队列里，当下一次线程调用函数GetMessage或PeekMessage时被读出
//		TranslateMessage(&msg);
//		//该函数分发一个消息给窗口程序。通常消息从GetMessage函数获得。消息被分发到回调函数（过程函数)，作用是消息传递给操作系统，然后操作系统去调用我们的回调函数，也就是说我们在窗体的过程函数中处理消息。
//		DispatchMessage(&msg);
//	}
//	//msg.wParam是退出消息
//	return msg.wParam;
//}
//
////回调函数：由程序员定义，系统调用的函数,前两个是消息参数，后两个是Win16系统遗留下来的产物
//LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
//{
//	//设备内容句柄
//	HDC hdc;
//	//PAINTSTRUCT结构包含了绘制客户区域的信息，第一个参数就是HDC类的
//	PAINTSTRUCT ps;
//	RECT rect;
//	switch (message)
//	{
//		//创建窗口消息：CreateWindow函数被调用以后就会发出，这个消息不进入消息队列。
//	case WM_CREATE:
//		//参数为：播放的声音，（中间这个参数一般为NULL，除非使用SND_RESOURCE 播放标记标记），播放标记（同步和异步的区别在于：如果你连续点两下，同步会逐一播放；异步会在点第二下时停止第一下的声音，直接播放第二下）
//		//只能播放wav格式
//		//PlaySound(TEXT ("D:/videos/msg.wav"),NULL,SND_FILENAME | SND_SYNC);
//		return 0;
//		//绘制窗口消息
//	case WM_PAINT:
//
//		//BeginPaint函数准备指定的窗口画图
//		//参数为：窗口句柄、指向PAINTSTRUCT结构的画图信息
//		hdc = BeginPaint(hwnd, &ps);
//		//获取客户区的坐标：参数为：将要被获取坐标的窗口，指向RECT结构的指针来存放坐标
//		GetClientRect(hwnd, &rect);
//		//在指定区域画格式化的文本
//		//参数为：设备内容句柄，将要被展示的字符，文本长度（-1表示假定是0结尾的），RECT类型的地址，表明文本将要在那里被格式化，格式化方式：这里是水平、垂直都居中
//		DrawText(hdc, TEXT("Hello, Windows7!"), -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
//		PlaySound(TEXT("D:/videos/msg.wav"), NULL, SND_FILENAME | SND_SYNC);
//		//绘制窗口结束
//		EndPaint(hwnd, &ps);
//		return 0;
//
//	case WM_LBUTTONDOWN:
//		//是指定区域变为无效区
//		//PlaySound(TEXT ("D:/videos/msg.wav"),NULL,SND_FILENAME | SND_SYNC);
//		//使指定区域变为无效区，然后会自动调用paint函数
//		//InvalidateRect(hwnd,NULL,FALSE);
//		//发送消息，参数为：消息发给谁、发什么消息、两个附加消息信息
//		//SendMessage(hwnd,WM_MYMSG,wParam,lParam);
//		if (wParam & MK_RBUTTON)//同时右键也按下
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
//		//关闭窗口消息
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		return 0;
//
//	}
//	return DefWindowProc(hwnd, message, wParam, lParam); //执行缺省消息
//}