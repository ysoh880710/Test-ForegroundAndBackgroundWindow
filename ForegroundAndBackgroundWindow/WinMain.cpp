#include <Windows.h>

HINSTANCE__* g_pInstance = nullptr;

//#define SINGLETHREAD

long long __stdcall WndProc(HWND__* const _pWindow, const unsigned int _unMessage, const unsigned long long _ullWParam, const long long _llLParam)
{
	switch (_unMessage)
	{
	case WM_CREATE:
		{
			//SetTimer(_pWindow, reinterpret_cast<unsigned long long>(_pWindow), 1u, nullptr);
		}
		break;
	case WM_CLOSE:
		{
		}
		break;
	case WM_DESTROY:
		{
		}
		break;
	case WM_TIMER:
		{
			//unsigned long long ullValue = 0ull;
			//for (unsigned long long i = 0ull; i < 5000000ull; ++i)
			//{
			//	++ullValue;
			//}
			//
			//static unsigned long long ullCount = 0ull;
			//wchar_t pString[256]{};
			//_ui64tow_s(ullCount, pString, 256, 10);
			//SetWindowTextW(_pWindow, pString);
			//++ullCount;
		}
		break;
	default:
		break;
	}

	return DefWindowProcW(_pWindow, _unMessage, _ullWParam, _llLParam);
}

unsigned long __stdcall Thread0(void* const _pParameter)
{
	tagWNDCLASSEXW stWNDCLASSEXW0
	{
		sizeof(tagWNDCLASSEXW),
		static_cast<unsigned int>(CS_VREDRAW | CS_HREDRAW),
		&WndProc,
		0,
		0,
		g_pInstance,
		nullptr,
		static_cast<HICON__*>(LoadImageW(nullptr, static_cast<const wchar_t*>(IDC_ARROW), static_cast<unsigned int>(IMAGE_CURSOR), 0, 0, static_cast<unsigned int>(LR_SHARED))),
		static_cast<HBRUSH__*>(GetStockObject(WHITE_BRUSH)),
		L"MenuName",
		L"ClassName0",
		nullptr
	};

	unsigned short usWindowClass0 = RegisterClassExW(&stWNDCLASSEXW0);

	HWND__* const pWindow0 = CreateWindowExW(0ul,
											 reinterpret_cast<const wchar_t*>(usWindowClass0),
											 L"0",
											 static_cast<unsigned long>(WS_OVERLAPPEDWINDOW),
											 0,
											 0,
											 1200,
											 800,
											 nullptr,
											 nullptr,
											 g_pInstance,
											 nullptr);

	ShowWindow(pWindow0, SW_SHOW);

	tagMSG stMSG{};

	while (true)
	{
		if (PeekMessageW(&stMSG, nullptr, 0, 0, static_cast<unsigned int>(PM_REMOVE)) != 0)
		{
			if (stMSG.message == static_cast<unsigned int>(WM_QUIT))
			{
				break;
			}

			TranslateMessage(&stMSG);
			DispatchMessageW(&stMSG);
		}
	}

	return 0ul;
}

unsigned long __stdcall Thread1(void* const _pParameter)
{
	tagWNDCLASSEXW stWNDCLASSEXW1
	{
		sizeof(tagWNDCLASSEXW),
		static_cast<unsigned int>(CS_VREDRAW | CS_HREDRAW),
		&WndProc,
		0,
		0,
		g_pInstance,
		nullptr,
		static_cast<HICON__*>(LoadImageW(nullptr, static_cast<const wchar_t*>(IDC_ARROW), static_cast<unsigned int>(IMAGE_CURSOR), 0, 0, static_cast<unsigned int>(LR_SHARED))),
		static_cast<HBRUSH__*>(GetStockObject(WHITE_BRUSH)),
		L"MenuName",
		L"ClassName1",
		nullptr
	};

	unsigned short usWindowClass1 = RegisterClassExW(&stWNDCLASSEXW1);

	HWND__* const pWindow1 = CreateWindowExW(0ul,
											 reinterpret_cast<const wchar_t*>(usWindowClass1),
											 L"1",
											 static_cast<unsigned long>(WS_OVERLAPPEDWINDOW),
											 400,
											 0,
											 1200,
											 800,
											 nullptr,
											 nullptr,
											 g_pInstance,
											 nullptr);

	ShowWindow(pWindow1, SW_SHOW);

	tagMSG stMSG{};

	while (true)
	{
		if (PeekMessageW(&stMSG, nullptr, 0, 0, static_cast<unsigned int>(PM_REMOVE)) != 0)
		{
			if (stMSG.message == static_cast<unsigned int>(WM_QUIT))
			{
				break;
			}

			TranslateMessage(&stMSG);
			DispatchMessageW(&stMSG);
		}
	}

	return 0ul;
}

int __stdcall wWinMain(HINSTANCE__* const _pInstance,
					   HINSTANCE__* const _pPrevInstance,
					   wchar_t* const _pCmdLine,
					   const int _nCmdShow)
{
	g_pInstance = _pInstance;

#ifdef SINGLETHREAD
	tagWNDCLASSEXW stWNDCLASSEXW0
	{
		sizeof(tagWNDCLASSEXW),
		static_cast<unsigned int>(CS_VREDRAW | CS_HREDRAW),
		&WndProc,
		0,
		0,
		_pInstance,
		nullptr,
		static_cast<HICON__*>(LoadImageW(nullptr, static_cast<const wchar_t*>(IDC_ARROW), static_cast<unsigned int>(IMAGE_CURSOR), 0, 0, static_cast<unsigned int>(LR_SHARED))),
		static_cast<HBRUSH__*>(GetStockObject(WHITE_BRUSH)),
		L"MenuName",
		L"ClassName0",
		nullptr
	};

	unsigned short usWindowClass0 = RegisterClassExW(&stWNDCLASSEXW0);

	HWND__* const pWindow0 = CreateWindowExW(0ul,
											 reinterpret_cast<const wchar_t*>(usWindowClass0),
											 L"0",
											 static_cast<unsigned long>(WS_OVERLAPPEDWINDOW),
											 0,
											 0,
											 1200,
											 800,
											 nullptr,
											 nullptr,
											 _pInstance,
											 nullptr);

	ShowWindow(pWindow0, SW_SHOW);

	tagWNDCLASSEXW stWNDCLASSEXW1
	{
		sizeof(tagWNDCLASSEXW),
		static_cast<unsigned int>(CS_VREDRAW | CS_HREDRAW),
		&WndProc,
		0,
		0,
		_pInstance,
		nullptr,
		static_cast<HICON__*>(LoadImageW(nullptr, static_cast<const wchar_t*>(IDC_ARROW), static_cast<unsigned int>(IMAGE_CURSOR), 0, 0, static_cast<unsigned int>(LR_SHARED))),
		static_cast<HBRUSH__*>(GetStockObject(WHITE_BRUSH)),
		L"MenuName",
		L"ClassName1",
		nullptr
	};

	unsigned short usWindowClass1 = RegisterClassExW(&stWNDCLASSEXW1);

	HWND__* const pWindow1 = CreateWindowExW(0ul,
											 reinterpret_cast<const wchar_t*>(usWindowClass1),
											 L"1",
											 static_cast<unsigned long>(WS_OVERLAPPEDWINDOW),
											 100,
											 100,
											 1200,
											 800,
											 nullptr,
											 nullptr,
											 _pInstance,
											 nullptr);

	ShowWindow(pWindow1, SW_SHOW);

	tagMSG stMSG{};

	while (true)
	{
		if (PeekMessageW(&stMSG, nullptr, 0, 0, static_cast<unsigned int>(PM_REMOVE)) != 0)
		{
			if (stMSG.message == static_cast<unsigned int>(WM_QUIT))
			{
				break;
			}

			TranslateMessage(&stMSG);
			DispatchMessageW(&stMSG);
		}
	}
#else

	unsigned long ulThreadID0 = 0ul;
	unsigned long ulThreadID1 = 0ul;

	void* pThread0 = CreateThread(nullptr, 0ull, &Thread0, nullptr, 0ul, &ulThreadID0);
	void* pThread1 = CreateThread(nullptr, 0ull, &Thread1, nullptr, 0ul, &ulThreadID1);
#endif // SINGLETHREAD

	Sleep(100000ul);

	return 0;
}