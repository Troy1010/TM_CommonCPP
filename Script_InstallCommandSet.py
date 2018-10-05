##region Settings
bPause = True
sProj = "TM_CommonCPP/TM_CommonCPP.vcxproj"
sLogTestsProj = "TM_CommonCPP_LogTests/TM_CommonCPP_LogTests.vcxproj"
##endregion
##region Imports
import os, sys, traceback
import TM_CommonPy as TM
import VisualStudioAutomation as VS
##endregion

def QueActions(vCommandSet):
    #---TMDefaultSettings
    vCommandSet.Que((VS.SetTMDefaultVSSettings.Do,VS.SetTMDefaultVSSettings.Undo),sProj)
    vCommandSet.Que((VS.SetTMDefaultVSSettings.Do,VS.SetTMDefaultVSSettings.Undo),sLogTestsProj)

##region DoubleclickEvent
try:
    vCommandSet = TM.CommandSet.TryLoad()
    QueActions(vCommandSet)
    print("Executing CommandSet..")
    vCommandSet.Execute()
    vCommandSet.Save()
except Exception as e:
    TM.DisplayException(e)
    sys.exit(1)
if bPause:
    TM.DisplayDone()
##endregion
