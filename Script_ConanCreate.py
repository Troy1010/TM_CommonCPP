import os
##region Settings
sProj = os.path.join("TM_CommonCPP","TM_CommonCPP.vcxproj")
bPause = True
##endregion
##region Imports
import sys, traceback
import TM_CommonPy as TM
##endregion

try:
    TM.Run("conan create . Troy1010/channel -pr conanprofile_OBSEPlugin")
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
