cls

del *.dll

del *.exp

del *.lib

del *.obj

cl.exe /c /EHsc ContainmentInnerDLLServer.cpp


link.exe ContainmentInnerDLLServer.obj user32.lib /DLL /DEF:ContainmentInnerDLLServer.def /subsystem:windows


