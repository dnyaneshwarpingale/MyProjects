cls

del *.dll

del *.exp

del *.lib

del *.obj

cl.exe /c /EHsc AutomationServer.cpp


link.exe AutomationServer.obj user32.lib ole32.lib oleaut32.lib /DLL /DEF:AutomationServer.def /subsystem:windows


