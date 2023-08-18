
// MFCApplication3Dlg.h: 헤더 파일
//

#pragma once


// CMFCApplication3Dlg 대화 상자
class CMFCApplication3Dlg : public CDialogEx
{
// 생성입니다.

public:
	CMFCApplication3Dlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION3_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.

#ifdef AFX_DESIGN_TIME
	enum { IOD = IOD_IMAGELOADEXAM_DIALOG }; s
#endif // AFX_DESIGN_TIME

// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnStnClickedMyPicture();
	afx_msg void OnBnClickedButton2();
	CStatic m_picture;
	afx_msg void OnStnClickedPic();
private:
	int m_x1; // x1 값는 변수 // 샘플 입력창 1 과 연결됨
	int m_y1; // y1 값는 변수 // 샘플 입력창 2 과 연결됨
	int m_x2;
	int m_y2;
public:
	afx_msg void OnBnClickedButtonGo();
private:
	int m_extend;
	int m_filter;

	int m_redgain;
	int greengain;
	int bluegain;
	int graygain;

	int m_2line_CD1;
	int m_2line_CD2;
	int m_2line_TD1;
	int m_2line_TD2;

	CString m_2lineControl;
	CString m_2lineTestArea;
	CString m_2lineRatio;

	int m_3line_CD1;
	int m_3line_CD2;
	int m_3line_T1D1;
	int m_3line_T1D2;
	int m_3line_T2D1;
	int m_3line_T2D2;

	CString m_3lineControl;
	CString m_3lineTestArea1;
	CString m_3lineTestArea2;
	CString m_3lineRatio1;
	CString m_3lineRatio2;

public:
	afx_msg void OnBnClickedButtonroad();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
private:
	int m_Xresult;
	int m_Yresult;
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
private:
	CString m_redresult;
	CString m_greenresult;
	CString m_blueresult;
	CString m_grayresult;

	double m_grayvalu[200];

	BOOL avg_check = FALSE;
	BOOL check_260 = FALSE;

public:
	afx_msg void OnBnClickedButton2linego();
	afx_msg void OnBnClickedButton3linego();
	CButton m_avg;
	afx_msg void OnBnClickedAvg();
	CButton m_260;
	afx_msg void OnBnClickedCheck260();
	afx_msg void OnBnClickedButtonCut();
private:
	CEdit redresult;
	CEdit greenresult;
	CEdit blueresult;
	CEdit grayresult;
public:
	afx_msg void OnBnClickedButtonCut2();
	afx_msg void OnBnClickedButtonCut3();
	afx_msg void OnBnClickedButtonCut4();
	afx_msg void OnBnClickedButtonClear();
	afx_msg void OnBnClickedButtonClear2();
	afx_msg void OnBnClickedButtonClear3();
	afx_msg void OnBnClickedButtonClear4();
};
