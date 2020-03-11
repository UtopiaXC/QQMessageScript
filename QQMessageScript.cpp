// QQMessageScript.cpp : 定义应用程序的入口点。
//

#include "framework.h"
#include "QQMessageScript.h"

#define MAX_LOADSTRING 100

using namespace std;

// 全局变量:
HINSTANCE hInst;                                // 当前实例
WCHAR szTitle[MAX_LOADSTRING];                  // 标题栏文本
WCHAR szWindowClass[MAX_LOADSTRING];            // 主窗口类名
bool toStop = false;
bool isStatic = false;
bool isShowCount = false;
bool isRandomTime = false;
bool isLimited = false;
TCHAR def_mode[20];

list<string> list_dict;
int max=500;
int min=500;
int icount = -1;
string static_string;

// 此代码模块中包含的函数的前向声明:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
string TCHAR2STRING(TCHAR* STR);
bool isEqual(TCHAR t1[], TCHAR t2[]);
void Script();

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 在此处放置代码。

    // 初始化全局字符串
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_QQMESSAGESCRIPT, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 执行应用程序初始化:
    if (!InitInstance(hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_QQMESSAGESCRIPT));

    MSG msg;



    // 主消息循环:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int)msg.wParam;
}



//
//  函数: MyRegisterClass()
//
//  目标: 注册窗口类。
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_QQMESSAGESCRIPT));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_QQMESSAGESCRIPT);
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_QQMESSAGESCRIPT));

    return RegisterClassExW(&wcex);
}

//
//   函数: InitInstance(HINSTANCE, int)
//
//   目标: 保存实例句柄并创建主窗口
//
//   注释:
//
//        在此函数中，我们在全局变量中保存实例句柄并
//        创建和显示主程序窗口。
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
    hInst = hInstance; // 将实例句柄存储在全局变量中

    HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT,900,530,nullptr, nullptr, hInstance, nullptr);

    if (!hWnd)
    {
        return FALSE;
    }

    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);


    return TRUE;
}

//
//  函数: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  目标: 处理主窗口的消息。
//
//  WM_COMMAND  - 处理应用程序菜单
//  WM_PAINT    - 绘制主窗口
//  WM_DESTROY  - 发送退出消息并返回
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam){

    

    

    
    switch (message){

    case WM_COMMAND:{
        int wmId = LOWORD(wParam);
        
        // 分析菜单选择:
        switch (wmId) {
        case IDM_ABOUT:
            DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
            break;
        case IDM_EXIT:
            DestroyWindow(hWnd);
            break;
        case IDC_BUTTON_START: {

            MessageBox(hWnd, L"脚本将在点击确认后的五秒时开始.请注意,本脚本的实质执行模拟QQ消息发送,请确保在执行中输入光标不要离开QQ消息窗口!在接下来五秒内本程序将挂起,您将无法对本程序进行任何操作.", L"提醒", 0);
            Sleep(5000);

            //确认是否勾选不变字节
            if (BST_CHECKED == IsDlgButtonChecked(hWnd, IDC_CHECK_USE_STATIC))
                isStatic = true;
            else
                isStatic = false;

            //确认是否勾选显示队列序号
            if (BST_CHECKED == IsDlgButtonChecked(hWnd, IDC_CHECK_SHOW_COUNT))
                isShowCount = true;
            else
                isShowCount = false;

            //确认是否勾选随机间隔
            if (BST_CHECKED == IsDlgButtonChecked(hWnd, IDC_CHECK_USE_RANDOM))
                isRandomTime = true;
            else
                isRandomTime = false;

            double in_max = 0;
            double in_min = 0;

            HWND hEditMin = GetDlgItem(hWnd, IDC_EDIT_MIN);
            char temp_min[20];
            SendMessage(hEditMin, WM_GETTEXT, 1000, (LPARAM)temp_min);
            char min_in[20];
            int min_in_count = 0;
            for (int i = 0; i < 20; i++) {
                if (temp_min[i] == '1' || temp_min[i] == '2' || temp_min[i] == '3' || temp_min[i] == '4' ||
                    temp_min[i] == '5' || temp_min[i] == '6' || temp_min[i] == '7' || temp_min[i] == '8' ||
                    temp_min[i] == '9' || temp_min[i] == '0' || temp_min[i] == '.')
                    min_in[min_in_count++]= temp_min[i];
            }
            if(min_in_count!=0)
                in_min = stod(min_in);

            HWND hEditMax = GetDlgItem(hWnd, IDC_EDIT_MAX);
            char temp_max[20];
            SendMessage(hEditMax, WM_GETTEXT, 1000, (LPARAM)temp_max);
            char max_in[20];
            int max_in_count = 0;
            for (int i = 0; i < 20; i++) {
                if (temp_max[i] == '1' || temp_max[i] == '2' || temp_max[i] == '3' || temp_max[i] == '4' ||
                    temp_max[i] == '5' || temp_max[i] == '6' || temp_max[i] == '7' || temp_max[i] == '8' ||
                    temp_max[i] == '9' || temp_max[i] == '0' || temp_max[i] == '.')
                    max_in[max_in_count++] = temp_max[i];
            }
            if (max_in_count != 0)
                in_max = stod(max_in);

            min = (int)in_min * 1000;
            max = (int)in_max * 1000;

            if (max <= min)
                isRandomTime = false;

            HWND hEditLimit = GetDlgItem(hWnd, IDC_EDIT_COUNT);
            char temp_count[20];
            SendMessage(hEditLimit, WM_GETTEXT, 1000, (LPARAM)temp_count);
            char count_in[20];
            int count_in_count = 0;
            for (int i = 0; i < 20; i++) {
                if (temp_count[i] == '1' || temp_count[i] == '2' || temp_count[i] == '3' || temp_count[i] == '4' ||
                    temp_count[i] == '5' || temp_count[i] == '6' || temp_count[i] == '7' || temp_count[i] == '8' ||
                    temp_count[i] == '9' || temp_count[i] == '0' || temp_count[i] == '.')
                    count_in[count_in_count++] = temp_count[i];
            }
            if (max_in_count != 0) {
                icount = stoi(count_in);
                isLimited = true;
            }

            TCHAR static_text[3000];

            HWND hEditStatic = GetDlgItem(hWnd, IDC_EDIT_STATIC_STRING);
            SendMessage(hEditStatic, WM_GETTEXT, 1000, (LPARAM)static_text);
            static_string = TCHAR2STRING(static_text);

            list_dict.clear();

            HWND hWndList = GetDlgItem(hWnd, IDC_LIST_DICT);
            int count = SendMessage(hWndList, LB_GETCOUNT, 0, 0);
            for (int i = 0; i < count; i++) {
                TCHAR tchar[1000];
                SendMessage(hWndList, LB_GETTEXT,i, (LPARAM)tchar);
                list_dict.insert(list_dict.begin(), TCHAR2STRING(tchar));
            }

            new thread(Script);
            break;
        }
        case IDC_BUTTON_CANCEL: {
            toStop = true;
            MessageBox(hWnd, L"脚本已停止", L"提醒", 0);

            break;
        }
        case IDC_COMBO_DICT: {
            HWND hWndComboBox = GetDlgItem(hWnd, IDC_COMBO_DICT);
            //改变ComboBox下拉高度
            RECT rt;
            POINT p1;
            int width;
            int height;
            GetWindowRect(hWndComboBox, &rt);
            p1.x = rt.left;
            p1.y = rt.top;
            width = rt.right - rt.left;
            height = (rt.bottom - rt.top) * 5;
            ScreenToClient(hWnd, &p1);
            MoveWindow(hWndComboBox, p1.x, p1.y, width, height, TRUE);
            break;
        }
        case IDC_BUTTON_READ: {
            HWND hWndComboBox = GetDlgItem(hWnd, IDC_COMBO_DICT);
            TCHAR szMessage[20];
            SendMessage(hWndComboBox, WM_GETTEXT, 20, (LPARAM)szMessage);

            for (int i = 0; i < 20; i++) {
                def_mode[i] = szMessage[i];
                cout << szMessage[i] << endl;
            }

            TCHAR anime[20] = L"中二病";
            TCHAR girls[20] = L"敷衍  ";
            TCHAR zuan[20] = L"祖安  ";
            TCHAR erciyuan[20] = L"二刺螈";

            dicts* dict = new dicts();

            if (isEqual(def_mode, anime))
                list_dict = dict->list_anime;
            else if (isEqual(def_mode, girls))
                list_dict = dict->list_agree;
            else if (isEqual(def_mode, zuan))
                list_dict = dict->list_zuan;
            else if (isEqual(def_mode, erciyuan))
                list_dict = dict->list_girls;
            else
                MessageBox(hWnd, L"未选中字库", L"提醒", 0);

            HWND hWndList = GetDlgItem(hWnd, IDC_LIST_DICT);

            for (string str : list_dict) {
                TCHAR temp[1000];
                MultiByteToWideChar(CP_ACP, 0, (LPCSTR)str.c_str(), -1, temp, 1000);
                SendMessage(hWndList, LB_INSERTSTRING, 0, (LPARAM)temp);
            }
            break;
        }
        case IDC_BUTTON_DELETE: {
            HWND hWndList = GetDlgItem(hWnd, IDC_LIST_DICT);
            int count = SendMessage(hWndList, LB_GETCURSEL, 0, 0);
            SendMessage(hWndList, LB_DELETESTRING, count, 0);
            break;
        }
        case IDC_BUTTON_ADD: {
            HWND hWndInputWords = GetDlgItem(hWnd, IDC_EDIT_ADD_DICT);
            TCHAR temp[1000] = { L" " };
            SendMessage(hWndInputWords, WM_GETTEXT, 1000, (LPARAM)temp);
            HWND hWndList = GetDlgItem(hWnd, IDC_LIST_DICT);
            SendMessage(hWndList, LB_INSERTSTRING, 0, (LPARAM)temp);
            break;
        }
        case IDC_BUTTON_SAVE: {
            MessageBox(hWnd, L"未开放", L"提醒", 0);
            break;
        }
        case IDC_BUTTON_READFILE: {
             MessageBox(hWnd, L"未开放", L"提醒", 0);
             break;
        }
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
        }
    }
    break;
    case WM_CREATE: {
        HWND hdlg = CreateDialog(hInst, MAKEINTRESOURCE(IDD_SURFACE), hWnd, (DLGPROC)WndProc);
        // 显示对话框
        ShowWindow(hdlg, SW_SHOWNA);
     
        HWND hWndComboBox = GetDlgItem(hdlg, IDC_COMBO_DICT);
        TCHAR szMessage1[20] = L"中二病";
        TCHAR szMessage2[20] = L"敷衍  ";
        TCHAR szMessage3[20] = L"祖安  ";
        TCHAR szMessage4[20] = L"二刺螈";
        SendMessage(hWndComboBox, CB_ADDSTRING, 0, (LPARAM)szMessage1);
        SendMessage(hWndComboBox, CB_ADDSTRING, 0, (LPARAM)szMessage2);
        SendMessage(hWndComboBox, CB_ADDSTRING, 0, (LPARAM)szMessage3);
        SendMessage(hWndComboBox, CB_ADDSTRING, 0, (LPARAM)szMessage4);

       
        break;

    }
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }

   

    return 0;
}

// “关于”框的消息处理程序。
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}



void Script() {
    if (isLimited) {
        for (int i = 0; i < icount; i++) {
            if (isRandomTime) {
                string output;
                int count_string = rand()%list_dict.size();
                if (isShowCount) {
                    output.append("本条消息队列序数为:");
                    output.append(to_string(i+1));
                    output.append(" ");
                }
                if (isStatic) {
                    output.append(" ");
                    output.append(static_string);
                }
                list<string>::iterator iter=list_dict.begin();
                advance(iter, count_string );
                output.append(*iter);
                char* out = (char*)output.data();
                HWND hWnd = NULL;
                OpenClipboard(hWnd);//打开剪切板
                EmptyClipboard();//清空剪切板
                HANDLE hHandle = GlobalAlloc(GMEM_FIXED, 5000);//分配内存
                char* pData = (char*)GlobalLock(hHandle);//锁定内存，返回申请内存的首地址
                strcpy_s(pData,5000,out);//或strcpy(pData, "this is a ClipBoard Test.");
                SetClipboardData(CF_TEXT, hHandle);//设置剪切板数据
                GlobalUnlock(hHandle);//解除锁定
                CloseClipboard();//关闭剪切板
                keybd_event(VK_CONTROL, 0, 0, 0);
                keybd_event('V', 0, 0, 0);
                keybd_event(VK_CONTROL, 0, KEYEVENTF_KEYUP, 0);
                keybd_event('V', 0, KEYEVENTF_KEYUP, 0);
                keybd_event(VK_RETURN, 0, 0, 0);
                keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);
                int time = rand() % (max - min + 1) + min;
                Sleep(time);
            }
            else {
                string output;
                int count_string = rand() % list_dict.size();
                if (isShowCount) {
                    output.append("本条消息队列序数为:");
                    output.append(to_string(i+1));
                    output.append(" ");
                }
                if (isStatic) {
                    output.append(" ");
                    output.append(static_string);
                }
                list<string>::iterator iter = list_dict.begin();
                advance(iter, count_string );
                output.append(*iter);
                char* out = (char*)output.data();
                HWND hWnd = NULL;
                OpenClipboard(hWnd);//打开剪切板
                EmptyClipboard();//清空剪切板
                HANDLE hHandle = GlobalAlloc(GMEM_FIXED, 5000);//分配内存
                char* pData = (char*)GlobalLock(hHandle);//锁定内存，返回申请内存的首地址
                strcpy_s(pData,5000, out);//或strcpy(pData, "this is a ClipBoard Test.");
                SetClipboardData(CF_TEXT, hHandle);//设置剪切板数据
                GlobalUnlock(hHandle);//解除锁定
                CloseClipboard();//关闭剪切板
                keybd_event(VK_CONTROL, 0, 0, 0);
                keybd_event('V', 0, 0, 0);
                keybd_event(VK_CONTROL, 0, KEYEVENTF_KEYUP, 0);
                keybd_event('V', 0, KEYEVENTF_KEYUP, 0);
                keybd_event(VK_RETURN, 0, 0, 0);
                keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);
                Sleep(500);
            }
        }
    }
    else {
        int i = 0;
        while (true) {
            if (toStop) {
                toStop = false;
                return;
            }

            if (isRandomTime) {
                string output;
                int count_string = rand() % list_dict.size();
                if (isShowCount) {
                    output.append("本条消息队列序数为:");
                    output.append(to_string(i+1));
                    output.append(" ");
                }
                if (isStatic) {
                    output.append(" ");
                    output.append(static_string);
                }
                list<string>::iterator iter = list_dict.begin();
                advance(iter, count_string);
                output.append(*iter);
                char* out = (char*)output.data();
                HWND hWnd = NULL;
                OpenClipboard(hWnd);//打开剪切板
                EmptyClipboard();//清空剪切板
                HANDLE hHandle = GlobalAlloc(GMEM_FIXED, 5000);//分配内存
                char* pData = (char*)GlobalLock(hHandle);//锁定内存，返回申请内存的首地址
                strcpy_s(pData, 5000,out);//或strcpy(pData, "this is a ClipBoard Test.");
                SetClipboardData(CF_TEXT, hHandle);//设置剪切板数据
                GlobalUnlock(hHandle);//解除锁定
                CloseClipboard();//关闭剪切板
                keybd_event(VK_CONTROL, 0, 0, 0);
                keybd_event('V', 0, 0, 0);
                keybd_event(VK_CONTROL, 0, KEYEVENTF_KEYUP, 0);
                keybd_event('V', 0, KEYEVENTF_KEYUP, 0);
                keybd_event(VK_RETURN, 0, 0, 0);
                keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);
                int time = rand() % (max - min + 1) + min;
                Sleep(time);
            }
            else {
                string output;
                int count_string = rand() % list_dict.size();
                if (isShowCount) {
                    output.append("本条消息队列序数为:");
                    output.append(to_string(i+1));
                    output.append(" ");
                }
                if (isStatic) {
                    output.append(" ");
                    output.append(static_string);
                }
                list<string>::iterator iter = list_dict.begin();
                advance(iter, count_string);
                output.append(*iter);
                char* out = (char*)output.data();

                HWND hWnd = NULL;
                OpenClipboard(hWnd);//打开剪切板
                EmptyClipboard();//清空剪切板
                HANDLE hHandle = GlobalAlloc(GMEM_FIXED, 5000);//分配内存
                char* pData = (char*)GlobalLock(hHandle);//锁定内存，返回申请内存的首地址
                strcpy_s(pData,5000, out);//或strcpy(pData, "this is a ClipBoard Test.");
                SetClipboardData(CF_TEXT, hHandle);//设置剪切板数据
                GlobalUnlock(hHandle);//解除锁定
                CloseClipboard();//关闭剪切板
                keybd_event(VK_CONTROL, 0, 0, 0);
                keybd_event('V', 0, 0, 0);
                keybd_event(VK_CONTROL, 0, KEYEVENTF_KEYUP, 0);
                keybd_event('V', 0, KEYEVENTF_KEYUP, 0);
                keybd_event(VK_RETURN, 0, 0, 0);
                keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);
                Sleep(500);
            }
        }
    }
}

bool isEqual(TCHAR t1[],TCHAR t2[]) {
    for (int i = 0; i < sizeof(t1);i++) {
        if (t1[i] != t2[i])
            return false;
    }
    return true;
}

string TCHAR2STRING(TCHAR* STR)
{
    int iLen = WideCharToMultiByte(CP_ACP, 0, STR, -1, NULL, 0, NULL, NULL);
    char* chRtn = new char[iLen * sizeof(char)];
    WideCharToMultiByte(CP_ACP, 0, STR, -1, chRtn, iLen, NULL, NULL);
    std::string str(chRtn);
    return str;
}
