cls

del *.dll

del *.exp

del *.lib

del *.obj

cl.exe /c /EHsc ClassFactoryDllServerWithRegFile.cpp


link.exe ClassFactoryDllServerWithRegFile.obj user32.lib /DLL /DEF:ClassFactoryDllServerWithRegFile.def /subsystem:windows

