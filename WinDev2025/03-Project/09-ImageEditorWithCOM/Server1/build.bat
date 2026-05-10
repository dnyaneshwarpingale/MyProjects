cls

del *.dll

del *.exp

del *.lib

del *.obj

cl.exe /c /EHsc NegativeDLL.cpp


link.exe NegativeDLL.obj user32.lib /DLL /DEF:NegativeDLL.def /subsystem:windows



