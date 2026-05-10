cls

del *.dll

del *.exp

del *.lib

del *.obj

cl.exe /c /EHsc ContainmentOuterDLLServer.cpp


link.exe ContainmentOuterDLLServer.obj user32.lib ole32.lib /DLL /DEF:ContainmentOuterDLLServer.def /subsystem:windows


