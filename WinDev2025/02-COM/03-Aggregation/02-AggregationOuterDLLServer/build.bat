cls

del *.dll

del *.exp

del *.lib

del *.obj

cl.exe /c /EHsc AggregationOuterDLLServer.cpp


link.exe AggregationOuterDLLServer.obj user32.lib ole32.lib /DLL /DEF:AggregationOuterDLLServer.def /subsystem:windows


