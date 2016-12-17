# 基于OPENCV+Direcshow+CameraDS驱动双目摄像头
	 同时加载两个相同的摄像头时，使用普通加载单个摄像头的方法是行不通的（如果同时打开电脑摄像头和USB摄像头可以，但是如果同时打开两个相同的usb摄像头就不能）。本工程展示了同时加载两个摄像头的方法（Directshow+CCameraDs）。除了编写源码之外还需要进行如下配置：
 • 文件准备：
      驱动双目摄像头的过程中需要的文件有如下：
      (1)directshow，(2)CCameraDs， (3)quedit.h和stdafx.h 
 • 配置工程：
        1.属性->VC++目录->包含目录->编辑，将DirectShow中的Includ路径添加进去
        2.属性->VC++目录->库目录->编辑，将DirectShow中的LIB文件夹添加进去
 • 解决编译错误：
  	• 错误一： 
		  ○ 错误描述：
	    	./../../winnt.h(222) : error C2146: syntax error : missing ‘;’ before identifier ‘PVOID64’ 
		  ○ 解决方法（注意：winnt.h是一个系统文件，修改之前最好先备份一下）：
        可以改写 winnt.h 中的代码，在下面这两行： 
        typedef void *PVOID; 
        typedef void *POINTER_64 PVOID64; 
        之前增加一行： #define POINTER_64 __ptr64
    • 错误二： 
	  	○ 错误描述：
	    	error C4996: ‘fopen’: This function or variable may be unsafe. Consider using fopen_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details. 
		  ○ 解决方法： 关闭安全检查，加上#define _CRT_SECURE_NO_WARNINGS
  	• 错误三： 
	  	○ 错误描述：
		    错误 21 error LNK1120: 19 个无法解析的外部命令 F:\Work\opencv\opencv2.0\双目视觉系统\x64\Debug\双目视觉系统.exe 双目视觉系统 
        错误 15 error LNK2001: 无法解析的外部符号 CLSID_CaptureGraphBuilder2 F:\Work\opencv\opencv2.0\双目视觉系统\双目视觉系统\CameraDS.obj 双目视觉系统 
        错误 16 error LNK2001: 无法解析的外部符号 CLSID_FilterGraph F:\Work\opencv\opencv2.0\双目视觉系统\双目视觉系统\CameraDS.obj 双目视觉系统 
        错误 10 error LNK2001: 无法解析的外部符号 CLSID_NullRenderer F:\Work\opencv\opencv2.0\双目视觉系统\双目视觉系统\CameraDS.obj 
        .
        .
        .
        .
        .

        错误 20 error LNK2001: 无法解析的外部符号 LOOK_UPSTREAM_ONLY F:\Work\opencv\opencv2.0\双目视觉系统\双目视觉系统\CameraDS.obj 双目视觉系统 
        错误 14 error LNK2001: 无法解析的外部符号 MEDIASUBTYPE_RGB24 F:\Work\opencv\opencv2.0\双目视觉系统\双目视觉系统\CameraDS.obj 双目视觉系统 
        错误 13 error LNK2001: 无法解析的外部符号 MEDIATYPE_Video F:\Work\opencv\opencv2.0\双目视觉系统\双目视觉系统\CameraDS.obj 双目视觉系统 
		

       ○ 解决方法：这个问题也是困扰我最久的问题，我在这里说明一下，网上流传的基于DirectShow驱动多个摄像头的方案里提供的DirectShow的lib文件多数都是32位的，如果你的电脑是64位的无法识别DirectShow的库就会报这些错误。所以选择一个正确的lib库就能避免这些库。
       
  • 存在的问题：
	  • 摄像头的读取分辨率只能是320*240 ,调到640*480就出现栈溢出的问题。
   如果不懂可以再参考参考我的博客：http://blog.csdn.net/hx1298234467/article/details/50478176
