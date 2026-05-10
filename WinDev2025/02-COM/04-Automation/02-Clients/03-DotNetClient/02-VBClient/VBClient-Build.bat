cls
del *.exe

vbc.exe /r:AutomationServerTypeLibForDotNet.dll /r:Microsoft.VisualBasic.dll /t:winexe VBAutomationClient.vb