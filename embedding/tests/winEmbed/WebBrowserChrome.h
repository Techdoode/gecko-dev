/* -*- Mode: IDL; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 2 -*-
 *
 * The contents of this file are subject to the Mozilla Public
 * License Version 1.1 (the "License"); you may not use this file
 * except in compliance with the License. You may obtain a copy of
 * the License at http://www.mozilla.org/MPL/
 * 
 * Software distributed under the License is distributed on an "AS
 * IS" basis, WITHOUT WARRANTY OF ANY KIND, either express or
 * implied. See the License for the specific language governing
 * rights and limitations under the License.
 * 
 * The Original Code is the Mozilla browser.
 * 
 * The Initial Developer of the Original Code is Netscape
 * Communications, Inc.  Portions created by Netscape are
 * Copyright (C) 1999, Mozilla.  All Rights Reserved.
 * 
 * Contributor(s):
 */

#ifndef __WebBrowserChrome__
#define __WebBrowserChrome__

#include "nsCOMPtr.h"
#include "nsIGenericFactory.h"
#include "nsString.h"
#include "nsIWebBrowserChrome.h"

#include "nsIDocShell.h"
#include "nsIContentViewer.h"
#include "nsIContentViewerFile.h"
#include "nsIBaseWindow.h"
#include "nsIWebNavigation.h"
#include "nsIWebProgressListener.h"
#include "nsIInterfaceRequestor.h"
#include "nsIPrompt.h"
#include "nsIWebBrowser.h"
#include "nsVoidArray.h"
#include "nsWeakReference.h"


class WebBrowserChromeUI
{
public:
    virtual nativeWindow CreateNativeWindow(nsIWebBrowserChrome* chrome) = 0;
    virtual void UpdateStatusBarText(nsIWebBrowserChrome *aChrome, const PRUnichar* aStatusText) = 0;
    virtual void UpdateCurrentURI(nsIWebBrowserChrome *aChrome) = 0;
    virtual void UpdateBusyState(nsIWebBrowserChrome *aChrome, PRBool aBusy) = 0;
    virtual void UpdateProgress(nsIWebBrowserChrome *aChrome, PRInt32 aCurrent, PRInt32 aMax) = 0;
};

#define NS_DECL_WEBBROWSERCHROMEUI \
  public: \
    virtual nativeWindow CreateNativeWindow(nsIWebBrowserChrome* chrome); \
    virtual void UpdateStatusBarText(nsIWebBrowserChrome *aChrome, const PRUnichar* aStatusText); \
    virtual void UpdateCurrentURI(nsIWebBrowserChrome *aChrome); \
    virtual void UpdateBusyState(nsIWebBrowserChrome *aChrome, PRBool aBusy); \
    virtual void UpdateProgress(nsIWebBrowserChrome *aChrome, PRInt32 aCurrent, PRInt32 aMax);

class WebBrowserChrome   : public nsIWebBrowserChrome,
                           public nsIWebProgressListener,
                           public nsIBaseWindow,
//                           public nsIPrompt,
                           public nsIInterfaceRequestor,
                           public nsSupportsWeakReference
{
public:
    WebBrowserChrome();
    virtual ~WebBrowserChrome();

    void SetUI(WebBrowserChromeUI *aUI);

    NS_DECL_ISUPPORTS
    NS_DECL_NSIWEBBROWSERCHROME
    NS_DECL_NSIWEBPROGRESSLISTENER
    NS_DECL_NSIBASEWINDOW
    //   NS_DECL_NSIPROMPT
    NS_DECL_NSIINTERFACEREQUESTOR

protected:
   
   nativeWindow mNativeWindow;
   
   WebBrowserChromeUI *mUI;
   nsCOMPtr<nsIWebBrowser> mWebBrowser;
   nsCOMPtr<nsIBaseWindow> mBaseWindow;
   nsCOMPtr<nsIWebBrowserChrome> mTopWindow;
    
   static nsVoidArray sBrowserList;
};

#endif /* __WebBrowserChrome__ */
