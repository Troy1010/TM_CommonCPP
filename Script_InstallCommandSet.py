##region Settings
bPause = True
sProj = "TM_CommonCPP/TM_CommonCPP.vcxproj"
##endregion
##region Imports
import os, sys, traceback
import TM_CommonPy as TM
import VisualStudioAutomation as VS
##endregion

def QueActions(vCommandSet):
    #---TMDefaultSettings
    vCommandSet.Que((VS.SetTMDefaultVSSettings.Do,VS.SetTMDefaultVSSettings.Undo),sProj)

##region DoubleclickEvent
try:
    vCommandSet = TM.CommandSet.TryLoad()
    QueActions(vCommandSet)
    print("Executing CommandSet..")
    vCommandSet.Execute()
    vCommandSet.Save()
except Exception as e:
    print("====================================================================")
    print("Traceback (most recent call last):")
    traceback.print_tb(e.__traceback__)
    print(e)
    os.system('pause')
    sys.exit(1)
if bPause:
    print("\n\t\t\tDone\n")
    os.system('pause')
##endregion
