#pragma once

#include <afxwin.h>

class Window : public CFrameWnd
{
    CStatic m_label;
    CButton m_button;

public:
    Window();

protected:
    afx_msg BOOL OnEraseBkgnd(CDC* deviceContext);
    afx_msg void OnButtonClicked();
    DECLARE_MESSAGE_MAP()
};