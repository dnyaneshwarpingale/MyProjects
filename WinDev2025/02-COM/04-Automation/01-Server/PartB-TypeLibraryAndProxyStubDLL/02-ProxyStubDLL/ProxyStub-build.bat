cls
del *.dll
del *.exp
del *.lib
del *.obj

cl.exe /c /EHsc /D REGISTER_PROXY_DLL AutomationProxyStub.C AutomationProxyStubDLLData.C AutomationProxyStubGuids.C

link.exe AutomationProxyStub.obj AutomationProxyStubDLLData.obj AutomationProxyStubGuids.obj /DLL /DEF:AutomationServerProxyStub.def user32.lib ole32.lib oleaut32.lib advapi32.lib rpcns4.lib rpcrt4.lib /subsystem:windows
