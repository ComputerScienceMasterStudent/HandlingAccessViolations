# HandlingAccessViolations
Code for handling access violations exceptions
please compile with this command line:

/JMC /permissive- /ifcOutput "Debug" /GS /analyze- /W3 /Zc:wchar_t /Gm- /Od /sdl /Fd"Debug\vc142.pdb" /Zc:inline /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_UNICODE" /D "UNICODE" /errorReport:prompt /WX- /Zc:forScope /Gd /Oy- /MDd /FC /Fa"Debug" /nologo /Fo"Debug" /Fp"Debug\ConsoleApplication1.pch" /diagnostics:column

and addition options:

/cl /W4 /clr ConsoleApplication1.cpp  /Zc:twoPhase-
