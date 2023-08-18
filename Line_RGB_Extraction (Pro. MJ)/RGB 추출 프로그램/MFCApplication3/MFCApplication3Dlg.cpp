// MFCApplication3Dlg.cpp: 구현 파일
//
#pragma once

#include "pch.h"
#include "framework.h"
#include "MFCApplication3.h"
#include "MFCApplication3Dlg.h"
#include "afxdialogex.h"
#include <atlimage.h>
#include "resource.h"

#include <iostream>
#include <string>
using namespace std;

#pragma warning (disable : 4996)

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

BOOL CMFCApplication3Dlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (pMsg->message == WM_KEYDOWN && (pMsg->wParam == VK_ESCAPE || pMsg->wParam == VK_RETURN))
		return TRUE;

	return CDialogEx::PreTranslateMessage(pMsg);
}

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplication3Dlg 대화 상자
CMFCApplication3Dlg::CMFCApplication3Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION3_DIALOG, pParent)
	, m_x1(0)
	, m_y1(0)
	, m_x2(0)
	, m_y2(0)
	, m_extend(0)
	, m_filter(1)
	, m_redgain(0)
	, greengain(0)
	, bluegain(0)
	, graygain(0)
	, m_Xresult(0)
	, m_Yresult(0)
	, m_2line_CD1(0)
	, m_2line_CD2(0)
	, m_2line_TD1(0)
	, m_2line_TD2(0)
	, m_3line_CD1(0)
	, m_3line_CD2(0)
	, m_3line_T1D1(0)
	, m_3line_T1D2(0)
	, m_3line_T2D1(0)
	, m_3line_T2D2(0)
	, m_2lineControl{}
	, m_2lineTestArea{}
	, m_2lineRatio{}
	, m_3lineControl{}
	, m_3lineTestArea1{}
	, m_3lineTestArea2{}
	, m_3lineRatio1{}
	, m_3lineRatio2{}
	, m_redresult{}
	, m_greenresult{}
	, m_blueresult{}
	, m_grayresult{}
	, m_grayvalu{}
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication3Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PIC, m_picture);
	DDX_Text(pDX, IDC_EDIT1_x1, m_x1);
	DDX_Text(pDX, IDC_EDIT2_y1, m_y1);
	DDX_Text(pDX, IDC_EDIT_lastX, m_x2);
	DDX_Text(pDX, IDC_EDIT_lastY, m_y2);
	DDX_Text(pDX, IDC_EDIT_extend, m_extend);
	DDX_Text(pDX, IDC_EDIT_filter, m_filter);
	DDX_Text(pDX, IDC_EDIT_redgain, m_redgain);
	DDX_Text(pDX, IDC_EDIT_greengain, greengain);
	DDX_Text(pDX, IDC_EDIT_bluegain, bluegain);
	DDX_Text(pDX, IDC_EDIT_graygain, graygain);
	DDX_Text(pDX, IDC_EDIT_Xresult, m_Xresult);
	DDX_Text(pDX, IDC_EDIT_Yresult, m_Yresult);
	DDX_Text(pDX, IDC_EDIT_redresult, m_redresult);
	DDX_Text(pDX, IDC_EDIT_greenresult, m_greenresult);
	DDX_Text(pDX, IDC_EDIT_blueresult, m_blueresult);
	DDX_Text(pDX, IDC_EDIT_grayresult, m_grayresult);

	DDX_Text(pDX, IDC_EDIT_2line_CD1, m_2line_CD1);
	DDX_Text(pDX, IDC_EDIT_2line_CD2, m_2line_CD2);
	DDX_Text(pDX, IDC_EDIT_2line_TD1, m_2line_TD1);
	DDX_Text(pDX, IDC_EDIT_2line_TD2, m_2line_TD2);

	DDX_Text(pDX, IDC_EDIT_2lineControl, m_2lineControl);
	DDX_Text(pDX, IDC_EDIT_2lineTestArea, m_2lineTestArea);
	DDX_Text(pDX, IDC_EDIT_2lineRatio, m_2lineRatio);

	DDX_Text(pDX, IDC_EDIT_3line_CD1, m_3line_CD1);
	DDX_Text(pDX, IDC_EDIT_3line_CD2, m_3line_CD2);
	DDX_Text(pDX, IDC_EDIT_3line_T1D1, m_3line_T1D1);
	DDX_Text(pDX, IDC_EDIT_3line_T1D2, m_3line_T1D2);
	DDX_Text(pDX, IDC_EDIT_3line_T2D1, m_3line_T2D1);
	DDX_Text(pDX, IDC_EDIT_3line_T2D2, m_3line_T2D2);

	DDX_Text(pDX, IDC_EDIT_3lineControl, m_3lineControl);
	DDX_Text(pDX, IDC_EDIT_3lineTestArea1, m_3lineTestArea1);
	DDX_Text(pDX, IDC_EDIT_3lineTestArea2, m_3lineTestArea2);
	DDX_Text(pDX, IDC_EDIT_3lineRatio1, m_3lineRatio1);
	DDX_Text(pDX, IDC_EDIT_3lineRatio2, m_3lineRatio2);

	DDX_Control(pDX, IDC_Avg, m_avg);
	DDX_Control(pDX, IDC_CHECK_260, m_260);
	DDX_Control(pDX, IDC_EDIT_redresult, redresult);
	DDX_Control(pDX, IDC_EDIT_greenresult, greenresult);
	DDX_Control(pDX, IDC_EDIT_blueresult, blueresult);
	DDX_Control(pDX, IDC_EDIT_grayresult, grayresult);
}

BEGIN_MESSAGE_MAP(CMFCApplication3Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication3Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication3Dlg::OnBnClickedButton2)
	ON_STN_CLICKED(IDC_PIC, &CMFCApplication3Dlg::OnStnClickedPic)
	ON_BN_CLICKED(IDC_BUTTON_Go, &CMFCApplication3Dlg::OnBnClickedButtonGo)
	ON_BN_CLICKED(IDC_BUTTON_road, &CMFCApplication3Dlg::OnBnClickedButtonroad)
	ON_WM_MOUSEMOVE()
	ON_WM_CTLCOLOR()
	ON_WM_VSCROLL()
	ON_BN_CLICKED(IDC_BUTTON_2lineGo, &CMFCApplication3Dlg::OnBnClickedButton2linego)
	ON_BN_CLICKED(IDC_BUTTON_3lineGo, &CMFCApplication3Dlg::OnBnClickedButton3linego)
	ON_BN_CLICKED(IDC_Avg, &CMFCApplication3Dlg::OnBnClickedAvg)
	ON_BN_CLICKED(IDC_CHECK_260, &CMFCApplication3Dlg::OnBnClickedCheck260)
	ON_BN_CLICKED(IDC_BUTTON_CUT, &CMFCApplication3Dlg::OnBnClickedButtonCut)
	ON_BN_CLICKED(IDC_BUTTON_CUT2, &CMFCApplication3Dlg::OnBnClickedButtonCut2)
	ON_BN_CLICKED(IDC_BUTTON_CUT3, &CMFCApplication3Dlg::OnBnClickedButtonCut3)
	ON_BN_CLICKED(IDC_BUTTON_CUT4, &CMFCApplication3Dlg::OnBnClickedButtonCut4)
	ON_BN_CLICKED(IDC_BUTTON_CLEAR, &CMFCApplication3Dlg::OnBnClickedButtonClear)
	ON_BN_CLICKED(IDC_BUTTON_CLEAR2, &CMFCApplication3Dlg::OnBnClickedButtonClear2)
	ON_BN_CLICKED(IDC_BUTTON_CLEAR3, &CMFCApplication3Dlg::OnBnClickedButtonClear3)
	ON_BN_CLICKED(IDC_BUTTON_CLEAR4, &CMFCApplication3Dlg::OnBnClickedButtonClear4)
END_MESSAGE_MAP()

// CMFCApplication3Dlg 메시지 처리기

BOOL CMFCApplication3Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	SetWindowText(_T("Line_RGB_Extraction v.0.0.1 (Pro. MJ)"));

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMFCApplication3Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMFCApplication3Dlg::OnPaint()
{
	CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMFCApplication3Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMFCApplication3Dlg::OnBnClickedButton1()
{
	// 이미지 파일 불러오고 띄우기

	CString szFilter = _T("All Files(*.*)|*.*||");

	CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY, szFilter);

	if (IDOK == dlg.DoModal())
	{
		// 파일 경로 불러오기
		CString strPathName = dlg.GetPathName();

		CDC* pDc = m_picture.GetWindowDC();
		CDC memdc;
		CImage m_bmpBitmap;
		int width = 0;
		int height = 0;

		m_bmpBitmap.Destroy();
		m_bmpBitmap.Load(strPathName);
		width = m_bmpBitmap.GetWidth();
		height = m_bmpBitmap.GetHeight();

		memdc.CreateCompatibleDC(pDc);
		m_bmpBitmap.Draw(pDc->m_hDC, 0, 0, width, height);

		pDc->StretchBlt(0, 0, width, height, &memdc, 0, 0, width, height, SRCCOPY);

		m_picture.ReleaseDC(pDc);

		pDc->DeleteDC();
		pDc = NULL;
	}
}

void CMFCApplication3Dlg::OnStnClickedMyPicture()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

void CMFCApplication3Dlg::OnBnClickedButton2()
{
	// clear 버튼 => 선만 없앰
	UpdateData(TRUE); // 대화상자에 입력한 값을 프로그램 상의 변수에 대입
	Invalidate();

	m_redresult = "\n";
	m_greenresult = "\n";
	m_blueresult = "\n";
	m_grayresult = "\n";
	//CClientDC line(this); // MFC의 dc 값 얻어오기

	//CPen pen;
	//pen.CreatePen(PS_SOLID, 1, RGB(237, 237, 237));

	//CPen* oldPen = line.SelectObject(&pen);

	//// Extend 만큼 간격으로 선 세개 그리기
	//line.MoveTo(m_x1, m_y1);
	//line.LineTo(m_x1, m_y1);
	//line.SelectObject(oldPen);

	//pen.DeleteObject();
	//CDialogEx::OnPaint();

	UpdateData(FALSE); // 프로그램 상 변수 값이 대화상자에 입력
}

void CMFCApplication3Dlg::OnStnClickedPic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMFCApplication3Dlg::OnBnClickedButtonGo()
{
	UpdateData(TRUE); // 대화상자에 입력한 값을 프로그램 상의 변수에 대입
	m_redresult = "\n";
	m_greenresult = "\n";
	m_blueresult = "\n";
	m_grayresult = "\n";
	int filter = (m_filter * 2) - 2;
	int n_m_extend = m_extend + 1;
	// x는 고정, y2 - y1만큼 한줄의 RED 값 불러와 출력하기
	CClientDC dc(this); // MFC의 dc 값 얻어오
	int m_realX1 = m_x1 + 18; // Picture Control 좌표에 맞춤
	int m_realY1 = m_y1 + 54; // Picture Control 좌표에 맞춤
	int m_realX2 = m_x2 + 18; // Picture Control 좌표에 맞춤
	int m_realY2 = m_y2 + 54; // Picture Control 좌표에 맞춤2

	double r = 0; // RGB에서 얻은 r 값 저장할 변수
	double Rrgb_byte[200] = {}; // 한 줄의 r 값을 저장할 배열
	double red[200] = {};
	CString m_red; // rgb_byte double -> CString 값 저장할 변수

	double g = 0; // RGB에서 얻은 r 값 저장할 변수
	double Grgb_byte[200] = {}; // 한 줄의 r 값을 저장할 배열
	double green[200] = {};
	CString m_green; // rgb_byte double -> CString 값 저장할 변수

	double b = 0; // RGB에서 얻은 r 값 저장할 변수
	double Brgb_byte[200] = {}; // 한 줄의 r 값을 저장할 배열
	double blue[200] = {};
	CString m_blue; // rgb_byte double -> CString 값 저장할 변수

	double gray = 0; // RGB에서 얻은 r 값 저장할 변수
	double rgb_byte[200] = {}; // 한 줄의 r 값을 저장할 배열
	CString m_gray; // rgb_byte double -> CString 값 저장할 변수

	int i1 = 0;

	if (avg_check == TRUE)
	{
		while (i1 < m_realY2 - m_realY1) // y2 - y1 만큼 값을 얻기 위한 반복문
		{
			// RED
			int i2 = 0;
			if (m_extend == 0)
			{
				COLORREF rrgb = GetPixel(dc, m_realX1, m_realY1 + i1); // 해당 위치의 RGB값을 얻는 함수
				r = GetRValue(rrgb);
			}
			else if (m_extend > 0)
			{
				while (i2 < n_m_extend)
				{
					if (i2 == 0)
					{
						COLORREF rrgb = GetPixel(dc, m_realX1, m_realY1 + i1); // 해당 위치의 RGB값을 얻는 함수
						r += GetRValue(rrgb);
						i2++;
					}
					else if (i2 > 0)
					{
						COLORREF rrgb = GetPixel(dc, m_realX1 + i2, m_realY1 + i1); // 해당 위치의 RGB값을 얻는 함수
						r += GetRValue(rrgb);
						rrgb = GetPixel(dc, m_realX1 - i2, m_realY1 + i1); // 해당 위치의 RGB값을 얻는 함수
						r += GetRValue(rrgb);
						i2++;
					}
				}
			}
			if (check_260 == TRUE)
			{
				if (m_redgain == 0)
				{
					if (m_extend == 0)
					{
						Rrgb_byte[i1] = 260 - r;
					}
					else if (m_extend > 0)
					{
						Rrgb_byte[i1] = 260 - (r / (m_extend * 2)); // 배열에 저
					}
				}
				else if (m_redgain != 0)
				{
					if (m_extend == 0)
					{
						Rrgb_byte[i1] = (260 - r) * m_redgain;
					}
					else if (m_extend > 0)
					{
						Rrgb_byte[i1] = (260 - (r / (m_extend * 2))) * m_redgain; // 배열에 저
					}
				}
			}
			else if (check_260 == FALSE)
			{
				if (m_redgain == 0)
				{
					if (m_extend == 0)
					{
						Rrgb_byte[i1] = r;
					}
					else if (m_extend > 0)
					{
						Rrgb_byte[i1] = r / (m_extend * 2); // 배열에 저
					}
				}
				else if (m_redgain != 0)
				{
					if (m_extend == 0)
					{
						Rrgb_byte[i1] = r * m_redgain;
					}
					else if (m_extend > 0)
					{
						Rrgb_byte[i1] = (r / (m_extend * 2)) * m_redgain; // 배열에 저
					}
				}
			}
			red[i1] = r;
			i1++;
			r = 0;
		}
		i1 = 0;
		if (m_filter > 1)
		{
			int i0 = 0;
			while (i0 < m_realY2 - m_realY1)
			{
				int i = 0;
				double sum = 0;
				while (i < m_filter)
				{
					sum += Rrgb_byte[((m_filter + i0) - 1) - i];
					i++;
				}
				Rrgb_byte[i0] = sum / (double)m_filter;
				i0++;
			}
			i0 = 0;
		}
		if (m_filter == 1)
		{
			while ((i1 < 165))
			{
				m_red.Format(_T("%.2f"), Rrgb_byte[i1]); // 배열의 double을 CString으로 바꿔서 저장
				m_redresult += m_red; // CString R 값 출력
				m_redresult += "\r\n"; // 한 줄 바꿈
				i1++;
			}
		}
		else if (m_filter > 1)
		{
			while (i1 < 165 - filter)
			{
				m_red.Format(_T("%.2f"), Rrgb_byte[i1]); // 배열의 double을 CString으로 바꿔서 저장
				m_redresult += m_red; // CString R 값 출력
				m_redresult += "\r\n"; // 한 줄 바꿈
				i1++;
			}
		}
		i1 = 0;
		while(i1 < m_realY2 - m_realY1)
		{
			// GREEN
			int i3 = 0;
			if (m_extend == 0)
			{
				COLORREF grgb = GetPixel(dc, m_realX1, m_realY1 + i1); // 해당 위치의 RGB값을 얻는 함수
				g = GetGValue(grgb);
			}
			else if (m_extend > 0)
			{
				while (i3 < n_m_extend)
				{
					if (i3 == 0)
					{
						COLORREF grgb = GetPixel(dc, m_realX1, m_realY1 + i1); // 해당 위치의 RGB값을 얻는 함수
						g += GetGValue(grgb);
						i3++;
					}
					else if (i3 > 0)
					{
						COLORREF grgb = GetPixel(dc, m_realX1 + i3, m_realY1 + i1); // 해당 위치의 RGB값을 얻는 함수
						g += GetGValue(grgb);
						grgb = GetPixel(dc, m_realX1 - i3, m_realY1 + i1); // 해당 위치의 RGB값을 얻는 함수
						g += GetGValue(grgb);
						i3++;
					}
				}
			}
			if (check_260 == TRUE)
			{
				if (greengain == 0)
				{
					if (m_extend == 0)
					{
						Grgb_byte[i1] = 260 - g;
					}
					else if (m_extend > 0)
					{
						Grgb_byte[i1] = 260 - (g / (m_extend * 2)); // 배열에 저장
					}
				}
				else if (greengain != 0)
				{
					if (m_extend == 0)
					{
						Grgb_byte[i1] = (260 - g) * greengain;
					}
					else if (m_extend > 0)
					{
						Grgb_byte[i1] = (260 - (g / (m_extend * 2))) * greengain; // 배열에 저장
					}
				}
			}
			else if (check_260 == FALSE)
			{
				if (greengain == 0)
				{
					if (m_extend == 0)
					{
						Grgb_byte[i1] = g;
					}
					else if (m_extend > 0)
					{
						Grgb_byte[i1] = g / (m_extend * 2); // 배열에 저장
					}
				}
				else if (greengain != 0)
				{
					if (m_extend == 0)
					{
						Grgb_byte[i1] = g * greengain;
					}
					else if (m_extend > 0)
					{
						Grgb_byte[i1] = (g / (m_extend * 2)) * greengain; // 배열에 저장
					}
				}
			}
			green[i1] = g;
			i1++;
			g = 0;
		}
		i1 = 0;
		if (m_filter > 1)
		{
			int i0 = 0;
			while (i0 < m_realY2 - m_realY1)
			{
				int i = 0;
				double sum = 0;
				while (i < m_filter)
				{
					sum += Grgb_byte[((m_filter + i0) - 1) - i];
					i++;
				}
				Grgb_byte[i0] = sum / (double)m_filter;
				i0++;
			}
			i0 = 0;
		}
		if (m_filter == 1)
		{
			while (i1 < 165)
			{
				m_green.Format(_T("%.2f"), Grgb_byte[i1]); // 배열의 double을 CString으로 바꿔서 저장
				m_greenresult += m_green; // CString R 값 출력
				m_greenresult += "\r\n"; // 한 줄 바꿈
				i1++;
			}
		}
		else if (m_filter > 1)
		{
			while (i1 < 1651 - filter)
			{
				m_green.Format(_T("%.2f"), Grgb_byte[i1]); // 배열의 double을 CString으로 바꿔서 저장
				m_greenresult += m_green; // CString R 값 출력
				m_greenresult += "\r\n"; // 한 줄 바꿈
				i1++;
			}
		}
		i1 = 0;
		while (i1 < m_realY2 - m_realY1)
		{
			// BLUE
			int i4 = 0;
			if (m_extend == 0)
			{
				COLORREF brgb = GetPixel(dc, m_realX1, m_realY1 + i1); // 해당 위치의 RGB값을 얻는 함수
				b = GetBValue(brgb);
			}
			else if (m_extend > 0)
			{
				while (i4 < n_m_extend)
				{
					if (i4 == 0)
					{
						COLORREF brgb = GetPixel(dc, m_realX1, m_realY1 + i1); // 해당 위치의 RGB값을 얻는 함수
						b += GetBValue(brgb);
						i4++;
					}
					else if (i4 > 0)
					{
						COLORREF brgb = GetPixel(dc, m_realX1 + i4, m_realY1 + i1); // 해당 위치의 RGB값을 얻는 함수
						b += GetBValue(brgb);
						brgb = GetPixel(dc, m_realX1 - i4, m_realY1 + i1); // 해당 위치의 RGB값을 얻는 함수
						b += GetBValue(brgb);
						i4++;
					}
				}
			}
			if (check_260 == TRUE)
			{
				if (bluegain == 0)
				{
					if (m_extend == 0)
					{
						Brgb_byte[i1] = 260 - b;
					}
					else if (m_extend > 0)
					{
						Brgb_byte[i1] = 260 - (b / (m_extend * 2)); // 배열에 저장
					}
				}
				else if (bluegain != 0)
				{
					if (m_extend == 0)
					{
						Brgb_byte[i1] = (260 - b) * bluegain;
					}
					else if (m_extend > 0)
					{
						Brgb_byte[i1] = (260 - (b / (m_extend * 2))) * bluegain; // 배열에 저장
					}
				}
			}
			else if (check_260 == FALSE)
			{
				if (bluegain == 0)
				{
					if (m_extend == 0)
					{
						Brgb_byte[i1] = b;
					}
					else if (m_extend > 0)
					{
						Brgb_byte[i1] = b / (m_extend * 2); // 배열에 저장
					}
				}
				else if (bluegain != 0)
				{
					if (m_extend == 0)
					{
						Brgb_byte[i1] = b * bluegain;
					}
					else if (m_extend > 0)
					{
						Brgb_byte[i1] = (b / (m_extend * 2)) * bluegain; // 배열에 저장
					}
				}
			}
			blue[i1] = b;
			i1++;
			b = 0;
		}
		i1 = 0;
		if (m_filter > 1)
		{
			int i0 = 0;
			while (i0 < m_realY2 - m_realY1)
			{
				int i = 0;
				double sum = 0;
				while (i < m_filter)
				{
					sum += Brgb_byte[((m_filter + i0) - 1) - i];
					i++;
				}
				Brgb_byte[i0] = sum / (double)m_filter;
				i0++;
			}
			i0 = 0;
		}
		if (m_filter == 1)
		{
			while (i1 < 165)
			{
				m_blue.Format(_T("%.2f"), Brgb_byte[i1]); // 배열의 double을 CString으로 바꿔서 저장
				m_blueresult += m_blue; // CString R 값 출력
				m_blueresult += "\r\n"; // 한 줄 바꿈
				i1++;
			}
		}
		else if (m_filter > 1)
		{
			while (i1 < 165 - filter)
			{
				m_blue.Format(_T("%.2f"), Brgb_byte[i1]); // 배열의 double을 CString으로 바꿔서 저장
				m_blueresult += m_blue; // CString R 값 출력
				m_blueresult += "\r\n"; // 한 줄 바꿈
				i1++;
			}
		}
		// GRAY
		i1 = 0;
		while (i1 < m_realY2 - m_realY1)
		{
			gray = (red[i1] + blue[i1] + green[i1]) / 3; // 얻은 RGB값에서 R 값만 얻어 저장
			if (check_260 == TRUE)
			{
				if (graygain == 0)
				{
					if (m_extend == 0)
					{
						rgb_byte[i1] = 260 - gray;
					}
					else if (m_extend > 0)
					{
						rgb_byte[i1] = 260 - (gray / (m_extend * 2)); // 배열에 저장
					}
				}
				else if (graygain != 0)
				{
					if (m_extend == 0)
					{
						rgb_byte[i1] = (260 - gray) * graygain;
					}
					else if (m_extend > 0)
					{
						rgb_byte[i1] = (260 - (gray / (m_extend * 2))) * graygain; // 배열에 저장
					}
				}
			}
			else if (check_260 == FALSE)
			{
				if (graygain == 0)
				{
					if (m_extend == 0)
					{
						rgb_byte[i1] = gray;
					}
					else if (m_extend > 0)
					{
						rgb_byte[i1] = gray / (m_extend * 2); // 배열에 저장
					}
				}
				else if (graygain != 0)
				{
					if (m_extend == 0)
					{
						rgb_byte[i1] = gray * graygain;
					}
					else if (m_extend > 0)
					{
						rgb_byte[i1] = (gray / (m_extend * 2)) * graygain; // 배열에 저장
					}
				}
			}
			i1++;
		}
		i1 = 0;
		if (m_filter > 1)
		{
			int i0 = 0;
			while (i0 < m_realY2 - m_realY1)
			{
				int i = 0;
				double sum = 0;
				while (i < m_filter)
				{
					sum += rgb_byte[((m_filter + i0) - 1) - i];
					i++;
				}
				rgb_byte[i0] = sum / (double)m_filter;
				if (check_260 == TRUE)
				{
					m_grayvalu[i0] = rgb_byte[i0];
				}
				i0++;
			}
			i0 = 0;
		}
		if (m_filter == 1)
		{
			while (i1 < 165)
			{
				m_gray.Format(_T("%.2f"), rgb_byte[i1]); // 배열의 double을 CString으로 바꿔서 저장
				m_grayresult += m_gray; // CString R 값 출력
				m_grayresult += "\r\n"; // 한 줄 바꿈
				i1++;
			}
		}
		else if (m_filter > 1)
		{
			while (i1 < 165 - filter)
			{
				m_gray.Format(_T("%.2f"), rgb_byte[i1]); // 배열의 double을 CString으로 바꿔서 저장
				m_grayresult += m_gray; // CString R 값 출력
				m_grayresult += "\r\n"; // 한 줄 바꿈
				i1++;
			}
		}
	} ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	else if (avg_check == FALSE)
	{
		while (i1 < m_realY2 - m_realY1) // y2 - y1 만큼 값을 얻기 위한 반복문
		{
			// RED
			int i2 = 0;
			if (m_extend == 0)
			{
				COLORREF rrgb = GetPixel(dc, m_realX1, m_realY1 + i1); // 해당 위치의 RGB값을 얻는 함수
				r = GetRValue(rrgb);
			}
			else if (m_extend > 0)
			{
				while (i2 < n_m_extend)
				{
					if (i2 == 0)
					{
						COLORREF rrgb = GetPixel(dc, m_realX1, m_realY1 + i1); // 해당 위치의 RGB값을 얻는 함수
						r += GetRValue(rrgb);
						i2++;
					}
					else if (i2 > 0)
					{
						COLORREF rrgb = GetPixel(dc, m_realX1 + i2, m_realY1 + i1); // 해당 위치의 RGB값을 얻는 함수
						r += GetRValue(rrgb);
						rrgb = GetPixel(dc, m_realX1 - i2, m_realY1 + i1); // 해당 위치의 RGB값을 얻는 함수
						r += GetRValue(rrgb);
						i2++;
					}
				}
			}
			if (m_redgain == 0)
			{
				Rrgb_byte[i1] = r;
			}
			else if (m_redgain != 0)
			{
				Rrgb_byte[i1] = r * m_redgain;
			}
			red[i1] = r;
			i1++;
			r = 0;
		}
		i1 = 0;
		if (m_filter > 1)
		{
			int i0 = 0;
			while (i0 < m_realY2 - m_realY1)
			{
				int i = 0;
				double sum = 0;
				while (i < m_filter)
				{
					sum += Rrgb_byte[((m_filter + i0) - 1) - i];
					i++;
				}
				Rrgb_byte[i0] = sum / (double)m_filter;
				i0++;
			}
			i0 = 0;
		}
		if (m_filter == 1)
		{
			while ((i1 < 165))
			{
				m_red.Format(_T("%.2f"), Rrgb_byte[i1]); // 배열의 double을 CString으로 바꿔서 저장
				m_redresult += m_red; // CString R 값 출력
				m_redresult += "\r\n"; // 한 줄 바꿈
				i1++;
			}
		}
		else if (m_filter > 1)
		{
			while (i1 < 165 - filter)
			{
				m_red.Format(_T("%.2f"), Rrgb_byte[i1]); // 배열의 double을 CString으로 바꿔서 저장
				m_redresult += m_red; // CString R 값 출력
				m_redresult += "\r\n"; // 한 줄 바꿈
				i1++;
			}
		}
		i1 = 0;
		while (i1 < m_realY2 - m_realY1)
		{
			// GREEN
			int i3 = 0;
			if (m_extend == 0)
			{
				COLORREF grgb = GetPixel(dc, m_realX1, m_realY1 + i1); // 해당 위치의 RGB값을 얻는 함수
				g = GetGValue(grgb);
			}
			else if (m_extend > 0)
			{
				while (i3 < n_m_extend)
				{
					if (i3 == 0)
					{
						COLORREF grgb = GetPixel(dc, m_realX1, m_realY1 + i1); // 해당 위치의 RGB값을 얻는 함수
						g += GetGValue(grgb);
						i3++;
					}
					else if (i3 > 0)
					{
						COLORREF grgb = GetPixel(dc, m_realX1 + i3, m_realY1 + i1); // 해당 위치의 RGB값을 얻는 함수
						g += GetGValue(grgb);
						grgb = GetPixel(dc, m_realX1 - i3, m_realY1 + i1); // 해당 위치의 RGB값을 얻는 함수
						g += GetGValue(grgb);
						i3++;
					}
				}
			}
			if (greengain == 0)
			{
				Grgb_byte[i1] = g;
			}
			else if (greengain != 0)
			{
				Grgb_byte[i1] = g * greengain;
			}
			green[i1] = g;
			i1++;
			g = 0;
		}
		i1 = 0;
		if (m_filter > 1)
		{
			int i0 = 0;
			while (i0 < m_realY2 - m_realY1)
			{
				int i = 0;
				double sum = 0;
				while (i < m_filter)
				{
					sum += Grgb_byte[((m_filter + i0) - 1) - i];
					i++;
				}
				Grgb_byte[i0] = sum / (double)m_filter;
				i0++;
			}
			i0 = 0;
		}
		if (m_filter == 1)
		{
			while (i1 < 165)
			{
				m_green.Format(_T("%.2f"), Grgb_byte[i1]); // 배열의 double을 CString으로 바꿔서 저장
				m_greenresult += m_green; // CString R 값 출력
				m_greenresult += "\r\n"; // 한 줄 바꿈
				i1++;
			}
		}
		else if (m_filter > 1)
		{
			while (i1 < 165 - filter)
			{
				m_green.Format(_T("%.2f"), Grgb_byte[i1]); // 배열의 double을 CString으로 바꿔서 저장
				m_greenresult += m_green; // CString R 값 출력
				m_greenresult += "\r\n"; // 한 줄 바꿈
				i1++;
			}
		}
		i1 = 0;
		while (i1 < m_realY2 - m_realY1)
		{
			// BLUE
			int i4 = 0;
			if (m_extend == 0)
			{
				COLORREF brgb = GetPixel(dc, m_realX1, m_realY1 + i1); // 해당 위치의 RGB값을 얻는 함수
				b = GetBValue(brgb);
			}
			else if (m_extend > 0)
			{
				while (i4 < n_m_extend)
				{
					if (i4 == 0)
					{
						COLORREF brgb = GetPixel(dc, m_realX1, m_realY1 + i1); // 해당 위치의 RGB값을 얻는 함수
						b += GetBValue(brgb);
						i4++;
					}
					else if (i4 > 0)
					{
						COLORREF brgb = GetPixel(dc, m_realX1 + i4, m_realY1 + i1); // 해당 위치의 RGB값을 얻는 함수
						b += GetBValue(brgb);
						brgb = GetPixel(dc, m_realX1 - i4, m_realY1 + i1); // 해당 위치의 RGB값을 얻는 함수
						b += GetBValue(brgb);
						i4++;
					}
				}
			}
			if (bluegain == 0)
			{
				Brgb_byte[i1] = b;
			}
			else if (bluegain != 0)
			{
				Brgb_byte[i1] = b * bluegain;
			}
			blue[i1] = b;
			i1++;
			b = 0;
		}
		i1 = 0;
		if (m_filter > 1)
		{
			int i0 = 0;
			while (i0 < m_realY2 - m_realY1)
			{
				int i = 0;
				double sum = 0;
				while (i < m_filter)
				{
					sum += Brgb_byte[((m_filter + i0) - 1) - i];
					i++;
				}
				Brgb_byte[i0] = sum / (double)m_filter;
				i0++;
			}
			i0 = 0;
		}
		if (m_filter == 1)
		{
			while (i1 < 165)
			{
				m_blue.Format(_T("%.2f"), Brgb_byte[i1]); // 배열의 double을 CString으로 바꿔서 저장
				m_blueresult += m_blue; // CString R 값 출력
				m_blueresult += "\r\n"; // 한 줄 바꿈
				i1++;
			}
		}
		else if (m_filter > 1)
		{
			while (i1 < 165 - filter)
			{
				m_blue.Format(_T("%.2f"), Brgb_byte[i1]); // 배열의 double을 CString으로 바꿔서 저장
				m_blueresult += m_blue; // CString R 값 출력
				m_blueresult += "\r\n"; // 한 줄 바꿈
				i1++;
			}
		}
		// GRAY
		i1 = 0;
		while (i1 < m_realY2 - m_realY1)
		{
			gray = (red[i1] + blue[i1] + green[i1]) / 3; // 얻은 RGB값에서 R 값만 얻어 저장
			if (graygain == 0)
			{
				rgb_byte[i1] = gray;
			}
			else if (graygain != 0)
			{
				rgb_byte[i1] = gray * graygain;
			}
			i1++;
		}
		i1 = 0;
		if (m_filter > 1)
		{
			int i0 = 0;
			while (i0 < m_realY2 - m_realY1)
			{
				int i = 0;
				double sum = 0;
				while (i < m_filter)
				{
					sum += rgb_byte[((m_filter + i0) - 1) - i];
					i++;
				}
				rgb_byte[i0] = sum / (double)m_filter;
				i0++;
			}
			i0 = 0;
		}
		if (m_filter == 1)
		{
			while (i1 < 165)
			{
				m_gray.Format(_T("%.2f"), rgb_byte[i1]); // 배열의 double을 CString으로 바꿔서 저장
				m_grayresult += m_gray; // CString R 값 출력
				m_grayresult += "\r\n"; // 한 줄 바꿈
				i1++;
			}
		}
		else if (m_filter > 1)
		{
			while (i1 < 165 - filter)
			{
				m_gray.Format(_T("%.2f"), rgb_byte[i1]); // 배열의 double을 CString으로 바꿔서 저장
				m_grayresult += m_gray; // CString R 값 출력
				m_grayresult += "\r\n"; // 한 줄 바꿈
				i1++;
			}
		}
	}

	CClientDC line(this); // MFC의 dc 값 얻어오기
	CClientDC Lline(this); // MFC의 dc 값 얻어오기
	CClientDC Rline(this); // MFC의 dc 값 얻어오기

	CPen pen;
	pen.CreatePen(PS_SOLID, 1, RGB(255, 255, 255));
	CPen Lpen;
	Lpen.CreatePen(PS_SOLID, 1, RGB(255, 255, 255));
	CPen Rpen;
	Rpen.CreatePen(PS_SOLID, 1, RGB(255, 255, 255));

	CPen* oldPen = line.SelectObject(&pen);
	CPen* LoldPen = Lline.SelectObject(&Lpen);
	CPen* RoldPen = Rline.SelectObject(&Rpen);

	// Extend 만큼 간격으로 선 세개 그리기
	line.MoveTo(m_realX1, m_realY1);
	line.LineTo(m_realX1, m_realY2);
	int m_leftX1 = m_realX1 - m_extend;
	Lline.MoveTo(m_leftX1, m_realY1);
	Lline.LineTo(m_leftX1, m_realY2);
	int m_rightX1 = m_realX1 + m_extend;
	Rline.MoveTo(m_rightX1, m_realY1);
	Rline.LineTo(m_rightX1, m_realY2);
	line.SelectObject(oldPen);
	Lline.SelectObject(LoldPen);
	Rline.SelectObject(RoldPen);

	pen.DeleteObject();
	CDialogEx::OnPaint();

	UpdateData(FALSE); // 프로그램 상 변수 값이 대화상자에 입력
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void CMFCApplication3Dlg::OnBnClickedButtonroad()
{
// Go와 같은 동작
	UpdateData(TRUE); // 대화상자에 입력한 값을 프로그램 상의 변수에 대입
	m_redresult = "\n";
	m_greenresult = "\n";
	m_blueresult = "\n";
	m_grayresult = "\n";
	int filter = (m_filter * 2) - 2;
	int n_m_extend = m_extend + 1;
	// x는 고정, y2 - y1만큼 한줄의 RED 값 불러와 출력하기
	CClientDC dc(this); // MFC의 dc 값 얻어오
	int m_realX1 = m_x1 + 18; // Picture Control 좌표에 맞춤
	int m_realY1 = m_y1 + 54; // Picture Control 좌표에 맞춤
	int m_realX2 = m_x2 + 18; // Picture Control 좌표에 맞춤
	int m_realY2 = m_y2 + 54; // Picture Control 좌표에 맞춤2

	double r = 0; // RGB에서 얻은 r 값 저장할 변수
	double Rrgb_byte[200] = {}; // 한 줄의 r 값을 저장할 배열
	double red[200] = {};
	CString m_red; // rgb_byte double -> CString 값 저장할 변수

	double g = 0; // RGB에서 얻은 r 값 저장할 변수
	double Grgb_byte[200] = {}; // 한 줄의 r 값을 저장할 배열
	double green[200] = {};
	CString m_green; // rgb_byte double -> CString 값 저장할 변수

	double b = 0; // RGB에서 얻은 r 값 저장할 변수
	double Brgb_byte[200] = {}; // 한 줄의 r 값을 저장할 배열
	double blue[200] = {};
	CString m_blue; // rgb_byte double -> CString 값 저장할 변수

	double gray = 0; // RGB에서 얻은 r 값 저장할 변수
	double rgb_byte[200] = {}; // 한 줄의 r 값을 저장할 배열
	CString m_gray; // rgb_byte double -> CString 값 저장할 변수

	int i1 = 0;

	if (avg_check == TRUE)
	{
		while (i1 < m_realY2 - m_realY1) // y2 - y1 만큼 값을 얻기 위한 반복문
		{
			// RED
			int i2 = 0;
			if (m_extend == 0)
			{
				COLORREF rrgb = GetPixel(dc, m_realX1, m_realY1 + i1); // 해당 위치의 RGB값을 얻는 함수
				r = GetRValue(rrgb);
			}
			else if (m_extend > 0)
			{
				while (i2 < n_m_extend)
				{
					if (i2 == 0)
					{
						COLORREF rrgb = GetPixel(dc, m_realX1, m_realY1 + i1); // 해당 위치의 RGB값을 얻는 함수
						r += GetRValue(rrgb);
						i2++;
					}
					else if (i2 > 0)
					{
						COLORREF rrgb = GetPixel(dc, m_realX1 + i2, m_realY1 + i1); // 해당 위치의 RGB값을 얻는 함수
						r += GetRValue(rrgb);
						rrgb = GetPixel(dc, m_realX1 - i2, m_realY1 + i1); // 해당 위치의 RGB값을 얻는 함수
						r += GetRValue(rrgb);
						i2++;
					}
				}
			}
			if (check_260 == TRUE)
			{
				if (m_redgain == 0)
				{
					if (m_extend == 0)
					{
						Rrgb_byte[i1] = 260 - r;
					}
					else if (m_extend > 0)
					{
						Rrgb_byte[i1] = 260 - (r / (m_extend * 2)); // 배열에 저
					}
				}
				else if (m_redgain != 0)
				{
					if (m_extend == 0)
					{
						Rrgb_byte[i1] = (260 - r) * m_redgain;
					}
					else if (m_extend > 0)
					{
						Rrgb_byte[i1] = (260 - (r / (m_extend * 2))) * m_redgain; // 배열에 저
					}
				}
			}
			else if (check_260 == FALSE)
			{
				if (m_redgain == 0)
				{
					if (m_extend == 0)
					{
						Rrgb_byte[i1] = r;
					}
					else if (m_extend > 0)
					{
						Rrgb_byte[i1] = r / (m_extend * 2); // 배열에 저
					}
				}
				else if (m_redgain != 0)
				{
					if (m_extend == 0)
					{
						Rrgb_byte[i1] = r * m_redgain;
					}
					else if (m_extend > 0)
					{
						Rrgb_byte[i1] = (r / (m_extend * 2)) * m_redgain; // 배열에 저
					}
				}
			}
			red[i1] = r;
			i1++;
			r = 0;
		}
		i1 = 0;
		if (m_filter > 1)
		{
			int i0 = 0;
			while (i0 < m_realY2 - m_realY1)
			{
				int i = 0;
				double sum = 0;
				while (i < m_filter)
				{
					sum += Rrgb_byte[((m_filter + i0) - 1) - i];
					i++;
				}
				Rrgb_byte[i0] = sum / (double)m_filter;
				i0++;
			}
			i0 = 0;
		}
		if (m_filter == 1)
		{
			while ((i1 < 165))
			{
				m_red.Format(_T("%.2f"), Rrgb_byte[i1]); // 배열의 double을 CString으로 바꿔서 저장
				m_redresult += m_red; // CString R 값 출력
				m_redresult += "\r\n"; // 한 줄 바꿈
				i1++;
			}
		}
		else if (m_filter > 1)
		{
			while (i1 < 165 - filter)
			{
				m_red.Format(_T("%.2f"), Rrgb_byte[i1]); // 배열의 double을 CString으로 바꿔서 저장
				m_redresult += m_red; // CString R 값 출력
				m_redresult += "\r\n"; // 한 줄 바꿈
				i1++;
			}
		}
		i1 = 0;
		while (i1 < m_realY2 - m_realY1)
		{
			// GREEN
			int i3 = 0;
			if (m_extend == 0)
			{
				COLORREF grgb = GetPixel(dc, m_realX1, m_realY1 + i1); // 해당 위치의 RGB값을 얻는 함수
				g = GetGValue(grgb);
			}
			else if (m_extend > 0)
			{
				while (i3 < n_m_extend)
				{
					if (i3 == 0)
					{
						COLORREF grgb = GetPixel(dc, m_realX1, m_realY1 + i1); // 해당 위치의 RGB값을 얻는 함수
						g += GetGValue(grgb);
						i3++;
					}
					else if (i3 > 0)
					{
						COLORREF grgb = GetPixel(dc, m_realX1 + i3, m_realY1 + i1); // 해당 위치의 RGB값을 얻는 함수
						g += GetGValue(grgb);
						grgb = GetPixel(dc, m_realX1 - i3, m_realY1 + i1); // 해당 위치의 RGB값을 얻는 함수
						g += GetGValue(grgb);
						i3++;
					}
				}
			}
			if (check_260 == TRUE)
			{
				if (greengain == 0)
				{
					if (m_extend == 0)
					{
						Grgb_byte[i1] = 260 - g;
					}
					else if (m_extend > 0)
					{
						Grgb_byte[i1] = 260 - (g / (m_extend * 2)); // 배열에 저장
					}
				}
				else if (greengain != 0)
				{
					if (m_extend == 0)
					{
						Grgb_byte[i1] = (260 - g) * greengain;
					}
					else if (m_extend > 0)
					{
						Grgb_byte[i1] = (260 - (g / (m_extend * 2))) * greengain; // 배열에 저장
					}
				}
			}
			else if (check_260 == FALSE)
			{
				if (greengain == 0)
				{
					if (m_extend == 0)
					{
						Grgb_byte[i1] = g;
					}
					else if (m_extend > 0)
					{
						Grgb_byte[i1] = g / (m_extend * 2); // 배열에 저장
					}
				}
				else if (greengain != 0)
				{
					if (m_extend == 0)
					{
						Grgb_byte[i1] = g * greengain;
					}
					else if (m_extend > 0)
					{
						Grgb_byte[i1] = (g / (m_extend * 2)) * greengain; // 배열에 저장
					}
				}
			}
			green[i1] = g;
			i1++;
			g = 0;
		}
		i1 = 0;
		if (m_filter > 1)
		{
			int i0 = 0;
			while (i0 < m_realY2 - m_realY1)
			{
				int i = 0;
				double sum = 0;
				while (i < m_filter)
				{
					sum += Grgb_byte[((m_filter + i0) - 1) - i];
					i++;
				}
				Grgb_byte[i0] = sum / (double)m_filter;
				i0++;
			}
			i0 = 0;
		}
		if (m_filter == 1)
		{
			while (i1 < 165)
			{
				m_green.Format(_T("%.2f"), Grgb_byte[i1]); // 배열의 double을 CString으로 바꿔서 저장
				m_greenresult += m_green; // CString R 값 출력
				m_greenresult += "\r\n"; // 한 줄 바꿈
				i1++;
			}
		}
		else if (m_filter > 1)
		{
			while (i1 < 165 - filter)
			{
				m_green.Format(_T("%.2f"), Grgb_byte[i1]); // 배열의 double을 CString으로 바꿔서 저장
				m_greenresult += m_green; // CString R 값 출력
				m_greenresult += "\r\n"; // 한 줄 바꿈
				i1++;
			}
		}
		i1 = 0;
		while (i1 < m_realY2 - m_realY1)
		{
			// BLUE
			int i4 = 0;
			if (m_extend == 0)
			{
				COLORREF brgb = GetPixel(dc, m_realX1, m_realY1 + i1); // 해당 위치의 RGB값을 얻는 함수
				b = GetBValue(brgb);
			}
			else if (m_extend > 0)
			{
				while (i4 < n_m_extend)
				{
					if (i4 == 0)
					{
						COLORREF brgb = GetPixel(dc, m_realX1, m_realY1 + i1); // 해당 위치의 RGB값을 얻는 함수
						b += GetBValue(brgb);
						i4++;
					}
					else if (i4 > 0)
					{
						COLORREF brgb = GetPixel(dc, m_realX1 + i4, m_realY1 + i1); // 해당 위치의 RGB값을 얻는 함수
						b += GetBValue(brgb);
						brgb = GetPixel(dc, m_realX1 - i4, m_realY1 + i1); // 해당 위치의 RGB값을 얻는 함수
						b += GetBValue(brgb);
						i4++;
					}
				}
			}
			if (check_260 == TRUE)
			{
				if (bluegain == 0)
				{
					if (m_extend == 0)
					{
						Brgb_byte[i1] = 260 - b;
					}
					else if (m_extend > 0)
					{
						Brgb_byte[i1] = 260 - (b / (m_extend * 2)); // 배열에 저장
					}
				}
				else if (bluegain != 0)
				{
					if (m_extend == 0)
					{
						Brgb_byte[i1] = (260 - b) * bluegain;
					}
					else if (m_extend > 0)
					{
						Brgb_byte[i1] = (260 - (b / (m_extend * 2))) * bluegain; // 배열에 저장
					}
				}
			}
			else if (check_260 == FALSE)
			{
				if (bluegain == 0)
				{
					if (m_extend == 0)
					{
						Brgb_byte[i1] = b;
					}
					else if (m_extend > 0)
					{
						Brgb_byte[i1] = b / (m_extend * 2); // 배열에 저장
					}
				}
				else if (bluegain != 0)
				{
					if (m_extend == 0)
					{
						Brgb_byte[i1] = b * bluegain;
					}
					else if (m_extend > 0)
					{
						Brgb_byte[i1] = (b / (m_extend * 2)) * bluegain; // 배열에 저장
					}
				}
			}
			blue[i1] = b;
			i1++;
			b = 0;
		}
		i1 = 0;
		if (m_filter > 1)
		{
			int i0 = 0;
			while (i0 < m_realY2 - m_realY1)
			{
				int i = 0;
				double sum = 0;
				while (i < m_filter)
				{
					sum += Brgb_byte[((m_filter + i0) - 1) - i];
					i++;
				}
				Brgb_byte[i0] = sum / (double)m_filter;
				i0++;
			}
			i0 = 0;
		}
		if (m_filter == 1)
		{
			while (i1 < 165)
			{
				m_blue.Format(_T("%.2f"), Brgb_byte[i1]); // 배열의 double을 CString으로 바꿔서 저장
				m_blueresult += m_blue; // CString R 값 출력
				m_blueresult += "\r\n"; // 한 줄 바꿈
				i1++;
			}
		}
		else if (m_filter > 1)
		{
			while (i1 < 165 - filter)
			{
				m_blue.Format(_T("%.2f"), Brgb_byte[i1]); // 배열의 double을 CString으로 바꿔서 저장
				m_blueresult += m_blue; // CString R 값 출력
				m_blueresult += "\r\n"; // 한 줄 바꿈
				i1++;
			}
		}
		// GRAY
		i1 = 0;
		while (i1 < m_realY2 - m_realY1)
		{
			gray = (red[i1] + blue[i1] + green[i1]) / 3; // 얻은 RGB값에서 R 값만 얻어 저장
			if (check_260 == TRUE)
			{
				if (graygain == 0)
				{
					if (m_extend == 0)
					{
						rgb_byte[i1] = 260 - gray;
					}
					else if (m_extend > 0)
					{
						rgb_byte[i1] = 260 - (gray / (m_extend * 2)); // 배열에 저장
					}
				}
				else if (graygain != 0)
				{
					if (m_extend == 0)
					{
						rgb_byte[i1] = (260 - gray) * graygain;
					}
					else if (m_extend > 0)
					{
						rgb_byte[i1] = (260 - (gray / (m_extend * 2))) * graygain; // 배열에 저장
					}
				}
			}
			else if (check_260 == FALSE)
			{
				if (graygain == 0)
				{
					if (m_extend == 0)
					{
						rgb_byte[i1] = gray;
					}
					else if (m_extend > 0)
					{
						rgb_byte[i1] = gray / (m_extend * 2); // 배열에 저장
					}
				}
				else if (graygain != 0)
				{
					if (m_extend == 0)
					{
						rgb_byte[i1] = gray * graygain;
					}
					else if (m_extend > 0)
					{
						rgb_byte[i1] = (gray / (m_extend * 2)) * graygain; // 배열에 저장
					}
				}
			}
			i1++;
		}
		i1 = 0;
		if (m_filter > 1)
		{
			int i0 = 0;
			while (i0 < m_realY2 - m_realY1)
			{
				int i = 0;
				double sum = 0;
				while (i < m_filter)
				{
					sum += rgb_byte[((m_filter + i0) - 1) - i];
					i++;
				}
				rgb_byte[i0] = sum / (double)m_filter;
				if (check_260 == TRUE)
				{
					m_grayvalu[i0] = rgb_byte[i0];
				}
				i0++;
			}
			i0 = 0;
		}
		if (m_filter == 1)
		{
			while (i1 < 165)
			{
				m_gray.Format(_T("%.2f"), rgb_byte[i1]); // 배열의 double을 CString으로 바꿔서 저장
				m_grayresult += m_gray; // CString R 값 출력
				m_grayresult += "\r\n"; // 한 줄 바꿈
				i1++;
			}
		}
		else if (m_filter > 1)
		{
			while (i1 < 165 - filter)
			{
				m_gray.Format(_T("%.2f"), rgb_byte[i1]); // 배열의 double을 CString으로 바꿔서 저장
				m_grayresult += m_gray; // CString R 값 출력
				m_grayresult += "\r\n"; // 한 줄 바꿈
				i1++;
			}
		}
	} ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	else if (avg_check == FALSE)
	{
		while (i1 < m_realY2 - m_realY1) // y2 - y1 만큼 값을 얻기 위한 반복문
		{
			// RED
			int i2 = 0;
			if (m_extend == 0)
			{
				COLORREF rrgb = GetPixel(dc, m_realX1, m_realY1 + i1); // 해당 위치의 RGB값을 얻는 함수
				r = GetRValue(rrgb);
			}
			else if (m_extend > 0)
			{
				while (i2 < n_m_extend)
				{
					if (i2 == 0)
					{
						COLORREF rrgb = GetPixel(dc, m_realX1, m_realY1 + i1); // 해당 위치의 RGB값을 얻는 함수
						r += GetRValue(rrgb);
						i2++;
					}
					else if (i2 > 0)
					{
						COLORREF rrgb = GetPixel(dc, m_realX1 + i2, m_realY1 + i1); // 해당 위치의 RGB값을 얻는 함수
						r += GetRValue(rrgb);
						rrgb = GetPixel(dc, m_realX1 - i2, m_realY1 + i1); // 해당 위치의 RGB값을 얻는 함수
						r += GetRValue(rrgb);
						i2++;
					}
				}
			}
			if (m_redgain == 0)
			{
				Rrgb_byte[i1] = r;
			}
			else if (m_redgain != 0)
			{
				Rrgb_byte[i1] = r * m_redgain;
			}
			red[i1] = r;
			i1++;
			r = 0;
		}
		i1 = 0;
		if (m_filter > 1)
		{
			int i0 = 0;
			while (i0 < m_realY2 - m_realY1)
			{
				int i = 0;
				double sum = 0;
				while (i < m_filter)
				{
					sum += Rrgb_byte[((m_filter + i0) - 1) - i];
					i++;
				}
				Rrgb_byte[i0] = sum / (double)m_filter;
				i0++;
			}
			i0 = 0;
		}
		if (m_filter == 1)
		{
			while ((i1 < 165))
			{
				m_red.Format(_T("%.2f"), Rrgb_byte[i1]); // 배열의 double을 CString으로 바꿔서 저장
				m_redresult += m_red; // CString R 값 출력
				m_redresult += "\r\n"; // 한 줄 바꿈
				i1++;
			}
		}
		else if (m_filter > 1)
		{
			while (i1 < 165 - filter)
			{
				m_red.Format(_T("%.2f"), Rrgb_byte[i1]); // 배열의 double을 CString으로 바꿔서 저장
				m_redresult += m_red; // CString R 값 출력
				m_redresult += "\r\n"; // 한 줄 바꿈
				i1++;
			}
		}
		i1 = 0;
		while (i1 < m_realY2 - m_realY1)
		{
			// GREEN
			int i3 = 0;
			if (m_extend == 0)
			{
				COLORREF grgb = GetPixel(dc, m_realX1, m_realY1 + i1); // 해당 위치의 RGB값을 얻는 함수
				g = GetGValue(grgb);
			}
			else if (m_extend > 0)
			{
				while (i3 < n_m_extend)
				{
					if (i3 == 0)
					{
						COLORREF grgb = GetPixel(dc, m_realX1, m_realY1 + i1); // 해당 위치의 RGB값을 얻는 함수
						g += GetGValue(grgb);
						i3++;
					}
					else if (i3 > 0)
					{
						COLORREF grgb = GetPixel(dc, m_realX1 + i3, m_realY1 + i1); // 해당 위치의 RGB값을 얻는 함수
						g += GetGValue(grgb);
						grgb = GetPixel(dc, m_realX1 - i3, m_realY1 + i1); // 해당 위치의 RGB값을 얻는 함수
						g += GetGValue(grgb);
						i3++;
					}
				}
			}
			if (greengain == 0)
			{
				Grgb_byte[i1] = g;
			}
			else if (greengain != 0)
			{
				Grgb_byte[i1] = g * greengain;
			}
			green[i1] = g;
			i1++;
			g = 0;
		}
		i1 = 0;
		if (m_filter > 1)
		{
			int i0 = 0;
			while (i0 < m_realY2 - m_realY1)
			{
				int i = 0;
				double sum = 0;
				while (i < m_filter)
				{
					sum += Grgb_byte[((m_filter + i0) - 1) - i];
					i++;
				}
				Grgb_byte[i0] = sum / (double)m_filter;
				i0++;
			}
			i0 = 0;
		}
		if (m_filter == 1)
		{
			while (i1 < 165)
			{
				m_green.Format(_T("%.2f"), Grgb_byte[i1]); // 배열의 double을 CString으로 바꿔서 저장
				m_greenresult += m_green; // CString R 값 출력
				m_greenresult += "\r\n"; // 한 줄 바꿈
				i1++;
			}
		}
		else if (m_filter > 1)
		{
			while (i1 < 165 - filter)
			{
				m_green.Format(_T("%.2f"), Grgb_byte[i1]); // 배열의 double을 CString으로 바꿔서 저장
				m_greenresult += m_green; // CString R 값 출력
				m_greenresult += "\r\n"; // 한 줄 바꿈
				i1++;
			}
		}
		i1 = 0;
		while (i1 < m_realY2 - m_realY1)
		{
			// BLUE
			int i4 = 0;
			if (m_extend == 0)
			{
				COLORREF brgb = GetPixel(dc, m_realX1, m_realY1 + i1); // 해당 위치의 RGB값을 얻는 함수
				b = GetBValue(brgb);
			}
			else if (m_extend > 0)
			{
				while (i4 < n_m_extend)
				{
					if (i4 == 0)
					{
						COLORREF brgb = GetPixel(dc, m_realX1, m_realY1 + i1); // 해당 위치의 RGB값을 얻는 함수
						b += GetBValue(brgb);
						i4++;
					}
					else if (i4 > 0)
					{
						COLORREF brgb = GetPixel(dc, m_realX1 + i4, m_realY1 + i1); // 해당 위치의 RGB값을 얻는 함수
						b += GetBValue(brgb);
						brgb = GetPixel(dc, m_realX1 - i4, m_realY1 + i1); // 해당 위치의 RGB값을 얻는 함수
						b += GetBValue(brgb);
						i4++;
					}
				}
			}
			if (bluegain == 0)
			{
				Brgb_byte[i1] = b;
			}
			else if (bluegain != 0)
			{
				Brgb_byte[i1] = b * bluegain;
			}
			blue[i1] = b;
			i1++;
			b = 0;
		}
		i1 = 0;
		if (m_filter > 1)
		{
			int i0 = 0;
			while (i0 < m_realY2 - m_realY1)
			{
				int i = 0;
				double sum = 0;
				while (i < m_filter)
				{
					sum += Brgb_byte[((m_filter + i0) - 1) - i];
					i++;
				}
				Brgb_byte[i0] = sum / (double)m_filter;
				i0++;
			}
			i0 = 0;
		}
		if (m_filter == 1)
		{
			while (i1 < 165)
			{
				m_blue.Format(_T("%.2f"), Brgb_byte[i1]); // 배열의 double을 CString으로 바꿔서 저장
				m_blueresult += m_blue; // CString R 값 출력
				m_blueresult += "\r\n"; // 한 줄 바꿈
				i1++;
			}
		}
		else if (m_filter > 1)
		{
			while (i1 < 165 - filter)
			{
				m_blue.Format(_T("%.2f"), Brgb_byte[i1]); // 배열의 double을 CString으로 바꿔서 저장
				m_blueresult += m_blue; // CString R 값 출력
				m_blueresult += "\r\n"; // 한 줄 바꿈
				i1++;
			}
		}
		// GRAY
		i1 = 0;
		while (i1 < m_realY2 - m_realY1)
		{
			gray = (red[i1] + blue[i1] + green[i1]) / 3; // 얻은 RGB값에서 R 값만 얻어 저장
			if (graygain == 0)
			{
				rgb_byte[i1] = gray;
			}
			else if (graygain != 0)
			{
				rgb_byte[i1] = gray * graygain;
			}
			i1++;
		}
		i1 = 0;
		if (m_filter > 1)
		{
			int i0 = 0;
			while (i0 < m_realY2 - m_realY1)
			{
				int i = 0;
				double sum = 0;
				while (i < m_filter)
				{
					sum += rgb_byte[((m_filter + i0) - 1) - i];
					i++;
				}
				rgb_byte[i0] = sum / (double)m_filter;
				i0++;
			}
			i0 = 0;
		}
		if (m_filter == 1)
		{
			while (i1 < 165)
			{
				m_gray.Format(_T("%.2f"), rgb_byte[i1]); // 배열의 double을 CString으로 바꿔서 저장
				m_grayresult += m_gray; // CString R 값 출력
				m_grayresult += "\r\n"; // 한 줄 바꿈
				i1++;
			}
		}
		else if (m_filter > 1)
		{
			while (i1 < 165 - filter)
			{
				m_gray.Format(_T("%.2f"), rgb_byte[i1]); // 배열의 double을 CString으로 바꿔서 저장
				m_grayresult += m_gray; // CString R 값 출력
				m_grayresult += "\r\n"; // 한 줄 바꿈
				i1++;
			}
		}
	}
	UpdateData(FALSE);
}


void CMFCApplication3Dlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CDialogEx::OnMouseMove(nFlags, point);
	UpdateData(TRUE);

	int Xresult = point.x - 19;
	int Yresult = point.y - 54;
	// x 좌표
	if (Xresult < 0)
	{
		return;
	}
	else if (Xresult > 381)
	{
		return;
	}
	else
	{
		m_Xresult = Xresult;
	}

	// y 좌표
	if (Yresult < 0)
	{
		return;
	}
	else if (Yresult > 365)
	{
		return;
	}
	else
	{
		m_Yresult = Yresult;
	}

	UpdateData(FALSE);
}


HBRUSH CMFCApplication3Dlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);
	// TODO:  여기서 DC의 특성을 변경합니다.
	UINT nlD = pWnd->GetDlgCtrlID();

	switch (nlD)
	{
	case IDC_EDIT_Xresult:
		pDC->SetBkColor(RGB(0, 0, 0));
		hbr = ::CreateSolidBrush(RGB(237, 237, 237));
		break;
	case IDC_EDIT_Yresult:
		pDC->SetBkColor(RGB(0, 0, 0));
		hbr = ::CreateSolidBrush(RGB(237, 237, 237));
		break;
	case IDC_STATIC_2line:
		pDC->SetBkColor(RGB(255, 255, 225));
		hbr = ::CreateSolidBrush(RGB(255, 255, 255));
		break;
	case IDC_STATIC_3line:
		pDC->SetBkColor(RGB(255, 255, 225));
		hbr = ::CreateSolidBrush(RGB(255, 255, 255));
		break;
	case IDC_STATIC_gain:
		pDC->SetBkColor(RGB(255, 255, 225));
		hbr = ::CreateSolidBrush(RGB(255, 255, 255));
		break;
	case IDC_STATIC_wait:
		pDC->SetBkColor(RGB(255, 150, 150));
		hbr = ::CreateSolidBrush(RGB(255, 150, 150));
		break;
	}
	// TODO:  기본값이 적당하지 않으면 다른 브러시를 반환합니다.
	return hbr;
}

void CMFCApplication3Dlg::OnBnClickedButton2linego()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);

	// Control : (I51:I86)-((I51+I86)*35)/2
	// -> 29 ~ 64 : 4
	// -> 32 ~ 67 : 8
	// -> 33 ~ 68 : 3
	// -> 35 ~ 70 : 1
	// 32 ~ 67 // 간격 : 35

	int ic = 32;
	int cd1 = m_2line_CD1;
	int cd2 = m_2line_CD2;
	double graycontrol = 0;
	double controlresult = 0;

	CString Control = { };

	if (cd1 > 0)
	{
		ic = cd1;

		while (ic < (cd2 + 1))
		{
			graycontrol += m_grayvalu[ic];
			ic++;
		}
		controlresult = graycontrol - (((m_grayvalu[cd1] + m_grayvalu[cd2]) * 35) / 2);

		Control.Format(_T("%.2f"), controlresult); // 배열의 double을 CString으로 바꿔서 저장
		m_2lineControl = Control; // CString R 값 출력

	}
	else if (cd1 == 0)
	{
		while (ic < (67 + 1))
		{
			graycontrol += m_grayvalu[ic];
			ic++;
		}
		controlresult = graycontrol - (((m_grayvalu[32] + m_grayvalu[67]) * 35) / 2);

		Control.Format(_T("%.2f"), controlresult); // 배열의 double을 CString으로 바꿔서 저장
		m_2lineControl = Control; // CString R 값 출력
	}

	// test : (I109:I144)-((I109+I144)*35)/2
	// -> 87 ~ 122 : 4
	// -> 88 ~ 123 : 7
	// -> 91 ~ 126 : 2
	// -> 89 ~ 124 : 3
	// 88 ~ 123 // 간격 : 35


	int it = 88;
	int td1 = m_2line_TD1;
	int td2 = m_2line_TD2;
	double graytest = 0;
	double testresult = 0;
	CString Test = { };

	if (td1 > 0)
	{
		it = td1;

		while (it < (td2 + 1))
		{
			graytest += m_grayvalu[it];
			it++;
		}
		testresult = graytest - (((m_grayvalu[td1] + m_grayvalu[td2]) * 35) / 2);

		Test.Format(_T("%.2f"), testresult); // 배열의 double을 CString으로 바꿔서 저장
		m_2lineTestArea = Test; // CString R 값 출력
	}
	else if (td1 == 0)
	{
		while (it < (123 + 1))
		{
			graytest += m_grayvalu[it];
			it++;
		}
		testresult = graytest - (((m_grayvalu[88] + m_grayvalu[123]) * 35) / 2);
		
		Test.Format(_T("%.2f"), testresult); // 배열의 double을 CString으로 바꿔서 저장
		m_2lineTestArea = Test; // CString R 값 출력
	}

	double ratioresult = 0;
	CString ratio = { };
	// ratio : I20/I19

	ratioresult = testresult / controlresult;

	ratio.Format(_T("%.2f"), ratioresult); // 배열의 double을 CString으로 바꿔서 저장
	m_2lineRatio = ratio; // CString R 값 출력

	UpdateData(FALSE);
}


void CMFCApplication3Dlg::OnBnClickedButton3linego()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);

	// Control : (H29:H64)-((H29+H64)*35)/2
	// -> 5 ~ 40 : 2
	// -> 12 ~ 47 : 2
	// -> 9 ~ 44 : 1
	// -> 13 ~ 48 : 1
	// -> 10 ~ 45 : 3
	// -> 11 ~ 46 : 2
	// -> 6 ~ 41 : 1
	// 10 ~ 45 // 간격 : 35

	int ic = 10;
	int cd1 = m_3line_CD1;
	int cd2 = m_3line_CD2;
	double graycontrol = 0;
	double controlresult = 0;
	CString control = { };

	if (cd1 > 0)
	{
		ic = cd1;

		while (ic < (cd2 + 1))
		{
			graycontrol += m_grayvalu[ic];
			ic++;
		}
		controlresult = graycontrol - (((m_grayvalu[cd1] + m_grayvalu[cd2]) * 35) / 2);

		control.Format(_T("%.2f"), controlresult); // 배열의 double을 CString으로 바꿔서 저장
		m_3lineControl = control; // CString R 값 출력
	}
	else if (cd1 == 0)
	{
		while (ic < (45 + 1))
		{
			graycontrol += m_grayvalu[ic];
			ic++;
		}
		controlresult = graycontrol - (((m_grayvalu[10] + m_grayvalu[45]) * 35) / 2);

		control.Format(_T("%.2f"), controlresult); // 배열의 double을 CString으로 바꿔서 저장
		m_3lineControl = control; // CString R 값 출력
	}

	// test1 : (H85:H120)-((H85+H120)*35)/2
	// -> 61 ~ 96 : 3
	// -> 77 ~ 112 : 3
	// -> 57 ~ 92 : 1
	// -> 53 ~ 88 : 1
	// -> 55 ~ 90 : 3
	// -> 49 ~ 84 : 1
	// 62 ~ 97 // 간격 : 35


	int it1 = 62;
	int t1d1 = m_3line_T1D1;
	int t1d2 = m_3line_T1D2;
	double graytest1 = 0;
	double test1result = 0;
	CString test1 = { };

	if (t1d1 > 0)
	{
		it1 = t1d1;

		while (it1 < (t1d2 + 1))
		{
			graytest1 += m_grayvalu[it1];
			it1++;
		}
		test1result = graytest1 - (((m_grayvalu[t1d1] + m_grayvalu[t1d2]) * 35) / 2);

		test1.Format(_T("%.2f"), test1result); // 배열의 double을 CString으로 바꿔서 저장
		m_3lineTestArea1 = test1; // CString R 값 출력
	}
	else if (t1d1 == 0)
	{
		while (it1 < (97 + 1))
		{
			graytest1 += m_grayvalu[it1];
			it1++;
		}
		test1result = graytest1 - (((m_grayvalu[62] + m_grayvalu[97]) * 35) / 2);

		test1.Format(_T("%.2f"), test1result); // 배열의 double을 CString으로 바꿔서 저장
		m_3lineTestArea1 = test1; // CString R 값 출력
	}

	// test2 : (H128:H163)-((H128+H163)*35)/2
	// -> 104 ~ 139 : 1
	// -> 107 ~ 142 : 1
	// -> 103 ~ 138 : 3
	// -> 108 ~ 143 : 1
	// -> 106 ~ 141 : 2
	// -> 109 ~ 144 : 1
	// -> 102 ~ 137 : 1
	// -> 100 ~ 135 : 2
	// 104 ~ 139 // 간격 : 35

	int it2 = 104;
	int t2d1 = m_3line_T2D1;
	int t2d2 = m_3line_T2D2;
	double graytest2 = 0;
	double test2result = 0;
	CString test2 = { };

	if (t2d1 > 0)
	{
		it2 = t2d1;

		while (it2 < (t2d2 + 1))
		{
			graytest2 += m_grayvalu[it2];
			it2++;
		}
		test2result = graytest2 - (((m_grayvalu[t2d1] + m_grayvalu[t2d2]) * 35) / 2);

		test2.Format(_T("%.2f"), test2result); // 배열의 double을 CString으로 바꿔서 저장
		m_3lineTestArea2 = test2; // CString R 값 출력
	}
	else if (t2d1 == 0)
	{
		while (it2 < (139 + 1))
		{
			graytest2 += m_grayvalu[it2];
			it2++;
		}
		test2result = graytest2 - (((m_grayvalu[104] + m_grayvalu[139]) * 35) / 2);
		
		test2.Format(_T("%.2f"), test2result); // 배열의 double을 CString으로 바꿔서 저장
		m_3lineTestArea2 = test2; // CString R 값 출력
	}

	double ratio1result = 0;
	CString ratio1 = { };
	// ratio : I20/I19

	ratio1result = test1result / controlresult;

	ratio1.Format(_T("%.2f"), ratio1result); // 배열의 double을 CString으로 바꿔서 저장
	m_3lineRatio1 = ratio1; // CString R 값 출력


	double ratio2result = 0;
	CString ratio2 = { };
	// ratio2 : I20/I19
	ratio2result = test2result / controlresult;

	ratio2.Format(_T("%.2f"), ratio2result); // 배열의 double을 CString으로 바꿔서 저장
	m_3lineRatio2 = ratio2; // CString R 값 출력

	UpdateData(FALSE);
}

void CMFCApplication3Dlg::OnBnClickedAvg()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (((CButton*)GetDlgItem(IDC_Avg))->GetCheck())
	{
		avg_check = TRUE;
	}
	else
	{
		avg_check = FALSE;
	}
}


void CMFCApplication3Dlg::OnBnClickedCheck260()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (((CButton*)GetDlgItem(IDC_Avg))->GetCheck())
	{
		check_260 = TRUE;
	}
	else
	{
		check_260 = FALSE;
	}
}

void CMFCApplication3Dlg::OnBnClickedButtonCut()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE); // 대화상자에 입력한 값을 프로그램 상의 변수에 대입
	/*CString redresult;
	GetDlgItemText(IDC_EDIT_redresult, redresult);*/
	int nLength = redresult.GetWindowTextLength();
	redresult.SetSel(0, 1);   // Edit에서 문자열을 선택한다.
	redresult.Clear();
	redresult.SetSel(0, nLength);   // Edit에서 문자열을 선택한다.
	redresult.Copy();
	m_redresult = '\n';
	UpdateData(FALSE); // 대화상자에 입력한 값을 프로그램 상의 변수에 대입
}

void CMFCApplication3Dlg::OnBnClickedButtonCut2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE); // 대화상자에 입력한 값을 프로그램 상의 변수에 대입
	/*CString redresult;
	GetDlgItemText(IDC_EDIT_redresult, redresult);*/
	int nLength = greenresult.GetWindowTextLength();
	greenresult.SetSel(0, 1);   // Edit에서 문자열을 선택한다.
	greenresult.Clear();
	greenresult.SetSel(0, nLength);   // Edit에서 문자열을 선택한다.
	greenresult.Copy();
	m_greenresult = '\n';
	UpdateData(FALSE); // 대화상자에 입력한 값을 프로그램 상의 변수에 대입
}

void CMFCApplication3Dlg::OnBnClickedButtonCut3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE); // 대화상자에 입력한 값을 프로그램 상의 변수에 대입
	/*CString redresult;
	GetDlgItemText(IDC_EDIT_redresult, redresult);*/
	int nLength = blueresult.GetWindowTextLength();
	blueresult.SetSel(0, 1);   // Edit에서 문자열을 선택한다.
	blueresult.Clear();
	blueresult.SetSel(0, nLength);   // Edit에서 문자열을 선택한다.
	blueresult.Copy();
	m_blueresult = '\n';
	UpdateData(FALSE); // 대화상자에 입력한 값을 프로그램 상의 변수에 대입
}

void CMFCApplication3Dlg::OnBnClickedButtonCut4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE); // 대화상자에 입력한 값을 프로그램 상의 변수에 대입
	/*CString redresult;
	GetDlgItemText(IDC_EDIT_redresult, redresult);*/
	int nLength = grayresult.GetWindowTextLength();
	grayresult.SetSel(0, 1);   // Edit에서 문자열을 선택한다.
	grayresult.Clear();
	grayresult.SetSel(0, nLength);   // Edit에서 문자열을 선택한다.
	grayresult.Copy();
	m_grayresult = '\n';
	UpdateData(FALSE); // 대화상자에 입력한 값을 프로그램 상의 변수에 대입
}


void CMFCApplication3Dlg::OnBnClickedButtonClear()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE); // 대화상자에 입력한 값을 프로그램 상의 변수에 대입
	m_redresult = "\n";
	UpdateData(FALSE); // 대화상자에 입력한 값을 프로그램 상의 변수에 대입
}


void CMFCApplication3Dlg::OnBnClickedButtonClear2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE); // 대화상자에 입력한 값을 프로그램 상의 변수에 대입
	m_greenresult = "\n";
	UpdateData(FALSE); // 대화상자에 입력한 값을 프로그램 상의 변수에 대입
}


void CMFCApplication3Dlg::OnBnClickedButtonClear3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE); // 대화상자에 입력한 값을 프로그램 상의 변수에 대입
	m_blueresult = "\n";
	UpdateData(FALSE); // 대화상자에 입력한 값을 프로그램 상의 변수에 대입
}


void CMFCApplication3Dlg::OnBnClickedButtonClear4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE); // 대화상자에 입력한 값을 프로그램 상의 변수에 대입
	m_grayresult = "\n";
	UpdateData(FALSE); // 대화상자에 입력한 값을 프로그램 상의 변수에 대입
}
