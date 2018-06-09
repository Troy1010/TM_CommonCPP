from conans import ConanFile
import xml.etree.ElementTree
import os, sys, ctypes
import VisualStudioAutomation as VS
import TM_CommonPy as TM

if __name__ == "__main__":
    try:
        #---Open
        sProj = os.path.join("TM_CommonCPP","TM_CommonCPP.vcxproj")
        #---
        TM.Run("conan create . Troy1010/channel -pr conanprofile_OBSEPlugin")
        VS.SetTMDefaultSettings(sProj)
        #VS.IntegrateProps(sProj,"conanbuildinfo.props")
    except:
        ctypes.windll.user32.MessageBoxW(0, "Exception occured.", __file__, 1)
        raise

class TM_CommonCPP_Conan(ConanFile):
    name = "TM_CommonCPP"
    version = "0.1"
    license = "MIT"
    url = "https://github.com/Troy1010/TM_CommonCPP"
    description = "TMinus1010's common C++ library."

    def source(self):
        self.run("git clone -b beta https://github.com/Troy1010/TM_CommonCPP.git")
        self.run("git clone https://github.com/SergiusTheBest/plog.git")

    def package(self):
        self.copy("*.h", dst="include", src="TM_CommonCPP/TM_CommonCPP/include")
        self.copy("*.h", dst="include", src="plog/include")

    def package_info(self):
        self.cpp_info.includedirs = ['include']
