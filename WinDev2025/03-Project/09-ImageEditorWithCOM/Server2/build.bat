cls

del *.dll

del *.exp

del *.lib

del *.obj

cl.exe /c /EHsc DesaturationSepiaNegativeDLL.cpp


link.exe DesaturationSepiaNegativeDLL.obj user32.lib ole32.lib /DLL /DEF:DesaturationSepiaNegativeDLL.def /subsystem:windows



