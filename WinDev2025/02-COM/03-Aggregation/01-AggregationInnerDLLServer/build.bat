cls

del *.dll

del *.exp

del *.lib

del *.obj

cl.exe /c /EHsc AggregationInnerDLLServer.cpp


link.exe AggregationInnerDLLServer.obj user32.lib /DLL /DEF:AggregationInnerDLLServer.def /subsystem:windows


