import VisualStudioAutomation as VS
import os

def Do(sRoot,sProj,sSln):
    with VS.DTEWrapper() as vDTEWrapper:
        with vDTEWrapper.OpenSln(sSln):
            with vDTEWrapper.OpenProj(sProj) as vProjWrapper:
                with vDTEWrapper.OpenProj(os.path.join(sRoot,"TM_CommonCPP/TM_CommonCPP/TM_CommonCPP_Lib.vcxproj")) as vProjectWrapperToReference:
                    vProjWrapper.AddProjRef(vProjectWrapperToReference.vProj)

def Undo(sRoot,sProj,sSln):
    with VS.DTEWrapper() as vDTEWrapper:
        with vDTEWrapper.OpenSln(sSln) as vSlnWrapper:
            with vDTEWrapper.OpenProj(sProj) as vProjWrapper:
                vProjWrapper.RemoveProjRef("TM_CommonCPP_Lib")
            vSlnWrapper.RemoveProj("TM_CommonCPP_Lib")
